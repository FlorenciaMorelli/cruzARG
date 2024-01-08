#include "Tiles.h"
#include "DEFINITIONS.h"


Tiles::Tiles(float posX, float posY, int tipo)
{
    shape.setSize(Vector2f(ANCHO_BARRERA, ALTURA_BARRERA));

    if(tipo == 1){ //Asfalto
        this->shapeTexture.loadFromFile("./assets/asfaltoPerpendicular.png");
        shape.setTexture(&shapeTexture);
    }

    shape.setPosition(Vector2f(posX, posY));
    shape.setOrigin(Vector2f(shape.getSize().x / 2.0f, shape.getSize().y / 2.0f));
}

Tiles::~Tiles()
{
    //dtor
}
