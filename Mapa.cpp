#include "Mapa.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include "DEFINITIONS.h"
#include "Tiles.h"

using namespace sf;

Mapa::Mapa(Vector2u tamVentana)
{
    this->tamanioVentana = tamVentana;

    this->carriles =  tamanioVentana.y / 14.0f;
    this->veredaCerrito1 = carriles * 0.0f;
    this->veredaCerrito2 = carriles * 1.0f;
    this->cerrito = carriles * 2.0f;
    this->cantero1 = carriles * 3.0f;
    this->nueveJulioAutos1 = carriles * 4.0f;
    this->newJersey1 = carriles * 5.0f;
    this->nueveJulioColectivos1 = carriles * 6.0f;
    this->metrobus = carriles * 7.0f;
    this->nueveJulioColectivos2 = carriles * 8.0f;
    this->newJersey2 = carriles * 9.0f;
    this->nueveJulioAutos2 = carriles * 10.0f;
    this->cantero2 = carriles * 11.0f;
    this->carlosPellegrini = carriles * 12.0f;
    this->veredaPellegrini1 = carriles * 13.0f;
    this->veredaPellegrini2 = carriles * 14.0f;

    crearCerrito(this->tamanioVentana, this->veredaCerrito2, veredaCerrito1);
    crearCalle(this->calleCerrito, this->tamanioVentana, this->cerrito);
    crearCantero(this->canteroVector1, this->tamanioVentana, this->cantero1);
    crearCalle(this->nueveAutos1, this->tamanioVentana, this->nueveJulioAutos1);
    crearCalle(this->nueveColectivos1, this->tamanioVentana, this->nueveJulioColectivos1);
    crearMetrobus(this->tamanioVentana, this->metrobus);
    crearCalle(this->nueveColectivos2, this->tamanioVentana, this->nueveJulioColectivos2);
    crearCalle(this->nueveAutos2, this->tamanioVentana, this->nueveJulioAutos2);
    crearCantero(this->canteroVector2, this->tamanioVentana, this->cantero2);
    crearCalle(this->callePellegrini, this->tamanioVentana, this->carlosPellegrini);
    crearPellegrini(this->tamanioVentana, this->veredaPellegrini1, this->veredaPellegrini2);


}

Mapa::~Mapa()
{
    //dtor
}


void Mapa::crearMetrobus(Vector2u tamanioVentana, float posY)
{
    if (metrobusVector.empty())
    {
        this->metrobusVector.push_back(new Tiles(0.0f, posY, 11));
    } else {
        this->metrobusVector.push_back(new Tiles(metrobusVector.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, 11));
    }

    while (metrobusVector.back()->getShape().getPosition().x < tamanioVentana.x)
    {
        this->metrobusVector.push_back(new Tiles(metrobusVector.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, 11));

        if (metrobusVector.size() % 4 == 0)
        {
            for(unsigned int i = 1; i <= 4; i++)
            {
                this->metrobusVector.push_back(new Tiles(metrobusVector.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, 1));
            }
        }
    }
}

void Mapa::crearCerrito(Vector2u tamanioVentana, float posY, float posY2)
{
    if (cerritoVereda.empty())
    {
        this->cerritoVereda.push_back(new Tiles(0.0f, posY, 8));
        this->cerritoVereda.push_back(new Tiles(0.0f, posY2, 5));

    }

    while (cerritoVereda.back()->getShape().getPosition().x < tamanioVentana.x)
    {
        if (cerritoVereda.size() > 2)
        {
            float posX = cerritoVereda.back()->getShape().getPosition().x + ANCHO_BARRERA;
            this->cerritoVereda.push_back(new Tiles(posX, posY, 8));
            this->cerritoVereda.push_back(new Tiles(posX, posY2, 5));
        }

        float posX8 = cerritoVereda.back()->getShape().getPosition().x + ANCHO_BARRERA;
        this->cerritoVereda.push_back(new Tiles(posX8, posY, 9));
        this->cerritoVereda.push_back(new Tiles(posX8, posY2, 6));

        float posX9 = cerritoVereda.back()->getShape().getPosition().x + ANCHO_BARRERA;
        this->cerritoVereda.push_back(new Tiles(posX9, posY, 9));
        this->cerritoVereda.push_back(new Tiles(posX9, posY2, 6));

        float posX10 = cerritoVereda.back()->getShape().getPosition().x + ANCHO_BARRERA;
        this->cerritoVereda.push_back(new Tiles(posX10, posY, 10));
        this->cerritoVereda.push_back(new Tiles(posX10, posY2, 7));


        for (unsigned int i = 1; i <= 4; i++)
        {
            float posX11 = cerritoVereda.back()->getShape().getPosition().x + ANCHO_BARRERA;
            this->cerritoVereda.push_back(new Tiles(posX11, posY, 1));
            this->cerritoVereda.push_back(new Tiles(posX11, posY2, 1));

        }
    }
}

