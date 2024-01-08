#ifndef CARLOSPELLEGRINI_H
#define CARLOSPELLEGRINI_H

#include <SFML/Graphics.hpp>
#include "Taxi.h"
#include "Auto.h"

using namespace sf;

class CarlosPellegrini
{
    public:
        CarlosPellegrini(Vector2u tamanioVentana);
        ~CarlosPellegrini();

        void move(Vector2u tamanioVentana);

    protected:

    private:
        Taxi *taxi;
        Taxi *taxi2;
        Taxi *taxi3;
        Taxi *taxi4;
        Taxi *taxi5;
        Taxi *taxi6;
        Taxi *taxi7;
};

#endif // CARLOSPELLEGRINI_H
