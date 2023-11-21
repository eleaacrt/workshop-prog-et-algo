#include <sil/sil.hpp>
#include <iostream>
#include "../../lib/random.hpp"

void glitch(sil::Image image)
{
    int rectangles{20};

    while (rectangles != 0)
    {

        sil::Image rect{random_int(3, 50) /*width*/, random_int(2, 15) /*height*/};
        sil::Image rect2{rect.width() /*width*/, rect.height() /*height*/};

        int imageXrect1{random_int(0, (image.width() - rect.width()))};
        int imageYrect1{random_int(0, (image.height() - rect.height()))};

        int imageXrect2{random_int(0, (image.width() - rect.width()))};
        int imageYrect2{random_int(0, (image.height() - rect.height()))};

        for (int x{0}; x < rect.width(); x++)
        {
            for (int y{0}; y < rect.height(); y++)
            {
                rect.pixel(x, y) = image.pixel((x + imageXrect1), (y + imageYrect1));
                rect2.pixel(x, y) = image.pixel((x + imageXrect2), (y + imageYrect2));

                image.pixel((x + imageXrect2), (y + imageYrect2)) = rect.pixel(x, y);
                image.pixel((x + imageXrect1), (y + imageYrect1)) = rect2.pixel(x, y);
            }
        }
        rectangles -= 1;
    }

    image.save("output/glitch.png");
}