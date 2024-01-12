#ifndef INSTRUCCCIONES_H
#define INSTRUCCCIONES_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Instruccciones
{
    private:
        RenderWindow *ventanaInstrucciones;
        Font fuenteTitulo;
        Font fuenteTexto;
        Text tituloInstrucciones;
        Text controles;
        Text objetivo;
        Text volver;


    public:
        Instruccciones(RenderWindow& ventanaCruzARG);

        void mostrar(RenderWindow& ventanaCruzARG);
};

#endif // INSTRUCCCIONES_H
