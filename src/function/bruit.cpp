#include <sil/sil.hpp>
#include <iostream>
#include "../../lib/random.hpp"

void bruit(sil::Image image)
{

    // Il est plus conventionnel d'écrire ce code avec une boucle for. On préfère éviter les boucles while autant que possible, et ne les utiliser que dans les cas où une boucle for ne peut pas faire le travail.
    for(int i{0}; i < 15000; ++i)
    {
        // Remarque : vous êtes en train de changer le rouge d'un pixel random, puis le bleu d'un AUTRE pixel, car vous appelez à nouveau random_int pour le x.
        // Si ce n'était pas votre intention et que vous vouliez plutôt modifier le r, g et b du MÊME pixel, il aurait fallu faire :
        int const x{random_int(0, image.width())};
        int const y{random_int(0, image.height())};
        image.pixel(x, y).r = random_float(0, 1);
        image.pixel(x, y).g = random_float(0, 1);
        image.pixel(x, y).b = random_float(0, 1);
    }

    image.save("output/bruit.png");
}