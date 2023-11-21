#include <sil/sil.hpp>
#include <iostream>

void mosaique_inverted(sil::Image image)
{

    sil::Image mosaique{image.width() * 5 /*width*/, image.height() * 5 /*height*/};
    sil::Image mirror{image.width() /*width*/, image.height() /*height*/};
    sil::Image inverted_mirror{image.width() /*width*/, image.height() /*height*/};
    sil::Image inverted_image{image.width() /*width*/, image.height() /*height*/};
    sil::Image patern{image.width() * 2 /*width*/, image.height() * 2 /*height*/};

    int countX{0};
    int countY{0};

    // création du  mirroir
    for (int x{0}; x < (image.width() / 2); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            mirror.pixel(x, y) = image.pixel((image.width() - 1 - x), y);
            mirror.pixel((image.width() - 1 - x), y) = image.pixel(x, y);
        }
    }

    // inversion du mirroir
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < (image.height() / 2); y++)
        {
            inverted_mirror.pixel(x, y) = mirror.pixel(x, (mirror.height() - 1 - y));
            inverted_mirror.pixel(x, (mirror.height() - 1 - y)) = mirror.pixel(x, y);
        }
    }

    // inversion de l'image
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < (image.height() / 2); y++)
        {
            inverted_image.pixel(x, y) = image.pixel(x, (image.height() - 1 - y));
            inverted_image.pixel(x, (image.height() - 1 - y)) = image.pixel(x, y);
        }
    }

    for (int x{0}; x < patern.width(); x++)
    {
        for (int y{0}; y < patern.height(); y++)
        {
            if (x > image.width() && y > image.height())
            {
                patern.pixel(x, y) = inverted_mirror.pixel(x % inverted_mirror.width(), y % inverted_mirror.height());
            }
            if (x < image.width() && y > image.height())
            {
                patern.pixel(x, y) = inverted_image.pixel(x % inverted_image.width(), y % inverted_image.height());
            }
            if (x > image.width() && y < image.height())
            {
                patern.pixel(x, y) = mirror.pixel(x % mirror.width(), y % mirror.height());
            }
            if (x < image.width() && y < image.height())
            {
                patern.pixel(x, y) = image.pixel(x % image.width(), y % image.height());
            }
        }
    }

    for (int x{0}; x < mosaique.width(); x++)
    {
        for (int y{0}; y < mosaique.height(); y++)
        {
            mosaique.pixel(x, y) = patern.pixel(x % patern.width(), y % patern.height());
        }
    }

    mosaique.save("output/mosaique_inverted.png");
}
