#include <sil/sil.hpp>
#include <iostream>

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
