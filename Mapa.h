#ifndef MAPA_H
#define MAPA_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "DEFINITIONS.h"
#include "Tiles.h"

using namespace sf;

class Mapa
{
    private:
        float carriles, veredaCerrito1, veredaCerrito2, cerrito, cantero1, nueveJulioAutos1, newJersey1, nueveJulioColectivos1, metrobus, nueveJulioColectivos2, newJersey2, nueveJulioAutos2, cantero2, carlosPellegrini, veredaPellegrini1, veredaPellegrini2;
        Vector2u tamanioVentana;
        std::vector<Tiles*> veredaCerrito;
        std::vector<Tiles*> calleCerrito;
        std::vector<Tiles*> canteroVector1;
        std::vector<Tiles*> nueveAutos1;
        std::vector<Tiles*> calleBarrera1;
        std::vector<Tiles*> nueveColectivos1;
        std::vector<Tiles*> metrobusVector;
        std::vector<Tiles*> nueveColectivos2;
        std::vector<Tiles*> calleBarrera2;
        std::vector<Tiles*> nueveAutos2;
        std::vector<Tiles*> canteroVector2;
        std::vector<Tiles*> callePellegrini;
        std::vector<Tiles*> veredaPellegrini;

    public:
        Mapa(Vector2u tamVentana);
        ~Mapa();
        void crearMetrobus(Vector2u tamVentana, float posY);
        void crearCerrito(Vector2u tamVentana, float posY, float posY2);
        void crearPellegrini(Vector2u tamVentana, float posY, float posY2);
        void crearCantero(std::vector<Tiles*>& vect, Vector2u tamVentana, float posY);
        void crearCalle(std::vector<Tiles*>& vect, Vector2u tamVentana, float posY);


        void draw(RenderWindow& window);
};

#endif // MAPA_H
