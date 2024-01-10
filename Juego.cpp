#include "Juego.h"
#include "DEFINITIONS.h"
#include <vector>
#include "Tiles.h"
#include "Mapa.h"


using namespace sf;

Juego::Juego()
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

    // ← Cerrito
    this->traficoCerrito = new Trafico(window->getSize().x, cerrito, false);
    this->traficoNueveJulioAutos1 = new Trafico(window->getSize().x, nueveJulioAutos1, false);

    //Barrera Jersey1
    this->barrera = new BarreraJersey(0.0f, newJersey1);
    this->barrera2 = new BarreraJersey(barrera->getShape().getPosition().x + ANCHO_BARRERA, newJersey1);
    this->barrera3 = new BarreraJersey(barrera2->getShape().getPosition().x + ANCHO_BARRERA, newJersey1);
    this->barrera4 = new BarreraJersey(barrera3->getShape().getPosition().x + ANCHO_BARRERA, newJersey1);

    this->asfalto = new Tiles(barrera4->getShape().getPosition().x + ANCHO_BARRERA, newJersey1, 1);
    this->asfalto2 = new Tiles(asfalto->getShape().getPosition().x + ANCHO_BARRERA, newJersey1, 1);
    this->asfalto3 = new Tiles(asfalto2->getShape().getPosition().x + ANCHO_BARRERA, newJersey1, 1);
    this->asfalto4 = new Tiles(asfalto3->getShape().getPosition().x + ANCHO_BARRERA, newJersey1, 1);

    this->barrera5 = new BarreraJersey(barrera4->getShape().getPosition().x + ESPACIO_ENTRE_CUADRAS, newJersey1);
    this->barrera6 = new BarreraJersey(barrera5->getShape().getPosition().x + ANCHO_BARRERA, newJersey1);
    this->barrera7 = new BarreraJersey(barrera6->getShape().getPosition().x + ANCHO_BARRERA, newJersey1);
    this->barrera8 = new BarreraJersey(barrera7->getShape().getPosition().x + ANCHO_BARRERA, newJersey1);

    this->asfalto5 = new Tiles(barrera8->getShape().getPosition().x + ANCHO_BARRERA, newJersey1, 1);
    this->asfalto6 = new Tiles(asfalto5->getShape().getPosition().x + ANCHO_BARRERA, newJersey1, 1);
    this->asfalto7 = new Tiles(asfalto6->getShape().getPosition().x + ANCHO_BARRERA, newJersey1, 1);
    this->asfalto8 = new Tiles(asfalto7->getShape().getPosition().x + ANCHO_BARRERA, newJersey1, 1);

    this->barrera9 = new BarreraJersey(barrera8->getShape().getPosition().x + ESPACIO_ENTRE_CUADRAS, newJersey1);
    this->barrera10 = new BarreraJersey(barrera9->getShape().getPosition().x + ANCHO_BARRERA, newJersey1);
    this->barrera11 = new BarreraJersey(barrera10->getShape().getPosition().x + ANCHO_BARRERA, newJersey1);
    this->barrera12 = new BarreraJersey(barrera11->getShape().getPosition().x + ANCHO_BARRERA, newJersey1);

    this->asfalto9 = new Tiles(barrera12->getShape().getPosition().x + ANCHO_BARRERA, newJersey1, 1);
    this->asfalto10 = new Tiles(asfalto9->getShape().getPosition().x + ANCHO_BARRERA, newJersey1, 1);
    this->asfalto11 = new Tiles(asfalto10->getShape().getPosition().x + ANCHO_BARRERA, newJersey1, 1);
    this->asfalto12 = new Tiles(asfalto11->getShape().getPosition().x + ANCHO_BARRERA, newJersey1, 1);

    // → 9 de Julio (colectivos)


    // ← 9 de Julio (colectivos)


    //Barrera Jersey2
    this->barrera13 = new BarreraJersey(0.0f, newJersey2);
    this->barrera14 = new BarreraJersey(barrera13->getShape().getPosition().x + ANCHO_BARRERA, newJersey2);
    this->barrera15 = new BarreraJersey(barrera14->getShape().getPosition().x + ANCHO_BARRERA, newJersey2);
    this->barrera16 = new BarreraJersey(barrera15->getShape().getPosition().x + ANCHO_BARRERA, newJersey2);

    this->asfalto13 = new Tiles(barrera16->getShape().getPosition().x + ANCHO_BARRERA, newJersey2, 1);
    this->asfalto14 = new Tiles(asfalto13->getShape().getPosition().x + ANCHO_BARRERA, newJersey2, 1);
    this->asfalto15 = new Tiles(asfalto14->getShape().getPosition().x + ANCHO_BARRERA, newJersey2, 1);
    this->asfalto16 = new Tiles(asfalto15->getShape().getPosition().x + ANCHO_BARRERA, newJersey2, 1);

    this->barrera17 = new BarreraJersey(barrera16->getShape().getPosition().x + ESPACIO_ENTRE_CUADRAS, newJersey2);
    this->barrera18 = new BarreraJersey(barrera17->getShape().getPosition().x + ANCHO_BARRERA, newJersey2);
    this->barrera19 = new BarreraJersey(barrera18->getShape().getPosition().x + ANCHO_BARRERA, newJersey2);
    this->barrera20 = new BarreraJersey(barrera19->getShape().getPosition().x + ANCHO_BARRERA, newJersey2);

    this->asfalto17 = new Tiles(barrera20->getShape().getPosition().x + ANCHO_BARRERA, newJersey2, 1);
    this->asfalto18 = new Tiles(asfalto17->getShape().getPosition().x + ANCHO_BARRERA, newJersey2, 1);
    this->asfalto19 = new Tiles(asfalto18->getShape().getPosition().x + ANCHO_BARRERA, newJersey2, 1);
    this->asfalto20 = new Tiles(asfalto19->getShape().getPosition().x + ANCHO_BARRERA, newJersey2, 1);

    this->barrera21 = new BarreraJersey(barrera20->getShape().getPosition().x + ESPACIO_ENTRE_CUADRAS, newJersey2);
    this->barrera22 = new BarreraJersey(barrera21->getShape().getPosition().x + ANCHO_BARRERA, newJersey2);
    this->barrera23 = new BarreraJersey(barrera22->getShape().getPosition().x + ANCHO_BARRERA, newJersey2);
    this->barrera24 = new BarreraJersey(barrera23->getShape().getPosition().x + ANCHO_BARRERA, newJersey2);

    this->asfalto21 = new Tiles(barrera24->getShape().getPosition().x + ANCHO_BARRERA, newJersey2, 1);
    this->asfalto22 = new Tiles(asfalto21->getShape().getPosition().x + ANCHO_BARRERA, newJersey2, 1);
    this->asfalto23 = new Tiles(asfalto22->getShape().getPosition().x + ANCHO_BARRERA, newJersey2, 1);
    this->asfalto24 = new Tiles(asfalto23->getShape().getPosition().x + ANCHO_BARRERA, newJersey2, 1);

    // → 9 de Julio (autos)
    this->traficoNueveJulioAutos2 = new Trafico(window->getSize().x, nueveJulioAutos2, true);

    // → Carlos Pellegrini
    this->traficoCarlosPellegrini = new Trafico(window->getSize().x, carlosPellegrini, true);


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
        traficoNueveJulioAutos2->move(window->getSize());
        traficoCarlosPellegrini->move(window->getSize());


        traficoCerrito->checkCollision(personaje, *window);
        traficoNueveJulioAutos1->checkCollision(personaje, *window);
        traficoNueveJulioAutos2->checkCollision(personaje, *window);
        traficoCarlosPellegrini->checkCollision(personaje, *window);


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

        nueveDeJulio->draw(*window);


        asfalto->draw(*window);
        asfalto2->draw(*window);
        asfalto3->draw(*window);
        asfalto4->draw(*window);
        asfalto5->draw(*window);
        asfalto6->draw(*window);
        asfalto7->draw(*window);
        asfalto8->draw(*window);
        asfalto9->draw(*window);
        asfalto10->draw(*window);
        asfalto11->draw(*window);
        asfalto12->draw(*window);
        asfalto13->draw(*window);
        asfalto14->draw(*window);
        asfalto15->draw(*window);
        asfalto16->draw(*window);
        asfalto17->draw(*window);
        asfalto18->draw(*window);
        asfalto19->draw(*window);
        asfalto20->draw(*window);
        asfalto21->draw(*window);
        asfalto22->draw(*window);
        asfalto23->draw(*window);
        asfalto24->draw(*window);


        personaje->draw(*window);

        traficoCerrito->draw(*window);
        traficoNueveJulioAutos1->draw(*window);
        traficoNueveJulioAutos2->draw(*window);
        traficoCarlosPellegrini->draw(*window);


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


