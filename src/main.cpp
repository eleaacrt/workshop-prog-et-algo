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

    // bruit(logo);
    // bw(logo);
    // cercle();
    // convolution(logo);
    // diff_gaussien(flou_faible, flou_fort);
    // diamond_square_patoutafait();
    diamond_square();
    // disque();
    // dithering(photo);
    // emboss(logo);
    // fractale();
    // gaussiens(logo);
    // glitch(logo);
    // gradient();
    // green(logo);
    // kmeans(photo);
    // kuwahara(photo);
    // luminosite(photo);
    // mirror(logo);
    // mosaique(logo);
    // mosaique_inverted(logo);
    // negatif(logo);
    // normalisation(photo);
    // outline(logo);
    // rosace();
    // rotate(logo);
    // sharpen(logo);
    // split(logo);
    // swap(logo);
    // tri(logo);
    // vortex(logo);
    // tri(logo);
    // kuwahara(photo);
}