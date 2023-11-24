#include <sil/sil.hpp>
#include <iostream>
#include <math.h>
#include "../../lib/random.hpp"

void diamond_square()
{
    int height_map_size = 257;

    sil::Image diamond_square(height_map_size, height_map_size);

    diamond_square.pixel(0, 0) = {0.7f, 0.7f, 0.7f};
    diamond_square.pixel(0, diamond_square.height() - 1) = {0.4f, 0.4f, 0.4f};
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

    // ---------------------------------------------

    sil::Image diamond_square_colored{"output/diamond_square.png"};

    for (int x{0}; x < diamond_square.width(); x++)
    {
        for (int y{0}; y < diamond_square.height(); y++)
        {
            float moy = (diamond_square_colored.pixel(x, y).r + diamond_square_colored.pixel(x, y).g + diamond_square_colored.pixel(x, y).b) / 3.f;

            if (moy < 0.5)
            {
                diamond_square_colored.pixel(x, y).r = 0.f;
                diamond_square_colored.pixel(x, y).b = 0.f;
            }
            else
            {
                diamond_square_colored.pixel(x, y).r = 0.f;
                diamond_square_colored.pixel(x, y).g = 0.f;
                diamond_square_colored.pixel(x, y).b = 1 - diamond_square_colored.pixel(x, y).b;
            }
        }
    }

    diamond_square_colored.save("output/diamond_square_colored.png");
}
