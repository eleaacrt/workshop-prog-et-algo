#include <sil/sil.hpp>
#include <iostream>

void rotate(sil::Image image)
{

    sil::Image image2{image.height() /*width*/, image.width() /*height*/};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image2.pixel((image.height() - 1 - y), x).r = image.pixel(x, y).r;
            image2.pixel((image.height() - 1 - y), x).g = image.pixel(x, y).g;
            image2.pixel((image.height() - 1 - y), x).b = image.pixel(x, y).b;
        }
    }

    image2.save("output/rotate.png");
}
