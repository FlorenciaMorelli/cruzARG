#include "Derrota.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "PantallaDeJuego.h"

using namespace sf;

Derrota::Derrota(RenderWindow& ventanaCruzARG)
{
    this->ventanaDerrota = &ventanaCruzARG;

    backgroundT.loadFromFile("./assets/ventanaPerdedor.png");
    background.setTexture(backgroundT);
    background.setOrigin(background.getLocalBounds().width / 2.0, background.getLocalBounds().height / 2.0);
    background.setPosition(ventanaCruzARG.getSize().x / 2.0, ventanaCruzARG.getSize().y / 2.0);

    this->bufferArrow.loadFromFile("./assets/sounds/moveArrow.wav");
    this->arrowPressed.setBuffer(bufferArrow);

    this->buffer.loadFromFile("./assets/sounds/loose.wav");
    this->defeatSound.setBuffer(buffer);

    this->defeatSound.play();

    this->textColor = new Color(132, 53, 17);

    if(!fuenteTexto.loadFromFile("./assets/fonts/fuenteTexto.ttf")){
        ventanaCruzARG.close();
    }

    volverAJugar.setFont(fuenteTexto);
    volverAJugar.setString("Volver a jugar");
    volverAJugar.setColor(*textColor);
    volverAJugar.setOrigin(volverAJugar.getLocalBounds().width / 2, volverAJugar.getLocalBounds().height / 2);
    volverAJugar.setPosition(ventanaCruzARG.getSize().x / 2.0, ventanaCruzARG.getSize().y / 2.0);
    volverAJugar.setCharacterSize(30);

    salirDelJuego.setFont(fuenteTexto);
    salirDelJuego.setString("Salir");
    salirDelJuego.setColor(Color::White);
    salirDelJuego.setOrigin(salirDelJuego.getLocalBounds().width / 2, salirDelJuego.getLocalBounds().height / 2);
    salirDelJuego.setPosition(ventanaCruzARG.getSize().x / 2.0, volverAJugar.getPosition().y + 50.0f);
    salirDelJuego.setCharacterSize(30);
}

void Derrota::derrotado(RenderWindow& ventanaCruzARG) {
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
                        arrowPressed.play();
                        ventanaCruzARG.close();
                    } else if (Keyboard::isKeyPressed(Keyboard::Enter)){
                        arrowPressed.play();
                        if(opcionSeleccionada == IniciarPartida){
                            ventanaCruzARG.clear(Color(150, 150, 150));
                            PantallaDeJuego juego(*this->ventanaDerrota);
                            juego.loop(*this->ventanaDerrota);
                        } else {
                            ventanaCruzARG.close();
                        }
                    } else if (Keyboard::isKeyPressed(Keyboard::Down)){
                        arrowPressed.play();
                        if (opcionSeleccionada == IniciarPartida){
                            volverAJugar.setFillColor(Color::White);
                            salirDelJuego.setFillColor(*textColor);
                            opcionSeleccionada = SalirDelJuego;
                        } else {
                            volverAJugar.setFillColor(*textColor);
                            salirDelJuego.setFillColor(Color::White);
                            opcionSeleccionada = IniciarPartida;
                        }
                    } else if (Keyboard::isKeyPressed(Keyboard::Up)){
                        arrowPressed.play();
                        if (opcionSeleccionada == IniciarPartida){
                            volverAJugar.setFillColor(Color::White);
                            salirDelJuego.setFillColor(*textColor);
                            opcionSeleccionada = SalirDelJuego;
                        } else {
                            volverAJugar.setFillColor(*textColor);
                            salirDelJuego.setFillColor(Color::White);
                            opcionSeleccionada = IniciarPartida;
                        }
                    }
                    break;
            }
        }

        ventanaCruzARG.clear(Color(150, 150, 150));
        defeatSound.play();
        ventanaCruzARG.draw(background);
        ventanaCruzARG.draw(volverAJugar);
        ventanaCruzARG.draw(salirDelJuego);

        ventanaCruzARG.display();
    }
}
