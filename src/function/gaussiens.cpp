#include <sil/sil.hpp>
#include <iostream>

// Petit point terminologie : ceci n'est pas un gaussian blur, mais un box blur. Le gaussian blur a des coefficients qui dépendent d'une exponentielle décroissante (cf wikipedia)
// Ceci dit un box blur marchait très bien aussi pour l'exo, c'est juste que c'est trompeur de l'appeler gaussien alors que ce n'est pas un gaussien ^^
void gaussiens(sil::Image image)
{
    sil::Image gaussien_leger(image.width(), image.height());
    sil::Image gaussien_hard(image.width(), image.height());

    int kernel{2};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            float count{0.f};
            glm::vec3 sum{0.f, 0.f, 0.f};

            for (int i{-kernel}; i <= kernel; i++)
            {
                for (int j{-kernel}; j <= kernel; j++)
                {
                    if ((x + i) >= image.width() || (x + i) <= 0 || (y + j) >= image.height() || (y + j) <= 0.5)
                    {
                        count += 1;
                    }
                    else
                    {
                        sum += image.pixel((x + i), (y + j));
                        count += 1;
                    }
                }
            }
            glm::vec3 moy{sum / count};
            gaussien_leger.pixel(x, y) = moy;
        }
    }

    kernel = 10;

    // Plutôt que de refaire le même code qu'au dessus, vous auriez pu mettre le code dans une fonction que vous auriez appelée deux fois, en lui passant un paramètre kernel différent à chaque fois.
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            float count{0.f};
            glm::vec3 sum{0.f, 0.f, 0.f};

            for (int i{-kernel}; i <= kernel; i++)
            {
                for (int j{-kernel}; j <= kernel; j++)
                {
                    if ((x + i) >= image.width() || (x + i) <= 0 || (y + j) >= image.height() || (y + j) <= 0)
                    {
                        count += 1;
                    }
                    else
                    {
                        sum += image.pixel((x + i), (y + j));
                        count += 1;
                    }
                }
            }
            glm::vec3 moy{sum / count};
            gaussien_hard.pixel(x, y) = moy;
        }
    }

    gaussien_leger.save("output/gaussien_leger.png");
    gaussien_hard.save("output/gaussien_hard.png");
}
