#include "Instruccciones.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"

using namespace sf;

Instruccciones::Instruccciones(RenderWindow& ventanaCruzARG)
{
    this->ventanaInstrucciones = &ventanaCruzARG;

    backgroundT.loadFromFile("./assets/instrucciones.png");
    background.setTexture(backgroundT);
    background.setOrigin(background.getLocalBounds().width / 2.0, background.getLocalBounds().height / 2.0);
    background.setPosition(ventanaCruzARG.getSize().x / 2.0, ventanaCruzARG.getSize().y / 2.0);

    this->textColor = new Color(132, 53, 17);

    if(!fuenteTexto.loadFromFile("./assets/fonts/fuenteTexto.ttf")){
        ventanaCruzARG.close();
    }

    volver.setFont(fuenteTexto);
    volver.setString("Volver");
    volver.setColor(*textColor);
    volver.setOrigin(volver.getLocalBounds().width / 2, 0.0);
    volver.setPosition(ventanaCruzARG.getSize().x / 2.0, ventanaCruzARG.getSize().y - 100.0);
    volver.setCharacterSize(30);
}

void Instruccciones::mostrar(RenderWindow& ventanaCruzARG)
{
    if (!ventanaCruzARG.isOpen()) {
        return;
    }

    while (ventanaCruzARG.isOpen()) {
        Event evnt;
        while (ventanaCruzARG.pollEvent(evnt)) {
            switch(evnt.type) {
                case Event::Closed:
                    ventanaCruzARG.close();
                    break;
                case Event::KeyPressed:
                    if(Keyboard::isKeyPressed(Keyboard::Escape) || Keyboard::isKeyPressed(Keyboard::Enter)){
                        ventanaCruzARG.clear(Color(150, 150, 150));
                        MainMenu menu(ventanaCruzARG);
                        menu.mostrarMenu(ventanaCruzARG);
                    }
                    break;
            }
        }

        ventanaCruzARG.clear(Color(150, 150, 150));
        ventanaCruzARG.draw(background);
        ventanaCruzARG.draw(volver);

        ventanaCruzARG.display();
    }
}
