#include "Colectivo.h"
#include "Vehiculo.h"
#include <cstdlib>
#include <ctime>

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"

using namespace sf;

Colectivo::Colectivo(float posX, float posY, bool direccion) : Vehiculo(posX, posY, direccion)
{
    shape.setSize(Vector2f(ANCHO_COLECTIVO, ALTURA_COLECTIVO));

    this->direccion = direccion;
    if(direccion){
        if (rand() % 3 == 0) {
            this->shapeTexture.loadFromFile("./assets/colectivoTrue1.png");
        } else if(rand() % 2 == 0){
            this->shapeTexture.loadFromFile("./assets/colectivoTrue2.png");
        } else {
            this->shapeTexture.loadFromFile("./assets/colectivoTrue3.png");
        }
    } else {
        if (rand() % 3 == 0) {
            this->shapeTexture.loadFromFile("./assets/colectivoFalse1.png");
        } else if(rand() % 2 == 0){
            this->shapeTexture.loadFromFile("./assets/colectivoFalse2.png");
        } else {
            this->shapeTexture.loadFromFile("./assets/colectivoFalse3.png");
        }
    }

    shape.setTexture(&shapeTexture);
    shape.setPosition(Vector2f(posX, posY));
    shape.setOrigin(Vector2f(shape.getSize().x / 2.0f, shape.getSize().y / 2.0f));

    this->posOriginalX = posX;
    this->posOriginalY = posY;

}

void Colectivo::move(Vector2u tamanioVentana)
{
    if(direccion){
        shape.move(COL_VEL_MOVIMIENTO_X, COL_VEL_MOVIMIENTO_Y);
        if(shape.getPosition().x > tamanioVentana.x)
        {
            shape.setPosition(Vector2f(-ANCHO_COLECTIVO, posOriginalY));
        }
    } else {
        shape.move(-COL_VEL_MOVIMIENTO_X, COL_VEL_MOVIMIENTO_Y);
        if(shape.getPosition().x < 0)
        {
            shape.setPosition(Vector2f(tamanioVentana.x + ANCHO_COLECTIVO, posOriginalY));
        }
    }
}
