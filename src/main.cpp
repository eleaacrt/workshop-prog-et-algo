#include <sil/sil.hpp>
#include <iostream>

#include "headers.hpp"

int main()
{
    sil::Image logo{"images/logo.png"};
    sil::Image photo{"images/photo.jpg"};

    // green(logo);
    // swap(logo);
    // bw(logo);
    // negatif(logo);
    // gradient();
    // mirror(logo);
    // bruit(logo);
    // rotate(logo);
    // split(logo);
    // luminosite(photo);
    // disque();
    // cercle();
    // rosace();
    // mosaique(logo);
    // mosaique_inverted(logo);
    // glitch(logo);
    // fractale();
    vortex(logo);
    // vortexN(logo);
}