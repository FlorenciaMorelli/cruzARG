#include "Mapa.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include "DEFINITIONS.h"
#include "Tiles.h"

using namespace sf;

Mapa::Mapa(Vector2u tamVentana)
{
    this->tamanioVentana = tamVentana;

    this->carriles =  CARRILES;
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
    crearCalle(this->calleBarrera1, this->tamanioVentana, this->newJersey1);
    crearCalle(this->nueveColectivos1, this->tamanioVentana, this->nueveJulioColectivos1);
    crearMetrobus(this->tamanioVentana, this->metrobus);
    crearCalle(this->nueveColectivos2, this->tamanioVentana, this->nueveJulioColectivos2);
    crearCalle(this->calleBarrera2, this->tamanioVentana, this->newJersey2);
    crearCalle(this->nueveAutos2, this->tamanioVentana, this->nueveJulioAutos2);
    crearCantero(this->canteroVector2, this->tamanioVentana, this->cantero2);
    crearCalle(this->callePellegrini, this->tamanioVentana, this->carlosPellegrini);
    crearPellegrini(this->tamanioVentana, this->veredaPellegrini1, this->veredaPellegrini2);


}

Mapa::~Mapa(){}


void Mapa::crearMetrobus(Vector2u tamanioVentana, float posY)
{
    if (metrobusVector.empty())
    {
        this->metrobusVector.push_back(new Tiles(0.0f, posY, Metrobus));
    } else {
        this->metrobusVector.push_back(new Tiles(metrobusVector.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, Metrobus));
    }

    while (metrobusVector.back()->getShape().getPosition().x < tamanioVentana.x)
    {
        this->metrobusVector.push_back(new Tiles(metrobusVector.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, Metrobus));

        if (metrobusVector.size() % 4 == 0)
        {
            for(unsigned int i = 1; i <= 4; i++)
            {
                this->metrobusVector.push_back(new Tiles(metrobusVector.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, Asfalto1));
            }
        }
    }
}

void Mapa::crearCerrito(Vector2u tamanioVentana, float posY, float posY2)
{
    if (veredaCerrito.empty())
    {
        this->veredaCerrito.push_back(new Tiles(0.0f, posY, VeredaCerritoIzq));
        this->veredaCerrito.push_back(new Tiles(0.0f, posY2, VeredaIzq));

    }

    while (veredaCerrito.back()->getShape().getPosition().x < tamanioVentana.x)
    {
        if (veredaCerrito.size() > 2)
        {
            float posX = veredaCerrito.back()->getShape().getPosition().x + ANCHO_BARRERA;
            this->veredaCerrito.push_back(new Tiles(posX, posY, VeredaCerritoIzq));
            this->veredaCerrito.push_back(new Tiles(posX, posY2, VeredaIzq));
        }

        float posX8 = veredaCerrito.back()->getShape().getPosition().x + ANCHO_BARRERA;
        this->veredaCerrito.push_back(new Tiles(posX8, posY, VeredaCerritoMed));
        this->veredaCerrito.push_back(new Tiles(posX8, posY2, VeredaMed));

        float posX9 = veredaCerrito.back()->getShape().getPosition().x + ANCHO_BARRERA;
        this->veredaCerrito.push_back(new Tiles(posX9, posY, VeredaCerritoMed));
        this->veredaCerrito.push_back(new Tiles(posX9, posY2, VeredaMed));

        float posX10 = veredaCerrito.back()->getShape().getPosition().x + ANCHO_BARRERA;
        this->veredaCerrito.push_back(new Tiles(posX10, posY, VeredaCerritoDer));
        this->veredaCerrito.push_back(new Tiles(posX10, posY2, VeredaDer));


        for (unsigned int i = 1; i <= 4; i++)
        {
            float posX11 = veredaCerrito.back()->getShape().getPosition().x + ANCHO_BARRERA;
            this->veredaCerrito.push_back(new Tiles(posX11, posY, Asfalto1));
            this->veredaCerrito.push_back(new Tiles(posX11, posY2, Asfalto1));

        }
    }
}

