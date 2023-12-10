#include <sil/sil.hpp>
#include <iostream>

void mosaique(sil::Image image)
{
    int nb_patern{5}; // C'est très bien de faire une variable pour stocker ce paramètre, mais vous ne l'utilisez pas ^^

    sil::Image mosaique{image.width() * nb_patern /*width*/, image.height() * nb_patern /*height*/};


    for (int x{0}; x < mosaique.width(); x++)
    {
        for (int y{0}; y < mosaique.height(); y++)
        {
            mosaique.pixel(x, y) = image.pixel(x % image.width(), y % image.height());
        }
    }

    mosaique.save("output/mosaique.png");
}
