#include "CarlosPellegrini.h"

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"

CarlosPellegrini::CarlosPellegrini(Vector2u tamanioVentana)
{
    this->taxi = new Taxi(-ANCHO_TAXI, tamanioVentana.y / 2.0f);
    this->taxi2 = new Taxi(taxi->getPosOriginalX() - SEPARACION_ENTRE_TAXIS, tamanioVentana.y / 2.0f);
    this->taxi3 = new Taxi(taxi2->getPosOriginalX() - SEPARACION_ENTRE_TAXIS, tamanioVentana.y / 2);
    this->taxi4 = new Taxi(taxi3->getPosOriginalX() - SEPARACION_PARA_PERSONAJE, tamanioVentana.y / 2);
    this->taxi5 = new Taxi(taxi4->getPosOriginalX() - SEPARACION_ENTRE_TAXIS, tamanioVentana.y / 2);
}

CarlosPellegrini::~CarlosPellegrini()
{
    //dtor
}

void CarlosPellegrini::move(Vector2u tamanioVentana)
{
        taxi->move(tamanioVentana);
        taxi2->move(tamanioVentana);
        taxi3->move(tamanioVentana);
        taxi4->move(tamanioVentana);
        taxi5->move(tamanioVentana);
}
