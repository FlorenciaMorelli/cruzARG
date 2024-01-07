#include "Juego.h"
#include "DEFINITIONS.h"


using namespace sf;

Juego::Juego()
{
    this->window = new RenderWindow(VideoMode(ANCHO_VENTANA, ALTURA_VENTANA), TITULO_JUEGO, Style::Close);
    this->personaje = new Personaje(window->getSize());
    this->taxi = new Taxi(0.0, window->getSize().y / 2);

    Image image;
    image.loadFromFile("./assets/icon.png");
    window->setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

}

Juego::~Juego()
{
    //dtor
}

void Juego::loop()
{
    while (window->isOpen()) //Mientras que la ventana esté abierta
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
                    personaje->move(evnt);
            }
        }

        //Esto pasa en todos los frames

        taxi->move(window->getSize());


        if(personaje->getShape().getGlobalBounds().intersects(taxi->getShape().getGlobalBounds()))
        {
            window->close();
        }

        window->clear(Color(150, 150, 150)); //Color gris para el fondo de la ventana

        personaje->draw(*window);
        taxi->draw(*window);



        window->display(); //Mostrar
    }
}
