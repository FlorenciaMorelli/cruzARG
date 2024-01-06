#ifndef TAXI_H
#define TAXI_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Taxi
{
    private:
        RectangleShape taxi;
        float posOriginalX, posOriginalY;

    public:
        Taxi(float posX, float posY);
        ~Taxi();

        void draw(RenderWindow& window);
        void move(Vector2u tamanioVentana);

        RectangleShape getShape() { return this->taxi; } //Para detectar colisiones
};

#endif // TAXI_H