void Mapa::crearPellegrini(Vector2u tamanioVentana, float posY, float posY2)
{
    if (veredaPellegrini.empty())
    {
        this->veredaPellegrini.push_back(new Tiles(0.0f, posY, VeredaPellegriniIzq));
        this->veredaPellegrini.push_back(new Tiles(0.0f, posY2, VeredaIzq));

    }

    while (veredaPellegrini.back()->getShape().getPosition().x < tamanioVentana.x)
    {
        if (veredaPellegrini.size() > 2)
        {
            float posX = veredaPellegrini.back()->getShape().getPosition().x + ANCHO_BARRERA;
            this->veredaPellegrini.push_back(new Tiles(posX, posY, VeredaPellegriniIzq));
            this->veredaPellegrini.push_back(new Tiles(posX, posY2, VeredaIzq));
        }

        float posX8 = veredaPellegrini.back()->getShape().getPosition().x + ANCHO_BARRERA;
        this->veredaPellegrini.push_back(new Tiles(posX8, posY, VeredaPellegriniMed));
        this->veredaPellegrini.push_back(new Tiles(posX8, posY2, VeredaMed));

        float posX9 = veredaPellegrini.back()->getShape().getPosition().x + ANCHO_BARRERA;
        this->veredaPellegrini.push_back(new Tiles(posX9, posY, VeredaPellegriniMed));
        this->veredaPellegrini.push_back(new Tiles(posX9, posY2, VeredaMed));

        float posX10 = veredaPellegrini.back()->getShape().getPosition().x + ANCHO_BARRERA;
        this->veredaPellegrini.push_back(new Tiles(posX10, posY, VeredaPellegriniDer));
        this->veredaPellegrini.push_back(new Tiles(posX10, posY2, VeredaDer));


        for (unsigned int i = 1; i <= 4; i++)
        {
            float posX11 = veredaPellegrini.back()->getShape().getPosition().x + ANCHO_BARRERA;
            this->veredaPellegrini.push_back(new Tiles(posX11, posY, Asfalto1));
            this->veredaPellegrini.push_back(new Tiles(posX11, posY2, Asfalto1));

        }
    }
}

void Mapa::crearCantero(std::vector<Tiles*>& vect, Vector2u tamanioVentana, float posY)
{
    if (vect.empty())
    {
        vect.push_back(new Tiles(0.0f, posY, CanteroIzq));
    }

    while (vect.back()->getShape().getPosition().x < tamanioVentana.x)
    {
        if (vect.size() > 2)
        {
            float posX = vect.back()->getShape().getPosition().x + ANCHO_BARRERA;
            vect.push_back(new Tiles(posX, posY, CanteroIzq));
        }

        float posX2 = vect.back()->getShape().getPosition().x + ANCHO_BARRERA;
        vect.push_back(new Tiles(posX2, posY, CanteroMed));

        float posX3 = vect.back()->getShape().getPosition().x + ANCHO_BARRERA;
        vect.push_back(new Tiles(posX3, posY, CanteroMed));

        float posX4 = vect.back()->getShape().getPosition().x + ANCHO_BARRERA;
        vect.push_back(new Tiles(posX4, posY, CanteroDer));


        for (unsigned int i = 1; i <= 4; i++)
        {
            float posX5 = vect.back()->getShape().getPosition().x + ANCHO_BARRERA;
            vect.push_back(new Tiles(posX5, posY, Asfalto1));

        }
    }
}

void Mapa::crearCalle(std::vector<Tiles*>& vect, Vector2u tamanioVentana, float posY)
{
    if (vect.empty())
    {
        vect.push_back(new Tiles(0.0f, posY, Asfalto2));
    } else {
        vect.push_back(new Tiles(vect.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, Asfalto2));
    }

    while (vect.back()->getShape().getPosition().x < tamanioVentana.x)
    {
        vect.push_back(new Tiles(vect.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, Asfalto2));
    }
}

void Mapa::draw(RenderWindow& ventanaCruzARG)
{
    for(Tiles* veredaCerrito: this->veredaCerrito)
        veredaCerrito->draw(ventanaCruzARG);

    for(Tiles* callCerrito: this->calleCerrito)
        callCerrito->draw(ventanaCruzARG);

    for(Tiles* cantero1: this->canteroVector1)
        cantero1->draw(ventanaCruzARG);

    for(Tiles* nueveAuto1: this->nueveAutos1)
        nueveAuto1->draw(ventanaCruzARG);

    for(Tiles* calleJersey1: this->calleBarrera1)
        calleJersey1->draw(ventanaCruzARG);

    for(Tiles* nueveColectivo1: this->nueveColectivos1)
        nueveColectivo1->draw(ventanaCruzARG);

    for(Tiles* metrobus : this->metrobusVector)
        metrobus->draw(ventanaCruzARG);

    for(Tiles* nueveColectivo2: this->nueveColectivos2)
        nueveColectivo2->draw(ventanaCruzARG);

    for(Tiles* calleJersey2: this->calleBarrera2)
        calleJersey2->draw(ventanaCruzARG);

    for(Tiles* nueveAuto2: this->nueveAutos2)
        nueveAuto2->draw(ventanaCruzARG);

    for(Tiles* cantero2: this->canteroVector2)
        cantero2->draw(ventanaCruzARG);

    for(Tiles* callPellegrini: this->callePellegrini)
        callPellegrini->draw(ventanaCruzARG);

    for(Tiles* veredaPellegrini: this->veredaPellegrini)
        veredaPellegrini->draw(ventanaCruzARG);
}
