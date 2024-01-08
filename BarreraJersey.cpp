#include "BarreraJersey.h"
#include "DEFINITIONS.h"

BarreraJersey::BarreraJersey(float posX, float posY)
{
    shape.setSize(Vector2f(ANCHO_BARRERA, ALTURA_BARRERA));
    //Prueba de textura, no es la imagen correcta
    this->shapeTexture.loadFromFile("./assets/barreraJersey.png");
    shape.setTexture(&shapeTexture);

    shape.setPosition(Vector2f(posX, posY));
    shape.setOrigin(Vector2f(shape.getSize().x / 2.0f, shape.getSize().y / 2.0f));
}

BarreraJersey::~BarreraJersey()
{
    //dtor
}
