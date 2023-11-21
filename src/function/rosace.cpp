#include <sil/sil.hpp>
#include <iostream>
#include <math.h>

void rosace()
{
    // création des images
    sil::Image rosace{500 /*width*/, 500 /*height*/};

    int r{100};
    int thinkeness{5};
    int r_dessin { r - thinkeness / 2 };

    for (int x{0}; x < rosace.width(); x++)
    {
        for (int y{0}; y < rosace.height(); y++)
        {

            if (pow((x - (rosace.width() / 2)), 2) + pow((y - (rosace.height() / 2)), 2) <= (r * r) and
                pow((x - (rosace.width() / 2)), 2) + pow((y - (rosace.height() / 2)), 2) >= ((r_dessin - thinkeness) * (r_dessin - thinkeness)))
            {
                rosace.pixel(x, y).r = 1.f;
                rosace.pixel(x, y).g = 1.f;
                rosace.pixel(x, y).b = 1.f;
            }

            for (int i{0}; i <= 5; i++)
            {
                if (
                    pow((x - ((rosace.width() / 2) + (r * cos((i * M_PI) / 3)))), 2) +
                            pow((y - ((rosace.width() / 2) + (r * sin((i * M_PI) / 3)))), 2) <=
                        (r * r) and
                    pow((x - ((rosace.width() / 2) + (r * cos((i * M_PI) / 3)))), 2) +
                            pow((y - ((rosace.width() / 2) + (r * sin((i * M_PI) / 3)))), 2) >=
                        ((r_dessin - thinkeness) * (r_dessin - thinkeness)))
                {
                    rosace.pixel(x, y).r = 1.f;
                    rosace.pixel(x, y).g = 1.f;
                    rosace.pixel(x, y).b = 1.f;
                }
            }
        }
    }

    rosace.save("output/rosace.png");
}
