#ifndef CONTADOR_H
#define CONTADOR_H

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.h"
#include "Derrota.h"

using namespace sf;

class Contador
{
    private:
        Clock temporizador;
        const int tiempoLimite = TIEMPO_LIMITE;
        Font fuenteTexto;
        Text temporizadorTexto;

    public:
        Contador(Vector2u tamanioVentana);

        void cuentaRegresiva(RenderWindow& window);
        void draw(RenderWindow& window);
};

#endif // CONTADOR_H
