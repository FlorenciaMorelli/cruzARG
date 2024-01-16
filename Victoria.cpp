#include "Victoria.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include "PantallaDeJuego.h"

using namespace sf;

Victoria::Victoria(RenderWindow& ventanaCruzARG)
{
    this->ventanaVictoria = &ventanaCruzARG;

    if(!fuenteTitulo.loadFromFile("./assets/fonts/fuenteTitulo.ttf")){
        ventanaCruzARG.close();
    }

    if(!fuenteTexto.loadFromFile("./assets/fonts/fuenteTexto.ttf")){
        ventanaCruzARG.close();
    }


    tituloVictoria.setFont(fuenteTitulo);
    tituloVictoria.setString("Ganaste, campeon del mundo");
    tituloVictoria.setOrigin(tituloVictoria.getLocalBounds().width / 2, tituloVictoria.getLocalBounds().height / 2);
    tituloVictoria.setPosition(ventanaCruzARG.getSize().x / 2.0, ventanaCruzARG.getSize().y / 2 - 200.0f);
//    tituloVictoria.setCharacterSize(72);

    nuevaPartida.setFont(fuenteTexto);
    nuevaPartida.setString("Nueva partida");
    nuevaPartida.setColor(Color::Yellow);
    nuevaPartida.setOrigin(nuevaPartida.getLocalBounds().width / 2, nuevaPartida.getLocalBounds().height / 2);
    nuevaPartida.setPosition(ventanaCruzARG.getSize().x / 2.0, tituloVictoria.getPosition().y + 350.0f);
    nuevaPartida.setCharacterSize(30);

    salirDelJuego.setFont(fuenteTexto);
    salirDelJuego.setString("Salir");
    salirDelJuego.setColor(Color::White);
    salirDelJuego.setOrigin(salirDelJuego.getLocalBounds().width / 2, salirDelJuego.getLocalBounds().height / 2);
    salirDelJuego.setPosition(ventanaCruzARG.getSize().x / 2.0, nuevaPartida.getPosition().y + 50.0f);
    salirDelJuego.setCharacterSize(30);
}

void Victoria::ganador(RenderWindow& ventanaCruzARG) {
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
                    if(Keyboard::isKeyPressed(Keyboard::Escape)){
                        ventanaCruzARG.close();
                    } else if (Keyboard::isKeyPressed(Keyboard::Enter)){
                        if(opcionSeleccionada == IniciarPartida){
                            ventanaCruzARG.clear(Color(150, 150, 150));
                            PantallaDeJuego juego(*this->ventanaVictoria);
                            juego.loop(*this->ventanaVictoria);
                        } else {
                            ventanaCruzARG.close();
                        }
                    } else if (Keyboard::isKeyPressed(Keyboard::Down)){
                        if (opcionSeleccionada == IniciarPartida){
                            nuevaPartida.setFillColor(Color::White);
                            salirDelJuego.setFillColor(Color::Yellow);
                            opcionSeleccionada = SalirDelJuego;
                        } else {
                            nuevaPartida.setFillColor(Color::Yellow);
                            salirDelJuego.setFillColor(Color::White);
                            opcionSeleccionada = IniciarPartida;
                        }
                    } else if (Keyboard::isKeyPressed(Keyboard::Up)){
                        if (opcionSeleccionada == IniciarPartida){
                            nuevaPartida.setFillColor(Color::White);
                            salirDelJuego.setFillColor(Color::Yellow);
                            opcionSeleccionada = SalirDelJuego;
                        } else {
                            nuevaPartida.setFillColor(Color::Yellow);
                            salirDelJuego.setFillColor(Color::White);
                            opcionSeleccionada = IniciarPartida;
                        }
                    }
                    break;
            }
        }

        ventanaCruzARG.clear(Color(150, 150, 150)); // Color gris para el fondo de la ventanaCruzARG

        // Dibujar elementos en el menú
        ventanaCruzARG.draw(tituloVictoria);
        ventanaCruzARG.draw(nuevaPartida);
        ventanaCruzARG.draw(salirDelJuego);

        ventanaCruzARG.display(); // Mostrar
    }
}