void Mapa::crearPellegrini(Vector2u tamanioVentana, float posY, float posY2)
{
    if (pellegriniVereda.empty())
    {
        this->pellegriniVereda.push_back(new Tiles(0.0f, posY, 2));
        this->pellegriniVereda.push_back(new Tiles(0.0f, posY2, 5));

    }

    while (pellegriniVereda.back()->getShape().getPosition().x < tamanioVentana.x)
    {
        if (pellegriniVereda.size() > 2)
        {
            float posX = pellegriniVereda.back()->getShape().getPosition().x + ANCHO_BARRERA;
            this->pellegriniVereda.push_back(new Tiles(posX, posY, 2));
            this->pellegriniVereda.push_back(new Tiles(posX, posY2, 5));
        }

        float posX8 = pellegriniVereda.back()->getShape().getPosition().x + ANCHO_BARRERA;
        this->pellegriniVereda.push_back(new Tiles(posX8, posY, 3));
        this->pellegriniVereda.push_back(new Tiles(posX8, posY2, 6));

        float posX9 = pellegriniVereda.back()->getShape().getPosition().x + ANCHO_BARRERA;
        this->pellegriniVereda.push_back(new Tiles(posX9, posY, 3));
        this->pellegriniVereda.push_back(new Tiles(posX9, posY2, 6));

        float posX10 = pellegriniVereda.back()->getShape().getPosition().x + ANCHO_BARRERA;
        this->pellegriniVereda.push_back(new Tiles(posX10, posY, 4));
        this->pellegriniVereda.push_back(new Tiles(posX10, posY2, 7));


        for (unsigned int i = 1; i <= 4; i++)
        {
            float posX11 = pellegriniVereda.back()->getShape().getPosition().x + ANCHO_BARRERA;
            this->pellegriniVereda.push_back(new Tiles(posX11, posY, 1));
            this->pellegriniVereda.push_back(new Tiles(posX11, posY2, 1));

        }
    }
}

void Mapa::crearCantero(std::vector<Tiles*>& vect, Vector2u tamanioVentana, float posY)
{
    if (vect.empty())
    {
        vect.push_back(new Tiles(0.0f, posY, 12));
    } else {
        vect.push_back(new Tiles(vect.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, 12));
    }

    while (vect.back()->getShape().getPosition().x < tamanioVentana.x)
    {
        vect.push_back(new Tiles(vect.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, 12));

        if (vect.size() % 4 == 0)
        {
            for(unsigned int i = 1; i <= 4; i++)
            {
                vect.push_back(new Tiles(vect.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, 1));
            }
        }
    }
}

void Mapa::crearCalle(std::vector<Tiles*>& vect, Vector2u tamanioVentana, float posY)
{
    if (vect.empty())
    {
        vect.push_back(new Tiles(0.0f, posY, 13));
    } else {
        vect.push_back(new Tiles(vect.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, 13));
    }

    while (vect.back()->getShape().getPosition().x < tamanioVentana.x)
    {
        vect.push_back(new Tiles(vect.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, 13));
    }
}

void Mapa::draw(RenderWindow& window)
{
    for(Tiles* veredaCerrito: this->cerritoVereda)
        veredaCerrito->draw(window);

    for(Tiles* callCerrito: this->calleCerrito)
        callCerrito->draw(window);

    for(Tiles* cantero1: this->canteroVector1)
        cantero1->draw(window);

    for(Tiles* nueveAuto1: this->nueveAutos1)
        nueveAuto1->draw(window);

    for(Tiles* nueveColectivo1: this->nueveColectivos1)
        nueveColectivo1->draw(window);

    for(Tiles* metrobus : this->metrobusVector)
        metrobus->draw(window);

    for(Tiles* nueveColectivo2: this->nueveColectivos2)
        nueveColectivo2->draw(window);

    for(Tiles* nueveAuto2: this->nueveAutos2)
        nueveAuto2->draw(window);

    for(Tiles* cantero2: this->canteroVector2)
        cantero2->draw(window);

    for(Tiles* callPellegrini: this->callePellegrini)
        callPellegrini->draw(window);

    for(Tiles* veredaPellegrini: this->pellegriniVereda)
        veredaPellegrini->draw(window);
}