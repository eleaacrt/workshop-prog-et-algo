#include <sil/sil.hpp>
#include <iostream>
#include <math.h>

void disque()
{
    // création des images
    sil::Image disque{500 /*width*/, 500 /*height*/};

    int r{150};

    for (int x{0}; x < disque.width(); x++)
    {
        for (int y{0}; y < disque.height(); y++)
        {
            if (pow((x - (disque.width() / 2)), 2) + pow((y - (disque.height() / 2)), 2) <= (r * r))
            {
                disque.pixel(x, y).r = 0.45f;
                disque.pixel(x, y).g = 0.24f;
                disque.pixel(x, y).b = 0.67f;
            }
        }
    }

    disque.save("output/disque.png");
}
