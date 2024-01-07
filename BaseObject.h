#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <SFML/Graphics.hpp>

using namespace sf;

class BaseObject
{
    public:
        BaseObject();
        ~BaseObject();

        void draw(RenderWindow& window);
        RectangleShape getShape() { return this->shape; } //Para detectar colisiones

    protected: // accesible en esta clase y en las clases que la heredan
        RectangleShape shape;
        Texture shapeTexture;

};

#endif // BASEOBJECT_H
