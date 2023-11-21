#include <sil/sil.hpp>
#include <iostream>

void negatif(sil::Image image)
{
    for (glm::vec3 &color : image.pixels())
    {
        color.r = 1 - color.r;
        color.b = 1 - color.b;
        color.g = 1 - color.g;
    }

    image.save("output/negatif.png");
}