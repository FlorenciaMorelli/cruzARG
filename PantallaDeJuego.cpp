#include "PantallaDeJuego.h"

#include <vector>
#include "DEFINITIONS.h"

#include "Tiles.h"
#include "Mapa.h"

using namespace sf;

PantallaDeJuego::PantallaDeJuego()
{
    this->window = new RenderWindow(VideoMode::getDesktopMode(), TITULO_JUEGO, Style::Close | Style::Fullscreen);
    this->personaje = new Personaje(window->getSize());
    this->nueveDeJulio = new Mapa(window->getSize());

    float carriles =  window->getSize().y / 14.0f;
    float veredaCerrito1 = carriles * 0.0f;
    float veredaCerrito2 = carriles * 1.0f;
    float cerrito = carriles * 2.0f;
    float cantero1 = carriles * 3.0f;
    float nueveJulioAutos1 = carriles * 4.0f;
    float newJersey1 = carriles * 5.0f;
    float nueveJulioColectivos1 = carriles * 6.0f;
    float metrobus = carriles * 7.0f;
    float nueveJulioColectivos2 = carriles * 8.0f;
    float newJersey2 = carriles * 9.0f;
    float nueveJulioAutos2 = carriles * 10.0f;
    float cantero2 = carriles * 11.0f;
    float carlosPellegrini = carriles * 12.0f;
    float veredaPellegrini1 = carriles * 13.0f;
    float veredaPellegrini2 = carriles * 14.0f;

    this->traficoCerrito = new Trafico(1, window->getSize().x, cerrito, false);
    this->traficoNueveJulioAutos1 = new Trafico(1, window->getSize().x, nueveJulioAutos1, false);
    this->barrera1 = new BarreraJersey(window->getSize().x, 0.0, newJersey1);
    this->traficoNueveJulioColectivos1 = new Trafico(2, window->getSize().x, nueveJulioColectivos1, true);
    this->traficoNueveJulioColectivos2 = new Trafico(2, window->getSize().x, nueveJulioColectivos2, false);
    this->barrera2 = new BarreraJersey(window->getSize().x, 0.0, newJersey2);
    this->traficoNueveJulioAutos2 = new Trafico(1, window->getSize().x, nueveJulioAutos2, true);
    this->traficoCarlosPellegrini = new Trafico(1, window->getSize().x, carlosPellegrini, true);

    Image image;
    image.loadFromFile("./assets/icon.png");
    window->setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

}

void PantallaDeJuego::loop()
{
    while (window->isOpen()) //Mientras que la ventana est� abierta
    {
        Event evnt;
        while (window->pollEvent(evnt))
        {
            switch(evnt.type)
            {
                case Event::Closed: //Si se toca para cerrar
                    window->close(); //Cerrar
                    break;
                case Event::KeyPressed:
                    if(Keyboard::isKeyPressed(Keyboard::Escape))
                    {
                        window->close();
                    }
                    break;
                case Event::KeyReleased:
                    personaje->move(evnt, window->getSize());
            }
        }

        //Esto pasa en todos los frames

        traficoCerrito->move(window->getSize());
        traficoNueveJulioAutos1->move(window->getSize());
        traficoNueveJulioColectivos1->move(window->getSize());
        traficoNueveJulioColectivos2->move(window->getSize());
        traficoNueveJulioAutos2->move(window->getSize());
        traficoCarlosPellegrini->move(window->getSize());


        traficoCerrito->checkCollision(personaje, *window);
        traficoNueveJulioAutos1->checkCollision(personaje, *window);
        barrera1->checkCollision(personaje, *window);
        traficoNueveJulioColectivos1->checkCollision(personaje, *window);
        traficoNueveJulioColectivos2->checkCollision(personaje, *window);
        barrera2->checkCollision(personaje, *window);
        traficoNueveJulioAutos2->checkCollision(personaje, *window);
        traficoCarlosPellegrini->checkCollision(personaje, *window);


        window->clear(Color(150, 150, 150)); //Color gris para el fondo de la ventana

        nueveDeJulio->draw(*window);
        personaje->draw(*window);

        traficoCerrito->draw(*window);
        traficoNueveJulioAutos1->draw(*window);
        barrera1->draw(*window);
        traficoNueveJulioColectivos1->draw(*window);
        traficoNueveJulioColectivos2->draw(*window);
        barrera2->draw(*window);
        traficoNueveJulioAutos2->draw(*window);
        traficoCarlosPellegrini->draw(*window);

        window->display(); //Mostrar
    }
}
