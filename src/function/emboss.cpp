#include <sil/sil.hpp>
#include <iostream>

void emboss(sil::Image image)
{
    sil::Image emboss(image.width(), image.height());

    const int kernel_n{3};
    // Plutôt que de copier-coller le code qui calcule la convolution entre les différents effets, vous auriez pu faire une fonction `convolution` une fois pour toute, qui prend un kernel en paramètre.
    float kernel[][kernel_n] = {
        {-2, -1, 0},
        {-1, 1, 1},
        {0, 1, 2},
    };

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            float count{0.f};
            glm::vec3 sum{0.f, 0.f, 0.f};

            for (int i{0}; i < kernel_n; i++)
            {
                for (int j{0}; j < kernel_n; j++)
                {
                    if ((x + i) >= image.width() || (x + i) <= 0 || (y + j) >= image.height() || (y + j) <= 0)
                    {
                    }
                    else
                    {
                        sum += image.pixel((x + i), (y + j)) * kernel[i][j];
                    }
                }
            }
            emboss.pixel(x, y) = sum;
        }
    }

    emboss.save("output/emboss.png");
}