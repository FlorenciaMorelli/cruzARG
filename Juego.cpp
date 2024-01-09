#include "Juego.h"
#include "DEFINITIONS.h"
#include <vector>
#include "Tiles.h"


using namespace sf;

Juego::Juego()
{
    this->window = new RenderWindow(VideoMode::getDesktopMode(), TITULO_JUEGO, Style::Close | Style::Fullscreen);
    this->personaje = new Personaje(window->getSize());

    this->carriles =  window->getSize().y / 14.0f;
    this->veredaCerrito1 = carriles * 0.0f;
    this->veredaCerrito2 = carriles * 1.0f;
    this->cerrito = carriles * 2.0f;
    this->cantero1 = carriles * 3.0f;
    this->nueveJulioAutos1 = carriles * 4.0f;
    this->newJersey1 = carriles * 5.0f;
    this->nueveJulioColectivos1 = carriles * 6.0f;
    this->metrobus = carriles * 7.0f;
    this->nueveJulioColectivos2 = carriles * 8.0f;
    this->newJersey2 = carriles * 9.0f;
    this->nueveJulioAutos2 = carriles * 10.0f;
    this->cantero2 = carriles * 11.0f;
    this->carlosPellegrini = carriles * 12.0f;
    this->veredaPellegrini1 = carriles * 13.0f;
    this->veredaPellegrini2 = carriles * 14.0f;


    //Vereda Cerrito
    crearCerrito(window->getSize(), this->veredaCerrito2, this->veredaCerrito1);

    // ← Cerrito
    this->taxi = new Taxi(window->getSize().x + ANCHO_TAXI, cerrito, false);
    this->taxi2 = new Taxi(taxi->getPosOriginalX() + SEPARACION_ENTRE_VEHICULOS, cerrito, false);
    this->autito = new Auto(taxi2->getPosOriginalX() + SEPARACION_ENTRE_VEHICULOS, cerrito, false);

    // Cantero
    crearCantero(this->canteroVector1, window->getSize(), cantero1);

    // ← 9 de Julio (autos)
    this->autito2 = new Auto(window->getSize().x + ANCHO_AUTO, nueveJulioAutos1, false);
    this->taxi3 = new Taxi(autito2->getPosOriginalX() + SEPARACION_PARA_PERSONAJE, nueveJulioAutos1, false);
    this->autito3 = new Auto(taxi3->getPosOriginalX() + SEPARACION_PARA_PERSONAJE, nueveJulioAutos1, false);

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


    // Metrobus
    crearMetrobus(window->getSize(), this->metrobus);


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
    this->autito4 = new Auto(-ANCHO_AUTO, nueveJulioAutos2, true);
    this->autito5 = new Auto(autito4->getPosOriginalX() - SEPARACION_PARA_PERSONAJE, nueveJulioAutos2, true);
    this->taxi4 = new Taxi(autito5->getPosOriginalX() - SEPARACION_ENTRE_VEHICULOS, nueveJulioAutos2, true);

    // Cantero
    crearCantero(this->canteroVector2, window->getSize(), cantero2);

    // → Carlos Pellegrini
    this->taxi5 = new Taxi(-ANCHO_TAXI, carlosPellegrini, true);
    this->autito6 = new Auto(taxi5->getPosOriginalX() - SEPARACION_ENTRE_VEHICULOS, carlosPellegrini, true);

    //Vereda Pellegrini
    crearPellegrini(window->getSize(), this->veredaPellegrini1, this->veredaPellegrini2);

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
        for(Tiles* metrobus : metrobusVector)
            metrobus->draw(*window);

        for(Tiles* vereda: calleCerrito)
            vereda->draw(*window);

        for(Tiles* vereda: pellegriniVereda)
            vereda->draw(*window);

        for(Tiles* cantero: canteroVector1)
            cantero->draw(*window);

        for(Tiles* cantero: canteroVector2)
            cantero->draw(*window);



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
void Juego::crearMetrobus(Vector2u tamanioVentana, float posY)
{
    if (metrobusVector.empty())
    {
        this->metrobusVector.push_back(new Tiles(0.0f, posY, 11));
    } else {
        this->metrobusVector.push_back(new Tiles(metrobusVector.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, 11));
    }

    while (metrobusVector.back()->getShape().getPosition().x < tamanioVentana.x)
    {
        this->metrobusVector.push_back(new Tiles(metrobusVector.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, 11));

        if (metrobusVector.size() % 4 == 0)
        {
            for(unsigned int i = 1; i <= 4; i++)
            {
                this->metrobusVector.push_back(new Tiles(metrobusVector.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, 1));
            }
        }
    }
}

void Juego::crearCerrito(Vector2u tamanioVentana, float posY, float posY2)
{
    if (calleCerrito.empty())
    {
        this->calleCerrito.push_back(new Tiles(0.0f, posY, 8));
        this->calleCerrito.push_back(new Tiles(0.0f, posY2, 5));

    }

    while (calleCerrito.back()->getShape().getPosition().x < tamanioVentana.x)
    {
        if (calleCerrito.size() > 2)
        {
            float posX = calleCerrito.back()->getShape().getPosition().x + ANCHO_BARRERA;
            this->calleCerrito.push_back(new Tiles(posX, posY, 8));
            this->calleCerrito.push_back(new Tiles(posX, posY2, 5));
        }

        float posX8 = calleCerrito.back()->getShape().getPosition().x + ANCHO_BARRERA;
        this->calleCerrito.push_back(new Tiles(posX8, posY, 9));
        this->calleCerrito.push_back(new Tiles(posX8, posY2, 6));

        float posX9 = calleCerrito.back()->getShape().getPosition().x + ANCHO_BARRERA;
        this->calleCerrito.push_back(new Tiles(posX9, posY, 9));
        this->calleCerrito.push_back(new Tiles(posX9, posY2, 6));

        float posX10 = calleCerrito.back()->getShape().getPosition().x + ANCHO_BARRERA;
        this->calleCerrito.push_back(new Tiles(posX10, posY, 10));
        this->calleCerrito.push_back(new Tiles(posX10, posY2, 7));


        for (unsigned int i = 1; i <= 4; i++)
        {
            float posX11 = calleCerrito.back()->getShape().getPosition().x + ANCHO_BARRERA;
            this->calleCerrito.push_back(new Tiles(posX11, posY, 1));
            this->calleCerrito.push_back(new Tiles(posX11, posY2, 1));

        }
    }
}

void Juego::crearPellegrini(Vector2u tamanioVentana, float posY, float posY2)
{
    if (pellegriniVereda.empty())
    {
        this->pellegriniVereda.push_back(new Tiles(0.0f, posY, 2));
        this->pellegriniVereda.push_back(new Tiles(0.0f, posY2, 5));

    }

    while (pellegriniVereda.back()->getShape().getPosition().x < tamanioVentana.x)
    {
        if (pellegriniVereda.size() > 2)
        {
            float posX = pellegriniVereda.back()->getShape().getPosition().x + ANCHO_BARRERA;
            this->pellegriniVereda.push_back(new Tiles(posX, posY, 2));
            this->pellegriniVereda.push_back(new Tiles(posX, posY2, 5));
        }

        float posX8 = pellegriniVereda.back()->getShape().getPosition().x + ANCHO_BARRERA;
        this->pellegriniVereda.push_back(new Tiles(posX8, posY, 3));
        this->pellegriniVereda.push_back(new Tiles(posX8, posY2, 6));

        float posX9 = pellegriniVereda.back()->getShape().getPosition().x + ANCHO_BARRERA;
        this->pellegriniVereda.push_back(new Tiles(posX9, posY, 3));
        this->pellegriniVereda.push_back(new Tiles(posX9, posY2, 6));

        float posX10 = pellegriniVereda.back()->getShape().getPosition().x + ANCHO_BARRERA;
        this->pellegriniVereda.push_back(new Tiles(posX10, posY, 4));
        this->pellegriniVereda.push_back(new Tiles(posX10, posY2, 7));


        for (unsigned int i = 1; i <= 4; i++)
        {
            float posX11 = pellegriniVereda.back()->getShape().getPosition().x + ANCHO_BARRERA;
            this->pellegriniVereda.push_back(new Tiles(posX11, posY, 1));
            this->pellegriniVereda.push_back(new Tiles(posX11, posY2, 1));

        }
    }
}

void Juego::crearCantero(std::vector<Tiles*>& vect, Vector2u tamanioVentana, float posY)
{
    if (vect.empty())
    {
        vect.push_back(new Tiles(0.0f, posY, 12));
    } else {
        vect.push_back(new Tiles(vect.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, 12));
    }

    while (vect.back()->getShape().getPosition().x < tamanioVentana.x)
    {
        vect.push_back(new Tiles(vect.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, 12));

        if (vect.size() % 4 == 0)
        {
            for(unsigned int i = 1; i <= 4; i++)
            {
                vect.push_back(new Tiles(vect.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, 1));
            }
        }
    }
}

