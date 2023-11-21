// #include <sil/sil.hpp>
// #include <iostream>
// #include "../../lib/random.hpp"
// #include <glm/gtx/matrix_transform_2d.hpp>

// glm::vec2 rotated(glm::vec2 v, float angle)
// {
//     return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{v, 1.f}};
// }

// void vortexN(sil::Image image)
// {
//     sil::Image vortex{image.width(), image.height()};
//     for (int x{0}; x < image.width(); x++)
//     {
//         for (int y{0}; y < image.height(); y++)
//         {
//             glm::vec2 position{x, y};
//             glm::vec2 center_of_rotation{image.width() / 2, image.height() / 2};
//             glm::vec2 final_position { rotated(position - center_of_rotation, 0.5) };
//             if (center_of_rotation.x + final_position.x > image.width() or center_of_rotation.x + final_position.x < 0 or center_of_rotation.y + final_position.y > image.height() or center_of_rotation.y + final_position.y < 0)
//             {
//                 image.pixel(x,y).r = 0.f;
//                 image.pixel(x,y).g = 0.f;
//                 image.pixel(x,y).b = 0.f;
//             }
//             else
//             {
//                 image.pixel(x,y) = image.pixel(center_of_rotation.x + final_position.x, center_of_rotation.y + final_position.y);
//             }
//         }
//     }

//     image.save("output/vortexN.png");
// }