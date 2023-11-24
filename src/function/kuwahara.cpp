#include <sil/sil.hpp>
#include <iostream>
#include <math.h>
#include <algorithm>

void kuwahara(sil::Image image)
{
    // création des images
    sil::Image kuwahara{image.width(), image.height()};

    int sector_size{4};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            glm::vec3 moy_sect1{};
            glm::vec3 moy_sect2{};
            glm::vec3 moy_sect3{};
            glm::vec3 moy_sect4{};

            float et_sect1{};
            float et_sect2{};
            float et_sect3{};
            float et_sect4{};

            // secteur 1 :
            float count_sect1{0.f};
            glm::vec3 sum_sect1{0.f, 0.f, 0.f};

            for (int i{x - sector_size + 1}; i <= x; i++)
            {
                for (int j{y - sector_size + 1}; j <= y; j++)
                {
                    // verification "si on sort de l'image alors le pixel ne compte pas"
                    if (i >= kuwahara.width() || i <= 0 || j >= kuwahara.height() || j <= 0)
                    {
                    }
                    // sinon on le compte dans la moyenne et on ajoute 1 au compteur de pixels
                    else
                    {
                        sum_sect1 += image.pixel(i, j);
                        count_sect1 += 1;
                    }
                }
            }

            // calcul de la moyenne du secteur  1
            moy_sect1 = sum_sect1 / count_sect1;

            // on initialise la somme des couleurs - moyennes au carré pour calculer l'écart type
            float sum_color_moy1{};

            // on ajoute pour chaque pixel : sa couleur  - la moyenne globale au carré (flotant)
            for (int i{x - sector_size + 1}; i <= x; i++)
            {
                for (int j{y - sector_size + 1}; j <= y; j++)
                {
                    // verification "si on sort de l'image alors le pixel ne compte pas"
                    if (i >= kuwahara.width() || i <= 0 || j >= kuwahara.height() || j <= 0)
                    {
                    }
                    // sinon on le compte dans la moyenne et on ajoute 1 au compteur de pixels
                    else
                    {
                        float color_pixel = ((image.pixel(i, j).r + image.pixel(i, j).g + image.pixel(i, j).b) / 3);
                        float moy = (moy_sect1.r + moy_sect1.g + moy_sect1.b) / 3;

                        sum_color_moy1 += pow((color_pixel - moy), 2);
                    }
                }
            }
            // l'écart type devient la racine carré de cette somme
            et_sect1 = sqrt(sum_color_moy1 / (count_sect1));

            // secteur 2 :
            float count_sect2{0.f};
            glm::vec3 sum_sect2{0.f, 0.f, 0.f};

            for (int i{x}; i < sector_size + x; i++)
            {
                for (int j{y}; j < sector_size + y; j++)
                {

                    // verification "si on sort de l'image alors le pixel ne compte pas"
                    if (i >= kuwahara.width() || i <= 0 || j >= kuwahara.height() || j <= 0)
                    {
                    }
                    // sinon on le compte dans la moyenne et on ajoute 1 au compteur de pixels
                    else
                    {
                        sum_sect2 += image.pixel(i, j);
                        count_sect2 += 1;
                    }
                }
            }

            // calcul de la moyenne du secteur  2
            moy_sect2 = sum_sect2 / count_sect2;

            // on initialise la somme des couleurs - moyennes au carré pour calculer l'écart type
            float sum_color_moy2{};

            // on ajoute pour chaque pixel : sa couleur  - la moyenne globale au carré (flotant)
            for (int i{x}; i < sector_size + x; i++)
            {
                for (int j{y}; j < sector_size + y; j++)
                {
                    // verification "si on sort de l'image alors le pixel ne compte pas"
                    if (i >= kuwahara.width() || i <= 0 || j >= kuwahara.height() || j <= 0)
                    {
                    }
                    // sinon on le compte dans la moyenne et on ajoute 1 au compteur de pixels
                    else
                    {
                        float color_pixel = ((image.pixel(i, j).r + image.pixel(i, j).g + image.pixel(i, j).b) / 3);
                        float moy = (moy_sect2.r + moy_sect2.g + moy_sect2.b) / 3;

                        sum_color_moy2 += pow((color_pixel - moy), 2);
                    }
                }
            }
            // l'écart type devient la racine carré de cette somme
            et_sect2 = sqrt(sum_color_moy2 / (count_sect2));

            // secteur 3 :

            float count_sect3{0.f};

            glm::vec3 sum_sect3{0.f, 0.f, 0.f};

            for (int i{x - sector_size + 1}; i <= x; i++)
            {
                for (int j{y}; j < sector_size + y; j++)
                {
                    // verification "si on sort de l'image alors le pixel ne compte pas"
                    if (i >= kuwahara.width() || i <= 0 || j >= kuwahara.height() || j <= 0)
                    {
                    }
                    // sinon on le compte dans la moyenne et on ajoute 1 au compteur de pixels
                    else
                    {
                        sum_sect3 += image.pixel(i, j);
                        count_sect3 += 1;
                    }
                }
            }

            // calcul de la moyenne du secteur  3
            moy_sect3 = sum_sect3 / count_sect3;

            // on initialise la somme des couleurs - moyennes au carré pour calculer l'écart type
            float sum_color_moy3{};

            // on ajoute pour chaque pixel : sa couleur  - la moyenne globale au carré (flotant)
            for (int i{x - sector_size + 1}; i <= x; i++)
            {
                for (int j{y}; j < sector_size + y; j++)
                {
                    // verification "si on sort de l'image alors le pixel ne compte pas"
                    if (i >= kuwahara.width() || i <= 0 || j >= kuwahara.height() || j <= 0)
                    {
                    }
                    // sinon on le compte dans la moyenne et on ajoute 1 au compteur de pixels
                    else
                    {
                        float color_pixel = ((image.pixel(i, j).r + image.pixel(i, j).g + image.pixel(i, j).b) / 3);
                        float moy = (moy_sect3.r + moy_sect3.g + moy_sect3.b) / 3;

                        sum_color_moy3 += pow((color_pixel - moy), 2);
                    }
                }
            }
            // l'écart type devient la racine carré de cette somme
            et_sect3 = sqrt(sum_color_moy3 / (count_sect3));

            // secteur 4 :
            float count_sect4{0.f};
            glm::vec3 sum_sect4{0.f, 0.f, 0.f};

            for (int i{x}; i < sector_size + x; i++)
            {
                for (int j{y - sector_size + 1}; j <= y; j++)
                {
                    // verification "si on sort de l'image alors le pixel ne compte pas"
                    if (i >= kuwahara.width() || i <= 0 || j >= kuwahara.height() || j <= 0)
                    {
                    }
                    // sinon on le compte dans la moyenne et on ajoute 1 au compteur de pixels
                    else
                    {
                        sum_sect4 += image.pixel(i, j);
                        count_sect4 += 1;
                    }
                }
            }

            // calcul de la moyenne du secteur  4
            moy_sect4 = sum_sect4 / count_sect4;

            // on initialise la somme des couleurs - moyennes au carré pour calculer l'écart type
            float sum_color_moy4{};

            // on ajoute pour chaque pixel : sa couleur  - la moyenne globale au carré (flotant)
            for (int i{x}; i < sector_size + x; i++)
            {
                for (int j{y - sector_size + 1}; j <= y; j++)
                {
                    // verification "si on sort de l'image alors le pixel ne compte pas"
                    if (i >= kuwahara.width() || i <= 0 || j >= kuwahara.height() || j <= 0)
                    {
                    }
                    // sinon on le compte dans la moyenne et on ajoute 1 au compteur de pixels
                    else
                    {
                        float color_pixel = ((image.pixel(i, j).r + image.pixel(i, j).g + image.pixel(i, j).b) / 3);
                        float moy = (moy_sect4.r + moy_sect4.g + moy_sect4.b) / 3;

                        sum_color_moy4 += pow((color_pixel - moy), 2);
                    }
                }
            }
            // l'écart type devient la racine carré de cette somme
            et_sect4 = sqrt(sum_color_moy4 / (count_sect4));

            // ------------------------------------------------------

            std::vector<float> all_et{et_sect1, et_sect2, et_sect3, et_sect4};
            std::sort(all_et.begin(), all_et.end());

            if (all_et[0] == et_sect1)
            {
                kuwahara.pixel(x, y) = moy_sect1;
            }
            if (all_et[0] == et_sect2)
            {
                kuwahara.pixel(x, y) = moy_sect2;
            }
            if (all_et[0] == et_sect3)
            {
                kuwahara.pixel(x, y) = moy_sect3;
            }
            if (all_et[0] == et_sect4)
            {
                kuwahara.pixel(x, y) = moy_sect4;
            }
        }
    }

    kuwahara.save("output/kuwahara.png");
}