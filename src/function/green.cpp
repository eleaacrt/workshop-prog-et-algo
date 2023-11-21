#include <sil/sil.hpp>
#include <iostream>

void green(sil::Image image)
{
    for (glm::vec3 &color : image.pixels())
    {
        color.b = 0.f;
        color.r = 0.f;
    }

    image.save("output/green.png");
}