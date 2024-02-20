#include "BarreraNewJersey.h"

BarreraNewJersey::BarreraNewJersey(float posY)
{
    this->barrera = new BarreraJersey(0.0f, posY);
    this->barrera2 = new BarreraJersey(barrera->getShape().getPosition().x + ANCHO_BARRERA, posY);
    this->barrera3 = new BarreraJersey(barrera2->getShape().getPosition().x + ANCHO_BARRERA, posY);
    this->barrera4 = new BarreraJersey(barrera3->getShape().getPosition().x + ANCHO_BARRERA, posY);

    this->asfalto = new Tiles(barrera4->getShape().getPosition().x + ANCHO_BARRERA, posY, 1);
    this->asfalto2 = new Tiles(asfalto->getShape().getPosition().x + ANCHO_BARRERA, posY, 1);
    this->asfalto3 = new Tiles(asfalto2->getShape().getPosition().x + ANCHO_BARRERA, posY, 1);
    this->asfalto4 = new Tiles(asfalto3->getShape().getPosition().x + ANCHO_BARRERA, posY, 1);

    this->barrera5 = new BarreraJersey(barrera4->getShape().getPosition().x + ESPACIO_ENTRE_CUADRAS, posY);
    this->barrera6 = new BarreraJersey(barrera5->getShape().getPosition().x + ANCHO_BARRERA, posY);
    this->barrera7 = new BarreraJersey(barrera6->getShape().getPosition().x + ANCHO_BARRERA, posY);
    this->barrera8 = new BarreraJersey(barrera7->getShape().getPosition().x + ANCHO_BARRERA, posY);

    this->asfalto5 = new Tiles(barrera8->getShape().getPosition().x + ANCHO_BARRERA, posY, 1);
    this->asfalto6 = new Tiles(asfalto5->getShape().getPosition().x + ANCHO_BARRERA, posY, 1);
    this->asfalto7 = new Tiles(asfalto6->getShape().getPosition().x + ANCHO_BARRERA, posY, 1);
    this->asfalto8 = new Tiles(asfalto7->getShape().getPosition().x + ANCHO_BARRERA, posY, 1);

    this->barrera9 = new BarreraJersey(barrera8->getShape().getPosition().x + ESPACIO_ENTRE_CUADRAS, posY);
    this->barrera10 = new BarreraJersey(barrera9->getShape().getPosition().x + ANCHO_BARRERA, posY);
    this->barrera11 = new BarreraJersey(barrera10->getShape().getPosition().x + ANCHO_BARRERA, posY);
    this->barrera12 = new BarreraJersey(barrera11->getShape().getPosition().x + ANCHO_BARRERA, posY);

    this->asfalto9 = new Tiles(barrera12->getShape().getPosition().x + ANCHO_BARRERA, posY, 1);
    this->asfalto10 = new Tiles(asfalto9->getShape().getPosition().x + ANCHO_BARRERA, posY, 1);
    this->asfalto11 = new Tiles(asfalto10->getShape().getPosition().x + ANCHO_BARRERA, posY, 1);
    this->asfalto12 = new Tiles(asfalto11->getShape().getPosition().x + ANCHO_BARRERA, posY, 1);

}

BarreraNewJersey::~BarreraNewJersey()
{
    //dtor
}
