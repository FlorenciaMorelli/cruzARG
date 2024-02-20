#include "Victoria.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include "PantallaDeJuego.h"

using namespace sf;

Victoria::Victoria(RenderWindow& ventanaCruzARG)
{
    this->ventanaVictoria = &ventanaCruzARG;

    backgroundT.loadFromFile("./assets/ventanaGanador.png");
    background.setTexture(backgroundT);
    background.setOrigin(background.getLocalBounds().width / 2.0, background.getLocalBounds().height / 2.0);
    background.setPosition(ventanaCruzARG.getSize().x / 2.0, ventanaCruzARG.getSize().y / 2.0);

    this->buffer.loadFromFile("./assets/sounds/win.wav");
    this->winSound.setBuffer(buffer);


    this->textColor = new Color(132, 53, 17);

    if(!fuenteTexto.loadFromFile("./assets/fonts/fuenteTexto.ttf")){
        ventanaCruzARG.close();
    }

    nuevaPartida.setFont(fuenteTexto);
    nuevaPartida.setString("Nueva partida");
    nuevaPartida.setColor(*textColor);
    nuevaPartida.setOrigin(nuevaPartida.getLocalBounds().width / 2, nuevaPartida.getLocalBounds().height / 2);
    nuevaPartida.setPosition(ventanaCruzARG.getSize().x / 2.0, ventanaCruzARG.getSize().y / 2.0 - 120.0);
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
                case Event::Closed:
                    ventanaCruzARG.close();
                    break;
                case Event::KeyPressed:
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
                            salirDelJuego.setFillColor(*textColor);
                            opcionSeleccionada = SalirDelJuego;
                        } else {
                            nuevaPartida.setFillColor(*textColor);
                            salirDelJuego.setFillColor(Color::White);
                            opcionSeleccionada = IniciarPartida;
                        }
                    } else if (Keyboard::isKeyPressed(Keyboard::Up)){
                        if (opcionSeleccionada == IniciarPartida){
                            nuevaPartida.setFillColor(Color::White);
                            salirDelJuego.setFillColor(*textColor);
                            opcionSeleccionada = SalirDelJuego;
                        } else {
                            nuevaPartida.setFillColor(*textColor);
                            salirDelJuego.setFillColor(Color::White);
                            opcionSeleccionada = IniciarPartida;
                        }
                    }
                    break;
            }
        }

        ventanaCruzARG.clear(Color(150, 150, 150));

        winSound.play();
        ventanaCruzARG.draw(background);
        ventanaCruzARG.draw(nuevaPartida);
        ventanaCruzARG.draw(salirDelJuego);

        ventanaCruzARG.display();
    }
}
