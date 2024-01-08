#ifndef CARRILES_H
#define CARRILES_H

#include <SFML/Graphics.hpp>
#include "../Taxi.h"
#include "../Auto.h"

using namespace sf;

class Carriles
{
    public:
        Carriles(Vector2u tamanioVentana, float carril);
        ~Carriles();

        void move(Vector2u tamanioVentana);
        void draw(RenderWindow& window);

    protected:

    private:
        float numCarril;
        Taxi *taxi;
        Taxi *taxi2;
        Taxi *taxi3;
        Taxi *taxi4;
        Taxi *taxi5;
        Taxi *taxi6;
        Taxi *taxi7;
};

#endif // CARRILES_H
