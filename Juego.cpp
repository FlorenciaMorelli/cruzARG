#include "Juego.h"
#include "MainMenu.h"

#include <SFML/Audio.hpp>

Juego::Juego()
{
    this->ventanaCruzARG = new RenderWindow(VideoMode::getDesktopMode(), TITULO_JUEGO, Style::Close | Style::Fullscreen);

    this->backgroundMusic.openFromFile("./assets/sounds/music.mp3");
    this->backgroundMusic.setLoop(true);

    this->backgroundMusic.play();
    MainMenu menu(*ventanaCruzARG);
    menu.mostrarMenu(*ventanaCruzARG);

}

