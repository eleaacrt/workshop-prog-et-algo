#include <sil/sil.hpp>
#include <iostream>

void split(sil::Image image)
{

    sil::Image image2{image.width() /*width*/, image.height() /*height*/};

    int decalage{30};
    for (int x{0}; x < (image.width()); x++)
    {
        for (int y{0}; y < (image.height()); y++)
        {
            if (x <= decalage)
            {
                image2.pixel(x, y).r = image.pixel(x, y).r;
                image2.pixel(x, y).g = image.pixel(x, y).g;
                image2.pixel(x, y).b = image.pixel(x + decalage, y).b;
            }
            else if ((x + decalage) >= image.width())
            {
                image2.pixel(x, y).r = image.pixel(x - decalage, y).r;
                image2.pixel(x, y).g = image.pixel(x, y).g;
                image2.pixel(x, y).b = image.pixel(x, y).b;
            }
            else
            {
                image2.pixel(x, y).r = image.pixel(x - decalage, y).r;
                image2.pixel(x, y).g = image.pixel(x, y).g;
                image2.pixel(x, y).b = image.pixel(x + decalage, y).b;
            }
        }
    }

    image2.save("output/split.png");
}
