#include "Juego.h"
#include "DEFINITIONS.h"


using namespace sf;

Juego::Juego()
{
    this->window = new RenderWindow(VideoMode(ANCHO_VENTANA, ALTURA_VENTANA), TITULO_JUEGO, Style::Close);
    this->personaje = new Personaje(window->getSize());
    this->taxi = new Taxi(-ANCHO_TAXI, window->getSize().y / 2);
    this->taxi2 = new Taxi(taxi->getPosOriginalX() - SEPARACION_ENTRE_TAXIS, window->getSize().y / 2);
    this->taxi3 = new Taxi(taxi2->getPosOriginalX() - SEPARACION_ENTRE_TAXIS, window->getSize().y / 2);
    this->taxi4 = new Taxi(taxi3->getPosOriginalX() - SEPARACION_PARA_PERSONAJE, window->getSize().y / 2);
    this->taxi5 = new Taxi(taxi4->getPosOriginalX() - SEPARACION_ENTRE_TAXIS, window->getSize().y / 2);

    this->autito = new Auto(window->getSize().x, window->getSize().y / 4);



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
        taxi2->move(window->getSize());
        taxi3->move(window->getSize());
        taxi4->move(window->getSize());
        taxi5->move(window->getSize());


        autito->move();





        if(personaje->getShape().getGlobalBounds().intersects(taxi->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(taxi2->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(taxi3->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(taxi4->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(taxi5->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(autito->getShape().getGlobalBounds()))
        {
            window->close();
        }




        window->clear(Color(150, 150, 150)); //Color gris para el fondo de la ventana

        personaje->draw(*window);
        taxi5->draw(*window);
        taxi4->draw(*window);
        taxi3->draw(*window);
        taxi2->draw(*window);
        taxi->draw(*window);

        autito->draw(*window);




        window->display(); //Mostrar
    }
}
