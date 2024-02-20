#ifndef BARRERAJERSEY_H
#define BARRERAJERSEY_H

#include "Tiles.h"
#include "Personaje.h"

using namespace sf;

class BarreraJersey
{
    private:
        std::vector<Tiles*> barrera;

    public:
        BarreraJersey(float tamVentana, float posX, float posY);

        void draw(RenderWindow& window);
        bool checkCollision(Personaje* personaje, RenderWindow& window);
};

#endif // BARRERAJERSEY_H
