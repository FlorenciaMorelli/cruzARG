#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Personaje
{
    private:
        RectangleShape personaje;

    public:
        Personaje(Vector2u tamanio);
        ~Personaje();

        void draw(RenderWindow& window);
        void move(Event evnt);

        RectangleShape getShape() { return this->personaje; } //Para detectar colisiones
};

#endif // PERSONAJE_H
