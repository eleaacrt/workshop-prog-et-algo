#include <sil/sil.hpp>
#include <iostream>
#include <math.h>

void normalisation(sil::Image image)
{
    // création des images
    sil::Image normalisation{image.width() /*width*/, image.height() /*height*/};

    float min{0.5f}; // Pourquoi init le min à 0.5 ? Pourquoi pas 1 ? Voir FLT_MAX (le plus grand nombre possible) ? Si tous les pixels ont une luminosité entre 0.6 et 1, votre code est bugué.
    float max{0.5f}; // Idem, vous pourriez l'init à -FLT_MAX (ou 0 ça marche bien aussi dans ce cas particulier où on sait que la luminosité sera toujours >= 0)

    for (int y = 0; y < normalisation.height(); y++)
    {
        for (int x = 0; x < normalisation.width(); x++)
        {
            float pixel_color{(image.pixel(x, y).r + image.pixel(x, y).g + image.pixel(x, y).b) / 3};
            if (pixel_color < min)
            {
                min = pixel_color;
            }
            else if (pixel_color > max)
            {
                max = pixel_color;
            }
        }
    }

    for (int y = 0; y < normalisation.height(); y++)
    {
        for (int x = 0; x < normalisation.width(); x++)
        {
            float pixel_color{(image.pixel(x, y).r + image.pixel(x, y).g + image.pixel(x, y).b) / 3};
            float moy{((1 - min) + max) / 2};
            
            float dist{};
            if (pixel_color > moy)
            {
                dist = pixel_color - moy;
            }
            else if (pixel_color < moy)
            {
                dist = moy - pixel_color;
            }
            else
            {
                dist = 0;
            }

            if (pixel_color < moy)
            {
                normalisation.pixel(x, y).r = (image.pixel(x, y).r) - (min * dist);
                normalisation.pixel(x, y).g = (image.pixel(x, y).g) - (min * dist);
                normalisation.pixel(x, y).b = (image.pixel(x, y).b) - (min * dist);
            }
            else
            {
                normalisation.pixel(x, y).r = (image.pixel(x, y).r) + ((1 - max) * dist);
                normalisation.pixel(x, y).g = (image.pixel(x, y).g) + ((1 - max) * dist);
                normalisation.pixel(x, y).b = (image.pixel(x, y).b) + ((1 - max) * dist);
            }
        }
    }

    std::cout << min << " ; " << max << std::endl; // Pensez à enlever votre code de debug au moment de rendre le projet (voire au moment de faire votre commit, une fois que le code est débugué)
    normalisation.save("output/normalisation.png");
}
