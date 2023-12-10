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
            // Vous calculez deux fois `pow((x - (cercle.width() / 2)), 2) + pow((y - (cercle.height() / 2)), 2)`
            // Vous auriez pu le mettre dans une variable pour le réutiliser :
            auto const distance_squared{ pow((x - (cercle.width() / 2)), 2) + pow((y - (cercle.height() / 2)), 2) };
            if (distance_squared <= (r * r) and 
            distance_squared >= ((r - thinkeness) * (r - thinkeness))
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
