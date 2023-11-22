#include <sil/sil.hpp>
#include <iostream>

void convolution(sil::Image image)
{
    sil::Image convolution(image.width(), image.height());

    int kernel{15};

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
            convolution.pixel(x, y) = moy;
        }
    }

    convolution.save("output/convolution.png");
}