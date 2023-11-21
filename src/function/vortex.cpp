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
    // je créer une nouvelle image qui va accueillir les pixels du vortex
    // si on crée pas cette image, on retrouve le même problème que lors du miroir
    // (c'était une erreur que j'ai eu dans mon code à la base)
    sil::Image vortex(image.width(), image.height());

    // je définis le centre de l'image
    glm::vec2 center(image.width() / 2, image.height() / 2);


    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {

            // je définis la position du pixel avec le x et le y
            glm::vec2 position{x, y};

            // je calcule la distance entre le centre et le pixel de position (x,y) que je souhaite bouger
            float distance{glm::distance(position, center)};

            // je calcule la position finale du pixel avec la fonction de rotation
            // comme v je mets le vecteur position - center et l'angle, je choisi la distance / 10 (sinon c'est beaucoup trop grand et ça devient illisible)
            // il faut ajouter centre sinon il n'est pas placé correctement (tu peux tester il manque des couleurs ^^)
            glm::vec2 pos_finale(rotated(position - center, distance / 10) + center);

            // si les pixels sortent de l'image on ne fait rien (le fond est déjà noir de base mais  on peut définir une autre couleur si on veut)
            // il faut penser à mettre le = dans >= sinon on sors de l'image
            if (pos_finale.x >= image.width() || pos_finale.x < 0 || pos_finale.y >= image.height() || pos_finale.y < 0){}

            // sinon on remplace le pixel(x,y) du de l'image vortex par le pixel à la position finale de l'image
            else
            {
                vortex.pixel(x, y) = image.pixel(pos_finale.x, pos_finale.y);
            }
        }
    }

    vortex.save("output/vortex.png");
}