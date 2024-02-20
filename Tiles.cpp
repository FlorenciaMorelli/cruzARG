#include "Tiles.h"
#include "DEFINITIONS.h"
#include <vector>

Tiles::Tiles(float posX, float posY, tipoDeTiles tipo)
{
    shape.setSize(Vector2f(ANCHO_BARRERA, ALTURA_BARRERA));
    this->tipoDePiso = tipo;

    if(tipo == Asfalto1){
        this->shapeTexture.loadFromFile("./assets/asfaltoPerpendicular.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == Asfalto2){
        this->shapeTexture.loadFromFile("./assets/asfaltoParalelo.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == VeredaPellegriniIzq){
        this->shapeTexture.loadFromFile("./assets/veredaPellegriniIzq.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == VeredaPellegriniMed){
        this->shapeTexture.loadFromFile("./assets/veredaPellegriniMed.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == VeredaPellegriniDer){
        this->shapeTexture.loadFromFile("./assets/veredaPellegriniDer.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == VeredaCerritoIzq){
        this->shapeTexture.loadFromFile("./assets/veredaCerritoIzq.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == VeredaCerritoMed){
        this->shapeTexture.loadFromFile("./assets/veredaCerritoMed.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == VeredaCerritoDer){
        this->shapeTexture.loadFromFile("./assets/veredaCerritoDer.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == VeredaIzq){
        this->shapeTexture.loadFromFile("./assets/veredaIzq.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == VeredaMed){
        this->shapeTexture.loadFromFile("./assets/veredaMed.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == VeredaDer){
        this->shapeTexture.loadFromFile("./assets/veredaDer.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == Metrobus){
        this->shapeTexture.loadFromFile("./assets/metrobus.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == CanteroIzq){
        this->shapeTexture.loadFromFile("./assets/canteroIzq.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == CanteroMed){
        this->shapeTexture.loadFromFile("./assets/canteroMed.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == CanteroDer){
        this->shapeTexture.loadFromFile("./assets/canteroDer.png");
        shape.setTexture(&shapeTexture);
    } else if (tipo == Barrera){
        this->shapeTexture.loadFromFile("./assets/barreraJersey.png");
        shape.setTexture(&shapeTexture);
    }

    shape.setPosition(Vector2f(posX, posY));
    shape.setOrigin(Vector2f(shape.getSize().x / 2.0f, shape.getSize().y / 2.0f));
}
