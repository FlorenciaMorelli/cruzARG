#include "MainMenu.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "PantallaDeJuego.h"
#include "Instruccciones.h"


using namespace sf;

MainMenu::MainMenu(RenderWindow& ventanaCruzARG)
{
    this->ventanaMenu = &ventanaCruzARG;

    backgroundT.loadFromFile("./assets/background.png");
    background.setTexture(backgroundT);
    background.setOrigin(background.getLocalBounds().width / 2.0, background.getLocalBounds().height / 2.0);
    background.setPosition(ventanaCruzARG.getSize().x / 2.0, ventanaCruzARG.getSize().y / 2.0);

    this->bufferArrow.loadFromFile("./assets/sounds/moveArrow.wav");
    this->arrowPressed.setBuffer(bufferArrow);

    this->textColor = new Color(132, 53, 17);

    if(!fuenteTexto.loadFromFile("./assets/fonts/fuenteTexto.ttf")){
        ventanaCruzARG.close();
    }

    iniciarPartida.setFont(fuenteTexto);
    iniciarPartida.setString("Iniciar Partida");
    iniciarPartida.setColor(*textColor);
    iniciarPartida.setOrigin(iniciarPartida.getLocalBounds().width / 2, iniciarPartida.getLocalBounds().height / 2);
    iniciarPartida.setPosition(ventanaCruzARG.getSize().x / 2.0, ventanaCruzARG.getSize().y / 2.0);
    iniciarPartida.setCharacterSize(30);

    comoJugar.setFont(fuenteTexto);
    comoJugar.setString("Cómo jugar");
    comoJugar.setColor(Color::White);
    comoJugar.setOrigin(comoJugar.getLocalBounds().width / 2, comoJugar.getLocalBounds().height / 2);
    comoJugar.setPosition(ventanaCruzARG.getSize().x / 2.0, iniciarPartida.getPosition().y + 50.0f);
    comoJugar.setCharacterSize(30);

    salirDelJuego.setFont(fuenteTexto);
    salirDelJuego.setString("Salir");
    salirDelJuego.setColor(Color::White);
    salirDelJuego.setOrigin(salirDelJuego.getLocalBounds().width / 2, salirDelJuego.getLocalBounds().height / 2);
    salirDelJuego.setPosition(ventanaCruzARG.getSize().x / 2.0, comoJugar.getPosition().y + 50.0f);
    salirDelJuego.setCharacterSize(30);
}

void MainMenu::mostrarMenu(RenderWindow& ventanaCruzARG) {
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
                        arrowPressed.play();
                        ventanaCruzARG.close();
                    } else if (Keyboard::isKeyPressed(Keyboard::Enter)){
                        arrowPressed.play();
                        if(opcionSeleccionada == IniciarPartida){
                            ventanaCruzARG.clear(Color(150, 150, 150));
                            PantallaDeJuego juego(*this->ventanaMenu);
                            juego.loop(*this->ventanaMenu);
                        } else if (opcionSeleccionada == ComoJugar){
                            Instruccciones instruc(*this->ventanaMenu);
                            instruc.mostrar(*this->ventanaMenu);
                        } else {
                            ventanaCruzARG.close();
                        }
                    } else if (Keyboard::isKeyPressed(Keyboard::Down)){
                        arrowPressed.play();
                        if (opcionSeleccionada == IniciarPartida){
                            iniciarPartida.setFillColor(Color::White);
                            comoJugar.setFillColor(*textColor);
                            salirDelJuego.setFillColor(Color::White);
                            opcionSeleccionada = ComoJugar;
                        } else if (opcionSeleccionada == ComoJugar){
                            iniciarPartida.setFillColor(Color::White);
                            comoJugar.setFillColor(Color::White);
                            salirDelJuego.setFillColor(*textColor);
                            opcionSeleccionada = SalirDelJuego;
                        } else {
                            iniciarPartida.setFillColor(*textColor);
                            comoJugar.setFillColor(Color::White);
                            salirDelJuego.setFillColor(Color::White);
                            opcionSeleccionada = IniciarPartida;
                        }
                    } else if (Keyboard::isKeyPressed(Keyboard::Up)){
                        arrowPressed.play();
                        if (opcionSeleccionada == IniciarPartida){
                            iniciarPartida.setFillColor(Color::White);
                            comoJugar.setFillColor(Color::White);
                            salirDelJuego.setFillColor(*textColor);
                            opcionSeleccionada = SalirDelJuego;
                        } else if (opcionSeleccionada == ComoJugar){
                            iniciarPartida.setFillColor(*textColor);
                            comoJugar.setFillColor(Color::White);
                            salirDelJuego.setFillColor(Color::White);
                            opcionSeleccionada = IniciarPartida;
                        } else {
                            iniciarPartida.setFillColor(Color::White);
                            comoJugar.setFillColor(*textColor);
                            salirDelJuego.setFillColor(Color::White);
                            opcionSeleccionada = ComoJugar;
                        }
                    }
                    break;
            }
        }

        ventanaCruzARG.clear(Color(150, 150, 150));
        ventanaCruzARG.draw(background);
        ventanaCruzARG.draw(iniciarPartida);
        ventanaCruzARG.draw(comoJugar);
        ventanaCruzARG.draw(salirDelJuego);

        ventanaCruzARG.display(); // Mostrar
    }
}
