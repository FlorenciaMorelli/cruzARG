#include "MainMenu.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include "PantallaDeJuego.h"
#include "Instruccciones.h"


using namespace sf;

MainMenu::MainMenu(RenderWindow& ventanaCruzARG)
{
    this->ventanaMenu = &ventanaCruzARG;

    if(!fuenteTitulo.loadFromFile("./assets/fonts/fuenteTitulo.ttf")){
        ventanaCruzARG.close();
    }

    if(!fuenteTexto.loadFromFile("./assets/fonts/fuenteTexto.ttf")){
        ventanaCruzARG.close();
    }


    tituloJuego.setFont(fuenteTitulo);
    tituloJuego.setString("CruzARG");
    tituloJuego.setOrigin(tituloJuego.getLocalBounds().width / 2, tituloJuego.getLocalBounds().height / 2);
    tituloJuego.setPosition(ventanaCruzARG.getSize().x / 2.0, ventanaCruzARG.getSize().y / 2 - 200.0f);
//    tituloJuego.setCharacterSize(72);

    iniciarPartida.setFont(fuenteTexto);
    iniciarPartida.setString("Iniciar Partida");
    iniciarPartida.setColor(Color::Yellow);
    iniciarPartida.setOrigin(iniciarPartida.getLocalBounds().width / 2, iniciarPartida.getLocalBounds().height / 2);
    iniciarPartida.setPosition(ventanaCruzARG.getSize().x / 2.0, tituloJuego.getPosition().y + 350.0f);
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
                        ventanaCruzARG.close();
                    } else if (Keyboard::isKeyPressed(Keyboard::Enter)){
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
                        if (opcionSeleccionada == IniciarPartida){
                            iniciarPartida.setFillColor(Color::White);
                            comoJugar.setFillColor(Color::Yellow);
                            salirDelJuego.setFillColor(Color::White);
                            opcionSeleccionada = ComoJugar;
                        } else if (opcionSeleccionada == ComoJugar){
                            iniciarPartida.setFillColor(Color::White);
                            comoJugar.setFillColor(Color::White);
                            salirDelJuego.setFillColor(Color::Yellow);
                            opcionSeleccionada = SalirDelJuego;
                        } else {
                            iniciarPartida.setFillColor(Color::Yellow);
                            comoJugar.setFillColor(Color::White);
                            salirDelJuego.setFillColor(Color::White);
                            opcionSeleccionada = IniciarPartida;
                        }
                    } else if (Keyboard::isKeyPressed(Keyboard::Up)){
                        if (opcionSeleccionada == IniciarPartida){
                            iniciarPartida.setFillColor(Color::White);
                            comoJugar.setFillColor(Color::White);
                            salirDelJuego.setFillColor(Color::Yellow);
                            opcionSeleccionada = SalirDelJuego;
                        } else if (opcionSeleccionada == ComoJugar){
                            iniciarPartida.setFillColor(Color::Yellow);
                            comoJugar.setFillColor(Color::White);
                            salirDelJuego.setFillColor(Color::White);
                            opcionSeleccionada = IniciarPartida;
                        } else {
                            iniciarPartida.setFillColor(Color::White);
                            comoJugar.setFillColor(Color::Yellow);
                            salirDelJuego.setFillColor(Color::White);
                            opcionSeleccionada = ComoJugar;
                        }
                    }
                    break;
            }
        }

        ventanaCruzARG.clear(Color(150, 150, 150)); // Color gris para el fondo de la ventanaCruzARG

        // Dibujar elementos en el menú
        ventanaCruzARG.draw(tituloJuego);
        ventanaCruzARG.draw(iniciarPartida);
        ventanaCruzARG.draw(comoJugar);
        ventanaCruzARG.draw(salirDelJuego);

        ventanaCruzARG.display(); // Mostrar
    }
}
