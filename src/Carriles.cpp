#include "Carriles.h"

#include "../../DEFINITIONS.h"

Carriles::Carriles(Vector2u tamanioVentana, float carril)
{
    float carriles =  tamanioVentana.y / CANT_CARRILES;
    this->numCarril = carriles * carril;
    this->taxi = new Taxi(-ANCHO_TAXI, numCarril);
    this->taxi2 = new Taxi(taxi->getPosOriginalX() - SEPARACION_ENTRE_TAXIS, numCarril);
    this->taxi3 = new Taxi(taxi2->getPosOriginalX() - SEPARACION_ENTRE_TAXIS, numCarril);
    this->taxi4 = new Taxi(taxi3->getPosOriginalX() - SEPARACION_PARA_PERSONAJE, numCarril);
    this->taxi5 = new Taxi(taxi4->getPosOriginalX() - SEPARACION_ENTRE_TAXIS, numCarril);
}

Carriles::~Carriles()
{
    //dtor
}

void Carriles::move(Vector2u tamanioVentana)
{
    this->taxi->move(tamanioVentana);
    this->taxi2->move(tamanioVentana);
    this->taxi3->move(tamanioVentana);
    this->taxi4->move(tamanioVentana);
    this->taxi5->move(tamanioVentana);
}

void Carriles::draw(RenderWindow& window)
{
    window.draw(*taxi);
    window.draw(taxi2);
    window.draw(taxi3);
    window.draw(taxi4);
    window.draw(taxi5);

}
