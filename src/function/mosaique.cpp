#include <sil/sil.hpp>
#include <iostream>

void mosaique(sil::Image image)
{

    sil::Image mosaique{image.width() * 5 /*width*/, image.height() * 5 /*height*/};

    int nb_patern{5};

    for (int x{0}; x < mosaique.width(); x++)
    {
        for (int y{0}; y < mosaique.height(); y++)
        {
            mosaique.pixel(x, y) = image.pixel(x % image.width(), y % image.height());
        }
    }

    mosaique.save("output/mosaique.png");
}
