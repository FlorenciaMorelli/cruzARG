#include "Instruccciones.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"

using namespace sf;

Instruccciones::Instruccciones(RenderWindow& ventanaCruzARG)
{
    this->ventanaInstrucciones = &ventanaCruzARG;

    if(!fuenteTitulo.loadFromFile("./assets/fonts/fuenteTitulo.ttf")){
        ventanaCruzARG.close();
    }

    if(!fuenteTexto.loadFromFile("./assets/fonts/fuenteTexto.ttf")){
        ventanaCruzARG.close();
    }


    tituloInstrucciones.setFont(fuenteTitulo);
    tituloInstrucciones.setString("Instrucciones");
    tituloInstrucciones.setOrigin(tituloInstrucciones.getLocalBounds().width / 2, tituloInstrucciones.getLocalBounds().height / 2);
    tituloInstrucciones.setPosition(ventanaCruzARG.getSize().x / 2.0, ventanaCruzARG.getSize().y / 2 - 300.0f);
//    tituloInstrucciones.setCharacterSize(72);

    controles.setFont(fuenteTexto);
    controles.setString("Nuestro Chaboncito se mueve con las flechas de desplazamiento\nde tu teclado");
    controles.setColor(Color::Black);
    controles.setOrigin(controles.getLocalBounds().width / 2, 0.0);
    controles.setPosition(ventanaCruzARG.getSize().x / 2.0, tituloInstrucciones.getPosition().y + 100.0f);
    controles.setCharacterSize(30);

    objetivo.setFont(fuenteTexto);
    objetivo.setString("CruzARG es un juego de tipo arcade\nfuertemente influenciado por nuestras costumbres argentinas,\ndonde nuestro (campeón) personaje porteño enfrenta\nel desafío de cruzar la alborotada Avenida 9 de Julio\nsorteando típicos obstáculos como autos, colectivos, taxis,\nparadas del MetroBus®, valiéndose de sus destrezas.\n ¡Demostrá tu habilidad esquivando el tráfico porteño\ny alcanza la gloria de cruzar la avenida\nsin que te lleven puesto!");
    objetivo.setColor(Color::Black);
    objetivo.setOrigin(objetivo.getLocalBounds().width / 2, 0.0);
    objetivo.setPosition(ventanaCruzARG.getSize().x / 2.0, controles.getPosition().y + 100.0f);
    objetivo.setCharacterSize(30);

    volver.setFont(fuenteTexto);
    volver.setString("Volver");
    volver.setColor(Color::Yellow);
    volver.setOrigin(volver.getLocalBounds().width / 2, 0.0);
    volver.setPosition(ventanaCruzARG.getSize().x / 2.0, controles.getPosition().y + objetivo.getGlobalBounds().getSize().y + 250.0f);
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
                case Event::Closed: //Si se toca para cerrar
                    ventanaCruzARG.close(); //Cerrar
                    break;
                case Event::KeyPressed: // Cerrar con ESC
                    if(Keyboard::isKeyPressed(Keyboard::Escape) || Keyboard::isKeyPressed(Keyboard::Enter)){
                        ventanaCruzARG.clear(Color(150, 150, 150));
                        MainMenu menu(ventanaCruzARG);
                        menu.mostrarMenu(ventanaCruzARG);
                    }
                    break;
            }
        }

        ventanaCruzARG.clear(Color(150, 150, 150)); // Color gris para el fondo de la ventanaCruzARG

        // Dibujar elementos en el menú
        ventanaCruzARG.draw(tituloInstrucciones);
        ventanaCruzARG.draw(controles);
        ventanaCruzARG.draw(objetivo);
        ventanaCruzARG.draw(volver);

        ventanaCruzARG.display(); // Mostrar
    }
}
