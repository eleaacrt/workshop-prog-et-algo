#include <sil/sil.hpp>
#include <iostream>

void gradient()
{
    // création de notre rectan
    sil::Image image{300 /*width*/, 200 /*height*/};
    // On passe sur tous les x et tous les y, et on accède au pixel correspondant :
    for (float x{0.f}; x < image.width(); x++)
    {
        for (float y{0.f}; y < image.height(); y++)
        {
            image.pixel(x, y).r = (0.f + (x / image.width()));
            image.pixel(x, y).g = (0.f + (x / image.width()));
            image.pixel(x, y).b = (0.f + (x / image.width()));
        }
    }

    image.save("output/gradient.png");
}
