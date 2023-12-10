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
            // Autre manière + simple d'écrire le code, où on ne met dans le if que ce qui a besoin d'y être:
            image2.pixel(x, y).g = image.pixel(x, y).g; // Le g est toujours bon
            if (x <= decalage) // Pour le b on check si on fait le décalage ou pas
            {
                image2.pixel(x, y).b = image.pixel(x + decalage, y).b;
            }
            else
            {
                image2.pixel(x, y).b = image.pixel(x, y).b;
            }
            if ((x + decalage) >= image.width())// Pour le r on check si on fait le décalage ou pas
            {
                image2.pixel(x, y).r = image.pixel(x - decalage, y).r;
            }
            else
            {
                image2.pixel(x, y).r = image.pixel(x, y).r;
            }
        }
    }

    image2.save("output/split.png");
}
