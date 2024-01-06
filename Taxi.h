#ifndef TAXI_H
#define TAXI_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Taxi
{
    private:
        RectangleShape taxi;

    public:
        Taxi(Vector2u tamanio);
        ~Taxi();

        void draw(RenderWindow& window);
        void move(Vector2u tam);

        RectangleShape getShape() { return this->taxi; } //Para detectar colisiones
        float originalPosEx, originalPosY;
};

#endif // TAXI_H
