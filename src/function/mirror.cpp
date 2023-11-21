#include <sil/sil.hpp>
#include <iostream>

void mirror(sil::Image image)
{
    float red_bin{};
    float green_bin{};
    float blue_bin{};

    for (float x{0.f}; x < (image.width() / 2.f); x++)
    {
        for (float y{0.f}; y < image.height(); y++)
        {
            red_bin = image.pixel(x, y).r;
            green_bin = image.pixel(x, y).g;
            blue_bin = image.pixel(x, y).b;

            image.pixel(x, y).r = image.pixel((image.width() - 1 - x), y).r;
            image.pixel(x, y).g = image.pixel((image.width() - 1 - x), y).g;
            image.pixel(x, y).b = image.pixel((image.width() - 1 - x), y).b;

            image.pixel((image.width() - 1 - x), y).r = red_bin;
            image.pixel((image.width() - 1 - x), y).g = green_bin;
            image.pixel((image.width() - 1 - x), y).b = blue_bin;
        }
    }

    image.save("output/mirror.png");
}
