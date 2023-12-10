#include <sil/sil.hpp>
#include <iostream>
#include <math.h>
#include "../../lib/random.hpp"

void diamond_square()
{
    int height_map_size = 1025;

    sil::Image diamond_square(height_map_size, height_map_size);

    // Si vous vouliez avoir la même valeur random dans les trois canaux de la couleur, il fallait faire une variable pour stocker le random, puis passer cette variable trois fois à la couleur:
    float const grey{random_float(0.f, 1.f)};
    diamond_square.pixel(0, 0) = {grey, grey, grey};
    // ou alors, utiliser la syntaxe glm qui permet de construire une couleur à partir d'un seul nombre, et qui met ce nombre dans les trois canaux:
    diamond_square.pixel(0, diamond_square.height() - 1) = {random_float(0.f, 1.f)};
    diamond_square.pixel(diamond_square.width() - 1, 0) = {0.2f, 0.2f, 0.2f};
    diamond_square.pixel(diamond_square.width() - 1, diamond_square.height() - 1) = {0.1f, 0.1f, 0.1f};

    int chunk_size = height_map_size - 1;
    float roughness = 0.5;

    while (chunk_size > 1)
    {
        int half = chunk_size / 2;

        // Square step
        for (int x = 0; x < height_map_size - 1; x += chunk_size)
        {
            for (int y = 0; y < height_map_size - 1; y += chunk_size)
            {
                diamond_square.pixel(x + half, y + half) =
                    (diamond_square.pixel(x, y) +
                     diamond_square.pixel(x + chunk_size, y) +
                     diamond_square.pixel(x, y + chunk_size) +
                     diamond_square.pixel(x + chunk_size, y + chunk_size)) /
                        4.f +
                    random_float(-roughness, roughness);
            }
        }

        // Diamond step
        for (int x = 0; x < height_map_size; x += half)
        {
            for (int y = (x + half) % chunk_size; y < height_map_size; y += chunk_size)
            {
                float count = 0.f;
                glm::vec3 temp_pixel = {};

                if (x - half >= 0)
                {
                    temp_pixel += diamond_square.pixel(x - half, y);
                    count++;
                }
                if (y - half >= 0)
                {
                    temp_pixel += diamond_square.pixel(x, y - half);
                    count++;
                }
                if (x + half < height_map_size)
                {
                    temp_pixel += diamond_square.pixel(x + half, y);
                    count++;
                }
                if (y + half < height_map_size)
                {
                    temp_pixel += diamond_square.pixel(x, y + half);
                    count++;
                }

                diamond_square.pixel(x, y) = temp_pixel / count + random_float(-roughness, roughness);
            }
        }

        chunk_size /= 2;
        roughness /= 2;
    }

    diamond_square.save("output/diamond_square.png");

    // -------- colorisation de la map -------------------------------------

    sil::Image diamond_square_colored{"output/diamond_square.png"};

    for (int x{0}; x < diamond_square.width(); x++)
    {
        for (int y{0}; y < diamond_square.height(); y++)
        {
            float moy = (diamond_square_colored.pixel(x, y).r + diamond_square_colored.pixel(x, y).g + diamond_square_colored.pixel(x, y).b) / 3.f;

            if (moy > 0.75f)
            {
                // Nuances de noir arrondies au centième
                float intensity = 1.0 - (moy - 0.75) * 4.f;
                diamond_square_colored.pixel(x, y).r = std::floor(intensity * 10.0) / 10.0;
                diamond_square_colored.pixel(x, y).g = std::floor(intensity * 10.0) / 10.0;
                diamond_square_colored.pixel(x, y).b = std::floor(intensity * 10.0) / 10.0;
            }
            else if (moy > 0.5f && moy <= 0.75f)
            {
                // Nuances de brun arrondies au centième
                float intensity = (moy - 0.5) * 4.f;
                diamond_square_colored.pixel(x, y).r = std::floor((0.7 * intensity) * 10.0) / 10.0;
                diamond_square_colored.pixel(x, y).g = std::floor((0.4 * intensity) * 10.0) / 10.0;
                diamond_square_colored.pixel(x, y).b = std::floor((0.2 * intensity) * 10.0) / 10.0;
            }
            else if (moy > 0.25f && moy <= 0.5f)
            {
                // Nuances de vert arrondies au centième
                float intensity = (moy - 0.25) * 4.f;
                diamond_square_colored.pixel(x, y) = {0.0, 1.0 * intensity, 0.0};
                diamond_square_colored.pixel(x, y).r = 0.f;
                diamond_square_colored.pixel(x, y).g = std::floor((1.0 * intensity) * 10.0) / 10.0;
                diamond_square_colored.pixel(x, y).b = 0.f;
            }
            else
            {
                // Nuances de bleu arrondies au centième
                float intensity = moy * 4.f;
                diamond_square_colored.pixel(x, y) = {0.0, 1.0 * intensity, 0.0};
                diamond_square_colored.pixel(x, y).r = 0.f;
                diamond_square_colored.pixel(x, y).g = 0.f;
                diamond_square_colored.pixel(x, y).b = std::floor((1.0 * intensity) * 10.0) / 10.0;
            }
        }
    }

    diamond_square_colored.save("output/diamond_square_colored.png");
}
