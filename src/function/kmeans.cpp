#include <sil/sil.hpp>
#include <iostream>
#include "../../lib/random.hpp"

void kmeans(sil::Image image)
{

    // je me créer une nouvelle image
    sil::Image kmeans(image.width(), image.height());

    // c'est le nombre de couleurs que je veux à la fin
    int nb_colors{2};

    // les pixels centroides qui serviront de première reférence
    std::vector<glm::vec3> px_centro{};

    // la moyenne des couleurs plus proches des centroïdes
    std::vector<glm::vec3> moy{};

    // le compteur de couleurs dans chaque moyenne
    std::vector<float> count{};

    // dans le vecteur contenant les pixels centroides, je push des pixels aléatoires de l'image de base
    for (float i{0}; i < nb_colors; i++)
    {
        px_centro.push_back(image.pixel(random_int(0, image.width()), random_int(0, image.height())));
    }
    moy.resize(px_centro.size());
    count.resize(px_centro.size());

    for (int k{0}; k < 10; k++)
    {

        for (int i{0}; i < nb_colors; i++)
        {
            moy[i] = glm::vec3{0.f};
            count[i] = 0.f;
        };
        // pour chaque pixel de l'image :
        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                // indice de la couleur centroide dans le vecteur px_centro
                int i_color{0};

                // pour chaque pixel centroide, je regarde si sa distance est inférieure à celle d'avant, si oui je change l'indice du pixel le plus proche
                for (int i{0}; i < nb_colors; i++)
                {
                    if (glm::distance(px_centro[i_color], image.pixel(x, y)) > glm::distance(px_centro[i], image.pixel(x, y)))
                    {
                        i_color = i;
                    }
                };

                // j'ajoute 1 à la couleur de pixel moyen
                count[i_color] += 1.f;

                moy[i_color] += image.pixel(x,y);
                // kmeans.pixel(x, y) = vec3_count;
            }
        }

        for (int i{0}; i < nb_colors; i++)
        {
            // glm::vec3 vec3_count{count[i], count[i], count[i]};
            moy[i] = moy[i] / count[i];
        };

        px_centro = moy;
    }

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            for (int i{0}; i < nb_colors; i++)
            {
                // indice de la couleur centroide dans le vecteur px_centro
                int i_color{0};

                // pour chaque pixel centroide, je regarde si sa distance est inférieure à celle d'avant, si oui je change l'indice du pixel le plus proche
                for (int i{0}; i < nb_colors; i++)
                {
                    if (glm::distance(px_centro[i_color], image.pixel(x, y)) >= glm::distance(px_centro[i], image.pixel(x, y)))
                    {
                        i_color = i;
                    }
                };

                // plus proche couleur dans le tableau  grace à l'indice trouvé dans le for précédent
                glm::vec3 pp_color{px_centro[i_color]};

                kmeans.pixel(x, y) = pp_color;
            };
        }
    }

    kmeans.save("output/kmeans2.png");
}