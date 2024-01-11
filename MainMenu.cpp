#include "MainMenu.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include "PantallaDeJuego.h"

using namespace sf;

MainMenu::MainMenu()
{
    if(!fuenteTitulo.loadFromFile("./assets/fonts/fuenteTitulo.ttf")){
        this->ventanaMenu->close();
    }

    if(!fuenteTexto.loadFromFile("./assets/fonts/fuenteTexto.ttf")){
        this->ventanaMenu->close();
    }

    this->ventanaMenu = new RenderWindow(VideoMode::getDesktopMode(), TITULO_JUEGO, Style::Close | Style::Fullscreen);

    tituloJuego.setFont(fuenteTitulo);
    tituloJuego.setString("CruzARG");
    tituloJuego.setOrigin(tituloJuego.getLocalBounds().width / 2, tituloJuego.getLocalBounds().height / 2);
    tituloJuego.setPosition(ventanaMenu->getSize().x / 2.0, ventanaMenu->getSize().y / 2 - 200.0f);
//    tituloJuego.setCharacterSize(72);

    iniciarPartida.setFont(fuenteTexto);
    iniciarPartida.setString("Iniciar Partida");
    iniciarPartida.setColor(Color::Black);
    iniciarPartida.setOrigin(iniciarPartida.getLocalBounds().width / 2, iniciarPartida.getLocalBounds().height / 2);
    iniciarPartida.setPosition(ventanaMenu->getSize().x / 2.0, tituloJuego.getPosition().y + 350.0f);
    iniciarPartida.setCharacterSize(30);

    salirDelJuego.setFont(fuenteTexto);
    salirDelJuego.setString("Salir");
    salirDelJuego.setColor(Color::Black);
    salirDelJuego.setOrigin(salirDelJuego.getLocalBounds().width / 2, tituloJuego.getLocalBounds().height / 2);
    salirDelJuego.setPosition(ventanaMenu->getSize().x / 2.0, iniciarPartida.getPosition().y + 50.0f);
    salirDelJuego.setCharacterSize(30);
}

void MainMenu::mostrarMenu() {
    if (!ventanaMenu->isOpen()) {
        return;
    }

    while (ventanaMenu->isOpen()) {
        Event evnt;
        while (ventanaMenu->pollEvent(evnt)) {
            switch(evnt.type) {
                case Event::Closed: //Si se toca para cerrar
                    ventanaMenu->close(); //Cerrar
                    break;
                case Event::KeyPressed: // Cerrar con ESC
                    if(Keyboard::isKeyPressed(Keyboard::Escape))
                    {
                        ventanaMenu->close();
                    }
                    break;
                case Event::MouseMoved: //Chequeamos el hover
                    if (iniciarPartida.getGlobalBounds().contains(evnt.mouseMove.x, evnt.mouseMove.y)) {
                        iniciarPartida.setFillColor(Color::Yellow);
                    } else {
                        iniciarPartida.setFillColor(Color::White);
                    }
                    if (salirDelJuego.getGlobalBounds().contains(evnt.mouseMove.x, evnt.mouseMove.y)) {
                        salirDelJuego.setFillColor(Color::Yellow);
                    } else {
                        salirDelJuego.setFillColor(Color::White);
                    }
                    break;
                case Event::MouseButtonPressed: // Evento de click. Iniciar partida o salir del juego
                    if (evnt.mouseButton.button == Mouse::Left) {
                        if (iniciarPartida.getGlobalBounds().contains(evnt.mouseButton.x, evnt.mouseButton.y)) {
                            PantallaDeJuego juego;
                            juego.loop();
                        } else if (salirDelJuego.getGlobalBounds().contains(evnt.mouseButton.x, evnt.mouseButton.y)) {
                            ventanaMenu->close();
                        }
                    }
                    break;
            }
        }

        ventanaMenu->clear(Color(150, 150, 150)); // Color gris para el fondo de la ventana

        // Dibujar elementos en el menú
        ventanaMenu->draw(tituloJuego);
        ventanaMenu->draw(iniciarPartida);
        ventanaMenu->draw(salirDelJuego);

        ventanaMenu->display(); // Mostrar
    }
}
