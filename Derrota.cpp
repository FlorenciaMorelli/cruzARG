#include "Derrota.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include "PantallaDeJuego.h"

using namespace sf;

Derrota::Derrota(RenderWindow& ventanaCruzARG)
{
    this->ventanaDerrota = &ventanaCruzARG;

    if(!fuenteTitulo.loadFromFile("./assets/fonts/fuenteTitulo.ttf")){
        ventanaCruzARG.close();
    }

    if(!fuenteTexto.loadFromFile("./assets/fonts/fuenteTexto.ttf")){
        ventanaCruzARG.close();
    }


    tituloDerrota.setFont(fuenteTitulo);
    tituloDerrota.setString("Perdiste :(");
    tituloDerrota.setOrigin(tituloDerrota.getLocalBounds().width / 2, tituloDerrota.getLocalBounds().height / 2);
    tituloDerrota.setPosition(ventanaCruzARG.getSize().x / 2.0, ventanaCruzARG.getSize().y / 2 - 200.0f);
//    tituloJuego.setCharacterSize(72);

    volverAJugar.setFont(fuenteTexto);
    volverAJugar.setString("Volver a jugar");
    volverAJugar.setColor(Color::Yellow);
    volverAJugar.setOrigin(volverAJugar.getLocalBounds().width / 2, volverAJugar.getLocalBounds().height / 2);
    volverAJugar.setPosition(ventanaCruzARG.getSize().x / 2.0, tituloDerrota.getPosition().y + 350.0f);
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
                case Event::Closed: //Si se toca para cerrar
                    ventanaCruzARG.close(); //Cerrar
                    break;
                case Event::KeyPressed: // Cerrar con ESC
                    if(Keyboard::isKeyPressed(Keyboard::Escape)){
                        ventanaCruzARG.close();
                    } else if (Keyboard::isKeyPressed(Keyboard::Enter)){
                        if(opcionSeleccionada == IniciarPartida){
                            ventanaCruzARG.clear(Color(150, 150, 150));
                            PantallaDeJuego juego(*this->ventanaDerrota);
                            juego.loop(*this->ventanaDerrota);
                        } else {
                            ventanaCruzARG.close();
                        }
                    } else if (Keyboard::isKeyPressed(Keyboard::Down)){
                        if (opcionSeleccionada == IniciarPartida){
                            volverAJugar.setFillColor(Color::White);
                            salirDelJuego.setFillColor(Color::Yellow);
                            opcionSeleccionada = SalirDelJuego;
                        } else {
                            volverAJugar.setFillColor(Color::Yellow);
                            salirDelJuego.setFillColor(Color::White);
                            opcionSeleccionada = IniciarPartida;
                        }
                    } else if (Keyboard::isKeyPressed(Keyboard::Up)){
                        if (opcionSeleccionada == IniciarPartida){
                            volverAJugar.setFillColor(Color::White);
                            salirDelJuego.setFillColor(Color::Yellow);
                            opcionSeleccionada = SalirDelJuego;
                        } else {
                            volverAJugar.setFillColor(Color::Yellow);
                            salirDelJuego.setFillColor(Color::White);
                            opcionSeleccionada = IniciarPartida;
                        }
                    }
                    break;
            }
        }

        ventanaCruzARG.clear(Color(150, 150, 150)); // Color gris para el fondo de la ventanaCruzARG

        // Dibujar elementos en el menú
        ventanaCruzARG.draw(tituloDerrota);
        ventanaCruzARG.draw(volverAJugar);
        ventanaCruzARG.draw(salirDelJuego);

        ventanaCruzARG.display(); // Mostrar
    }
}
