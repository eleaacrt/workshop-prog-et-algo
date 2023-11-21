#include <sil/sil.hpp>
#include <iostream>

void bw(sil::Image image)
{

    // Pour transformer une image couleur en niveaux de gris, on doit remplacer chaque composante [R, G, B] par leur moyenne. Par exemple pour le pixel (X, Y), cela donne : int moy = (rgb[0]+rgb[1]+rgb[2]) / 3 setPixel(X, Y, moy , moy, moy); 4) compléter la fonction filtre qui met en niveaux de gris une image couleur.

    for (glm::vec3 &color : image.pixels())
    {
        float moy = (color.r + color.g + color.b) / 3;
        color.r = moy;
        color.b = moy;
        color.g = moy;
    }

    image.save("output/bw.png");
}