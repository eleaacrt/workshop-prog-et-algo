#include <sil/sil.hpp>
#include <iostream>
#include <math.h>
#include "../../lib/random.hpp"

void diamond_square_patoutafait()
{
    int height_map_size{257};
    // int height_map_size{257};

    sil::Image diamond_square{height_map_size /*width*/, height_map_size /*height*/};

    diamond_square.pixel(0, 0) = {random_float(0.f, 1.f), random_float(0.f, 1.f), random_float(0.f, 1.f)};
    diamond_square.pixel(0, diamond_square.height() - 1) = {random_float(0.f, 1.f), random_float(0.f, 1.f), random_float(0.f, 1.f)};
    diamond_square.pixel(diamond_square.width() - 1, 0) = {random_float(0.f, 1.f), random_float(0.f, 1.f), random_float(0.f, 1.f)};
    diamond_square.pixel(diamond_square.width() - 1, diamond_square.height() - 1) = {random_float(0.f, 1.f), random_float(0.f, 1.f), random_float(0.f, 1.f)};

    int chunk_size{diamond_square.height() - 1};

    float roughness{0.5};

    while (chunk_size > 1)
    {
        int half = chunk_size / 2;

        // square step
        for (int x{0}; x < height_map_size - 1; x += chunk_size)
        {
            for (int y{0}; y < height_map_size - 1; y += chunk_size)
            {
                diamond_square.pixel(x + half, y + half) =
                    (diamond_square.pixel(x, y) + diamond_square.pixel(x + chunk_size, y) + diamond_square.pixel(x, y + chunk_size) + diamond_square.pixel(x + chunk_size, y + chunk_size)) / 4.f + random_float(-roughness, roughness);
            }
        }

        for (int x{0}; x < height_map_size; x += half)
        {
            for (int y{(x + half) % chunk_size}; y < height_map_size; y += chunk_size)
            {
                float count{0.f};
                if (x - half >= 0)
                {
                    diamond_square.pixel(x, y) += diamond_square.pixel(x - half, y);
                    count++;
                }
                if (y - half >= 0)
                {
                    diamond_square.pixel(x, y) += diamond_square.pixel(x, y - half);
                    count++;
                }
                if (x + half < 0)
                {
                    diamond_square.pixel(x, y) += diamond_square.pixel(x + half, y);
                    count++;
                }
                if (y + half < 0)
                {
                    diamond_square.pixel(x, y) += diamond_square.pixel(x, y + half);
                    count++;
                }
                diamond_square.pixel(x, y) = diamond_square.pixel(x, y) / count + random_float(-roughness, roughness);
            }
        }

        chunk_size /= 2;
        roughness /= 2;
    }

    diamond_square.save("output/diamond_square_patoutafait.png");
}
