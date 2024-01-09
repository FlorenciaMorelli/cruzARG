#ifndef BARRERANEWJERSEY_H
#define BARRERANEWJERSEY_H

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "BarreraJersey.h"
#include "Tiles.h"

using namespace sf;

class BarreraNewJersey
{
    public:
        BarreraNewJersey(float posY);
        ~BarreraNewJersey();

    protected:

    private:
        BarreraJersey *barrera;
        BarreraJersey *barrera2;
        BarreraJersey *barrera3;
        BarreraJersey *barrera4;
        BarreraJersey *barrera5;
        BarreraJersey *barrera6;
        BarreraJersey *barrera7;
        BarreraJersey *barrera8;
        BarreraJersey *barrera9;
        BarreraJersey *barrera10;
        BarreraJersey *barrera11;
        BarreraJersey *barrera12;

        Tiles *asfalto;
        Tiles *asfalto2;
        Tiles *asfalto3;
        Tiles *asfalto4;
        Tiles *asfalto5;
        Tiles *asfalto6;
        Tiles *asfalto7;
        Tiles *asfalto8;
        Tiles *asfalto9;
        Tiles *asfalto10;
        Tiles *asfalto11;
        Tiles *asfalto12;
};

#endif // BARRERANEWJERSEY_H
