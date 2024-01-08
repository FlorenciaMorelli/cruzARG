#include "Juego.h"
#include "DEFINITIONS.h"


using namespace sf;

Juego::Juego()
{
    this->window = new RenderWindow(VideoMode::getDesktopMode(), TITULO_JUEGO, Style::Close | Style::Fullscreen);
    this->personaje = new Personaje(window->getSize());

    float carriles =  window->getSize().y / 14.0f;
    float veredaCerrito = carriles * 1.0f;
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


    this->taxi = new Taxi(-ANCHO_TAXI, cerrito, true);
    this->taxi2 = new Taxi(taxi->getPosOriginalX() - SEPARACION_ENTRE_VEHICULOS, cerrito, true);
    this->taxi3 = new Taxi(taxi2->getPosOriginalX() - SEPARACION_ENTRE_VEHICULOS, carlosPellegrini, false);
    this->taxi4 = new Taxi(taxi3->getPosOriginalX() - SEPARACION_PARA_PERSONAJE, nueveJulioAutos1, true);
    this->taxi5 = new Taxi(taxi4->getPosOriginalX() - SEPARACION_ENTRE_VEHICULOS, nueveJulioAutos2, false);

    this->autito = new Auto(window->getSize().x, nueveJulioAutos1, true);
    this->autito2 = new Auto(autito->getPosOriginalX() - SEPARACION_ENTRE_VEHICULOS, nueveJulioAutos2, false);
    this->autito3 = new Auto(autito2->getPosOriginalX() - SEPARACION_PARA_PERSONAJE, nueveJulioAutos1, true);
    this->autito4 = new Auto(autito3->getPosOriginalX() - SEPARACION_ENTRE_VEHICULOS, carlosPellegrini, false);
    this->autito5 = new Auto(autito4->getPosOriginalX() - SEPARACION_ENTRE_VEHICULOS, cerrito, true);
    this->autito6 = new Auto(autito5->getPosOriginalX() - SEPARACION_PARA_PERSONAJE, nueveJulioAutos2, false);


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
                    personaje->move(evnt, window->getSize());
            }
        }

        //Esto pasa en todos los frames

        taxi->move(window->getSize());
        taxi2->move(window->getSize());
        taxi3->move(window->getSize());
        taxi4->move(window->getSize());
        taxi5->move(window->getSize());


        autito->move(window->getSize());
        autito2->move(window->getSize());
        autito3->move(window->getSize());
        autito4->move(window->getSize());
        autito5->move(window->getSize());
        autito6->move(window->getSize());




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

        if(personaje->getShape().getGlobalBounds().intersects(autito2->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(autito3->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(autito4->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(autito5->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(autito6->getShape().getGlobalBounds()))
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

        autito6->draw(*window);
        autito->draw(*window);
        autito2->draw(*window);
        autito3->draw(*window);
        autito4->draw(*window);
        autito5->draw(*window);



        window->display(); //Mostrar
    }
}
