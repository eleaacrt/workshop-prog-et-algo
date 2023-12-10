#include <sil/sil.hpp>
#include <iostream>

// Passer par const& vous évite de copier les images (et une image c'est gros donc on n'a pas envie de la copier)
void diff_gaussien(sil::Image const& gaussien_leger, sil::Image const& gaussien_hard)
{
    sil::Image final(gaussien_leger.width(), gaussien_leger.height());

    for (int x{0}; x < gaussien_leger.width(); x++)
    {
        for (int y{0}; y < gaussien_leger.height(); y++)
        {
            glm::vec3 pixel(final.pixel(x, y));
            float tau{10};
            final.pixel(x, y) = (1 + tau) * gaussien_leger.pixel(x, y) - tau * gaussien_hard.pixel(x, y);

            if (((final.pixel(x, y).r + final.pixel(x, y).g + final.pixel(x, y).b) / 3) >= 0.5f)
            {
                final.pixel(x, y).r = 1.f;
                final.pixel(x, y).g = 1.f;
                final.pixel(x, y).b = 1.f;
            } else {
                final.pixel(x, y).r = 0.f;
                final.pixel(x, y).g = 0.f;
                final.pixel(x, y).b = 0.f;
            }
        }
    }
    final.save("output/gaussien.png");
}