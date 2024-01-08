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

    this->barrera = new BarreraJersey(0.0f, newJersey1);
    this->barrera2 = new BarreraJersey(barrera->getShape().getPosition().x + ANCHO_BARRERA, newJersey1);
    this->barrera3 = new BarreraJersey(barrera2->getShape().getPosition().x + ANCHO_BARRERA, newJersey1);
    this->barrera4 = new BarreraJersey(barrera3->getShape().getPosition().x + ANCHO_BARRERA, newJersey1);
    this->barrera5 = new BarreraJersey(barrera4->getShape().getPosition().x + ESPACIO_ENTRE_CUADRAS, newJersey1);
    this->barrera6 = new BarreraJersey(barrera5->getShape().getPosition().x + ANCHO_BARRERA, newJersey1);
    this->barrera7 = new BarreraJersey(barrera6->getShape().getPosition().x + ANCHO_BARRERA, newJersey1);
    this->barrera8 = new BarreraJersey(barrera7->getShape().getPosition().x + ANCHO_BARRERA, newJersey1);
    this->barrera9 = new BarreraJersey(barrera8->getShape().getPosition().x + ESPACIO_ENTRE_CUADRAS, newJersey1);
    this->barrera10 = new BarreraJersey(barrera9->getShape().getPosition().x + ANCHO_BARRERA, newJersey1);
    this->barrera11 = new BarreraJersey(barrera10->getShape().getPosition().x + ANCHO_BARRERA, newJersey1);
    this->barrera12 = new BarreraJersey(barrera11->getShape().getPosition().x + ANCHO_BARRERA, newJersey1);
    this->barrera13 = new BarreraJersey(0.0f, newJersey2);
    this->barrera14 = new BarreraJersey(barrera13->getShape().getPosition().x + ANCHO_BARRERA, newJersey2);
    this->barrera15 = new BarreraJersey(barrera14->getShape().getPosition().x + ANCHO_BARRERA, newJersey2);
    this->barrera16 = new BarreraJersey(barrera15->getShape().getPosition().x + ANCHO_BARRERA, newJersey2);
    this->barrera17 = new BarreraJersey(barrera16->getShape().getPosition().x + ESPACIO_ENTRE_CUADRAS, newJersey2);
    this->barrera18 = new BarreraJersey(barrera17->getShape().getPosition().x + ANCHO_BARRERA, newJersey2);
    this->barrera19 = new BarreraJersey(barrera18->getShape().getPosition().x + ANCHO_BARRERA, newJersey2);
    this->barrera20 = new BarreraJersey(barrera19->getShape().getPosition().x + ANCHO_BARRERA, newJersey2);
    this->barrera21 = new BarreraJersey(barrera20->getShape().getPosition().x + ESPACIO_ENTRE_CUADRAS, newJersey2);
    this->barrera22 = new BarreraJersey(barrera21->getShape().getPosition().x + ANCHO_BARRERA, newJersey2);
    this->barrera23 = new BarreraJersey(barrera22->getShape().getPosition().x + ANCHO_BARRERA, newJersey2);
    this->barrera24 = new BarreraJersey(barrera23->getShape().getPosition().x + ANCHO_BARRERA, newJersey2);




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


        if(personaje->getShape().getGlobalBounds().intersects(barrera->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera2->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera3->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera4->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera5->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera6->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera7->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera8->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera9->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera10->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera11->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera12->getShape().getGlobalBounds()))
        {
            window->close();
        }
        if(personaje->getShape().getGlobalBounds().intersects(barrera13->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera14->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera15->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera16->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera17->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera18->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera19->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera20->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera21->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera22->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera23->getShape().getGlobalBounds()))
        {
            window->close();
        }

        if(personaje->getShape().getGlobalBounds().intersects(barrera24->getShape().getGlobalBounds()))
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

        barrera->draw(*window);
        barrera2->draw(*window);
        barrera3->draw(*window);
        barrera4->draw(*window);
        barrera5->draw(*window);
        barrera6->draw(*window);
        barrera7->draw(*window);
        barrera8->draw(*window);
        barrera9->draw(*window);
        barrera10->draw(*window);
        barrera11->draw(*window);
        barrera12->draw(*window);
        barrera13->draw(*window);
        barrera14->draw(*window);
        barrera15->draw(*window);
        barrera16->draw(*window);
        barrera17->draw(*window);
        barrera18->draw(*window);
        barrera19->draw(*window);
        barrera20->draw(*window);
        barrera21->draw(*window);
        barrera22->draw(*window);
        barrera23->draw(*window);
        barrera24->draw(*window);




        window->display(); //Mostrar
    }
}
