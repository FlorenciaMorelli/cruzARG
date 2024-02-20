#ifndef INSTRUCCCIONES_H
#define INSTRUCCCIONES_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Instruccciones
{
    private:
        RenderWindow *ventanaInstrucciones;
        Texture backgroundT;
        Font fuenteTexto;
        Color *textColor;
        Sprite background;
        Text volver;


    public:
        Instruccciones(RenderWindow& ventanaCruzARG);

        void mostrar(RenderWindow& ventanaCruzARG);
};

#endif // INSTRUCCCIONES_H
