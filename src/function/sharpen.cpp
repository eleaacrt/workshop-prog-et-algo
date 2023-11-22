#include <sil/sil.hpp>
#include <iostream>

void sharpen(sil::Image image)
{
    sil::Image sharpen(image.width(), image.height());

    const int kernel_n{3};
    float kernel[][kernel_n] = {
        {0, -1, 0},
        {-1, 5, -1},
        {0, -1, 0},
    };

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            float count{0.f};
            glm::vec3 sum{0.f, 0.f, 0.f};

            for (int i{0}; i < kernel_n; i++)
            {
                for (int j{0}; j < kernel_n; j++)
                {
                    if ((x + i) >= image.width() || (x + i) <= 0 || (y + j) >= image.height() || (y + j) <= 0)
                    {
                    }
                    else
                    {
                        sum += image.pixel((x + i), (y + j)) * kernel[i][j];
                    }
                }
            }
            sharpen.pixel(x, y) = sum;
        }
    }

    sharpen.save("output/sharpen.png");
}