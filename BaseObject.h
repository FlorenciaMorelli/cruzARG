#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class BaseObject
{
    protected:
        RectangleShape shape;
        Texture shapeTexture;
        SoundBuffer soundBuffer;
        Sound movingSound;

    public:
        BaseObject();

        void draw(RenderWindow& window);
        RectangleShape getShape() { return this->shape; }
};

#endif // BASEOBJECT_H
