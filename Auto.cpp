#include "Auto.h"

#include <SFML/Graphics.hpp>
#include "Vehiculo.h"
#include "DEFINITIONS.h"

using namespace sf;

Auto::Auto(float posX, float posY, bool direccion) : Vehiculo(posX, posY, direccion)
{
    shape.setSize(Vector2f(ANCHO_AUTO, ALTURA_AUTO));

    this->direccion = direccion;
    if(direccion){
        this->shapeTexture.loadFromFile("./assets/carTrue.png");
        shape.setTexture(&shapeTexture);
    } else {
        this->shapeTexture.loadFromFile("./assets/carFalse.png");
        shape.setTexture(&shapeTexture);
    }

    shape.setPosition(Vector2f(posX, posY));
    shape.setOrigin(Vector2f(shape.getSize().x / 2.0f, shape.getSize().y / 2.0f));

    this->posOriginalX = posX;
    this->posOriginalY = posY;
}

void Auto::move(Vector2u tamanioVentana)
{
    if(direccion){
        shape.move(AUTO_VEL_MOVIMIENTO_X, AUTO_VEL_MOVIMIENTO_Y);
        if(shape.getPosition().x > tamanioVentana.x)
        {
            shape.setPosition(Vector2f(-ANCHO_AUTO, posOriginalY));
        }
    } else {
        shape.move(-AUTO_VEL_MOVIMIENTO_X, AUTO_VEL_MOVIMIENTO_Y);
        if(shape.getPosition().x < 0)
        {
            shape.setPosition(Vector2f(tamanioVentana.x + ANCHO_AUTO, posOriginalY));
        }
    }
}
