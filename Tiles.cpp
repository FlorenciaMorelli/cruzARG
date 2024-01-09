#include "Tiles.h"
#include "DEFINITIONS.h"
#include <vector>

Tiles::Tiles(float posX, float posY, int tipo)
{
    shape.setSize(Vector2f(ANCHO_BARRERA, ALTURA_BARRERA));

    if(tipo == 1){ //Asfalto
        this->shapeTexture.loadFromFile("./assets/asfaltoPerpendicular.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == 2){
        this->shapeTexture.loadFromFile("./assets/veredaPellegriniIzq.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == 3){
        this->shapeTexture.loadFromFile("./assets/veredaPellegriniMed.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == 4){
        this->shapeTexture.loadFromFile("./assets/veredaPellegriniDer.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == 5){
        this->shapeTexture.loadFromFile("./assets/veredaIzq.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == 6){
        this->shapeTexture.loadFromFile("./assets/veredaMed.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == 7){
        this->shapeTexture.loadFromFile("./assets/veredaDer.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == 8){
        this->shapeTexture.loadFromFile("./assets/veredaCerritoIzq.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == 9){
        this->shapeTexture.loadFromFile("./assets/veredaCerritoMed.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == 10){
        this->shapeTexture.loadFromFile("./assets/veredaCerritoDer.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == 11){
        this->shapeTexture.loadFromFile("./assets/metrobus.png");
        shape.setTexture(&shapeTexture);
    }

    shape.setPosition(Vector2f(posX, posY));
    shape.setOrigin(Vector2f(shape.getSize().x / 2.0f, shape.getSize().y / 2.0f));
}
