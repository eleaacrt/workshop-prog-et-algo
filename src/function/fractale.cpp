#include <sil/sil.hpp>
#include <iostream>
#include <complex>
#include "../../lib/random.hpp"

void fractale()
{
    // creation de l'image
    sil::Image fractale{500 /*width*/, 500 /*height*/};

    for (float x{0.f}; x < fractale.width(); x++)
    {
        for (float y{0.f}; y < fractale.height(); y++)
        {

            float count{0};

            float x1{x / 200 - 2};
            float y1{y / 200 - 1.25f};

            std::complex<float> c{x1, y1};
            std::complex<float> z{0.f, 0.f};

            while (count < 50)
            {
                z = z * z + c;

                if (std::abs(z) > 2)
                {
                    break;
                }

                count++;
            }

            fractale.pixel(x, y).r = 0.f + count / 50;
            fractale.pixel(x, y).g = 0.f + count / 50;
            fractale.pixel(x, y).b = 0.f + count / 50;
        }
    }

    fractale.save("output/fractale.png");
}