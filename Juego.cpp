#include "Juego.h"
#include "MainMenu.h"

Juego::Juego()
{
    this->ventanaCruzARG = new RenderWindow(VideoMode::getDesktopMode(), TITULO_JUEGO, Style::Close | Style::Fullscreen);

    MainMenu menu(*ventanaCruzARG);
    menu.mostrarMenu(*ventanaCruzARG);
}
