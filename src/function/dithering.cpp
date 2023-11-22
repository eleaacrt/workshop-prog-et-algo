#include <sil/sil.hpp>
#include <iostream>
#include <math.h>

void dithering(sil::Image image)
{
    // création des images
    sil::Image dithering{image.width() /*width*/, image.height() /*height*/};

    const int bayer_n = 4;
    float bayer_matrix_4x4[][bayer_n] = {
        {-0.5, 0, -0.375, 0.125},
        {0.25, -0.25, 0.375, -0.125},
        {-0.3125, 0.1875, -0.4375, 0.0625},
        {0.4375, -0.0625, 0.3125, -0.1875},
    };

    for (int sy = 0; sy < dithering.height(); sy++)
    {
        for (int sx = 0; sx < dithering.width(); sx++)
        {
            dithering.pixel(sx, sy) = image.pixel(sx, sy);
        }
    }

    for (int sy = 0; sy < dithering.height(); sy++)
    {
        for (int sx = 0; sx < dithering.width(); sx++)
        {
            int color_result = 0;
            float bayer_value = bayer_matrix_4x4[sy % bayer_n][sx % bayer_n];
            float output_color = ((dithering.pixel(sx, sy).r + dithering.pixel(sx, sy).g + dithering.pixel(sx, sy).b) / 3) + (bayer_value);
            // Color screen blue to white
            if (output_color < (((dithering.pixel(sx, sy).r + (dithering.pixel(sx, sy).g + (dithering.pixel(sx, sy).b)) / 3) / 2)))
            {
                color_result = 1;
            }
            dithering.pixel(sx, sy).r = color_result;
            dithering.pixel(sx, sy).g = color_result;
            dithering.pixel(sx, sy).b = color_result;
        }
    }
    dithering.save("output/dithering.png");
}
