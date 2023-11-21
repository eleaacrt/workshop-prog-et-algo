#include <sil/sil.hpp>
#include <iostream>
#include "../../lib/random.hpp"

void bruit(sil::Image image)
{

    int nb_pixels{15000};

    while (nb_pixels != 0)
    {
        image.pixel(random_int(0, image.width()), random_int(0, image.height())).r = random_float(0, 1);
        image.pixel(random_int(0, image.width()), random_int(0, image.height())).g = random_float(0, 1);
        image.pixel(random_int(0, image.width()), random_int(0, image.height())).b = random_float(0, 1);
        nb_pixels -= 1;
    }

    image.save("output/bruit.png");
}