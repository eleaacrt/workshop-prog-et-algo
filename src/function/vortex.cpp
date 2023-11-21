#include <sil/sil.hpp>
#include <iostream>
#include "../../lib/random.hpp"
#include <glm/gtx/matrix_transform_2d.hpp>

glm::vec2 rotated(glm::vec2 v, float angle)
{
    return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{v, 1.f}};
}

void vortex(sil::Image image)
{
    sil::Image vortex(image.width(), image.height());
    glm::vec2 center(image.width() / 2, image.height() / 2);
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            glm::vec2 position{x, y};
            float distance{glm::distance(position, center)};
            glm::vec2 pos_finale(rotated(position - center, distance / 10) + center);
            if (pos_finale.x >= image.width() || pos_finale.x < 0 || pos_finale.y >= image.height() || pos_finale.y < 0)
            {
            }
            else
            {
                vortex.pixel(x, y) = image.pixel(pos_finale.x, pos_finale.y);
            }
        }
    }

    vortex.save("output/vortex.png");
}