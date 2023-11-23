#include <sil/sil.hpp>
#include <iostream>
#include "headers.hpp"

int main()
{
    sil::Image logo{"images/logo.png"};
    sil::Image photo{"images/photo.jpg"};
    sil::Image photo_faible_contraste{"images/photo_faible_contraste.jpg"};
    sil::Image flou_faible{"output/gaussien_leger.png"};
    sil::Image flou_fort{"output/gaussien_hard.png"};

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
    // vortex(logo);
    // dithering(photo);
    // normalisation(photo);
    // convolution(logo);
    // convolution(logo);
    // emboss(logo);
    // outline(logo);
    // sharpen(logo);
    // gaussiens(photo);
    // diff_gaussien(flou_faible, flou_fort);
    tri(logo);
    // kuwahara(photo);
}