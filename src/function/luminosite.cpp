#include <sil/sil.hpp>
#include <iostream>
#include <math.h>

void luminosite(sil::Image image)
{
    // création des images
    sil::Image basse{image.width() /*width*/, image.height() /*height*/};
    sil::Image haute{image.width() /*width*/, image.height() /*height*/};

    for (float x{0.f}; x < image.width(); x++)
    {
        for (float y{0.f}; y < image.height(); y++)
        {
            basse.pixel(x, y).r = pow((image.pixel(x, y).r), 2);
            basse.pixel(x, y).g = pow((image.pixel(x, y).g), 2);
            basse.pixel(x, y).b = pow((image.pixel(x, y).b), 2);

            haute.pixel(x, y).r = pow((image.pixel(x, y).r), 0.5);
            haute.pixel(x, y).g = pow((image.pixel(x, y).g), 0.5);
            haute.pixel(x, y).b = pow((image.pixel(x, y).b), 0.5);
        }
    }

    basse.save("output/lum_basse.png");
    haute.save("output/lum_haute.png");
}
