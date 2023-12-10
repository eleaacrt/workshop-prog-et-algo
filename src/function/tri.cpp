#include <sil/sil.hpp>
#include <iostream>
#include "../../lib/random.hpp"
#include <algorithm>

float brightness(glm::vec3 color)
{
    return ((color[0] + color[1] + color[2]) / 3);
}

void tri(sil::Image image)
{
    sil::Image tri(image.width(), image.height());
    sil::Image rect(50, 1);

    int nb_rectangles{500};

    while (nb_rectangles > 0)
    {
        std::vector<glm::vec3> pixels{};
        int imageXrect{random_int(0, (image.width() - rect.width()))};
        int imageYrect{random_int(0, (image.height() - rect.height()))};

        for (int x{0}; x < rect.width(); x++)
        {
            for (int y{0}; y < rect.height(); y++)
            {
                rect.pixel(x, y) = image.pixel((x + imageXrect), (y + imageYrect));
            }
        }

        for (int x{0}; x < rect.width(); x++)
        {
            for (int y{0}; y < rect.height(); y++)
            {
                pixels.push_back(rect.pixel(x, y));
            }
        }
        std::sort(pixels.begin(), pixels.end(), [](glm::vec3 const &color1, glm::vec3 const &color2)
                    {
                        return brightness(color1) < brightness(color2); // Trie selon la luminosité des couleurs (NB : c'est à vous de coder la fonction `brightness`)
                    });

        int i{0};
        for (int x{0}; x < rect.width(); x++)
        {
            for (int y{0}; y < rect.height(); y++)
            {
                rect.pixel(x, y) = pixels[i]; // Bug: le tableau pixels contient rect.width() * rect.height() éléments, mais vous ne lisez que les rect.width() premiers, et ignorez tous les autres. Dans le cas où height > 1 il faudrait adapter le code pour qu'il marche bien. Par exemple avec le compteur i que j'ai rajouté.
                i++;
            }
        }
        // Ou version + opti :
        for (int x{0}; x < rect.width(); x++)
        {
            for (int y{0}; y < rect.height(); y++)
            {
                rect.pixel(x, y) = pixels[y + x * image.height()];
            }
        }

        for (int x{0}; x < rect.width(); x++)
        {
            for (int y{0}; y < rect.height(); y++)
            {
                image.pixel((x + imageXrect), (y + imageYrect)) = rect.pixel(x, y);
            }
        }

        nb_rectangles--;
    }

    image.save("output/tri.png");
}