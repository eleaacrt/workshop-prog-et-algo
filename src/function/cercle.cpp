#include <sil/sil.hpp>
#include <iostream>
#include <math.h>

void cercle()
{
    // création des images
    sil::Image cercle{500 /*width*/, 500 /*height*/};

    int r{100};
    int thinkeness{5};

    for (int x{0}; x < cercle.width(); x++)
    {
        for (int y{0}; y < cercle.height(); y++)
        {
            if (pow((x - (cercle.width() / 2)), 2) + pow((y - (cercle.height() / 2)), 2) <= (r * r) and 
            pow((x - (cercle.width() / 2)), 2) + pow((y - (cercle.height() / 2)), 2) >= ((r - thinkeness) * (r - thinkeness))
            )
            {
                cercle.pixel(x, y).r = 0.45f;
                cercle.pixel(x, y).g = 0.24f;
                cercle.pixel(x, y).b = 0.67f;
            }
        }
    }

    cercle.save("output/cercle.png");
}
