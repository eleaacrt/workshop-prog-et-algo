#include <sil/sil.hpp>
#include <iostream>

void swap(sil::Image image)
{
    for (glm::vec3 &color : image.pixels())
    {
        std::swap(color.r, color.b);
    }

    image.save("output/swap.png");
}
