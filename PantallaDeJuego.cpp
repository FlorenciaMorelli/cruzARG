#include "PantallaDeJuego.h"

#include <vector>
#include "DEFINITIONS.h"

#include "Tiles.h"
#include "Mapa.h"


using namespace sf;

PantallaDeJuego::PantallaDeJuego(RenderWindow& ventanaCruzARG)
{
    this->personaje = new Personaje(ventanaCruzARG.getSize());
    this->nueveDeJulio = new Mapa(ventanaCruzARG.getSize());
    this->matecito = new Mate(ventanaCruzARG.getSize());
    temporizador.restart();

    float carriles =  ventanaCruzARG.getSize().y / 14.0f;
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

    this->traficoCerrito = new Trafico(1, ventanaCruzARG.getSize().x, cerrito, false);
    this->traficoNueveJulioAutos1 = new Trafico(1, ventanaCruzARG.getSize().x, nueveJulioAutos1, false);
    this->barrera1 = new BarreraJersey(ventanaCruzARG.getSize().x, 0.0, newJersey1);
    this->traficoNueveJulioColectivos1 = new Trafico(2, ventanaCruzARG.getSize().x, nueveJulioColectivos1, true);
    this->traficoNueveJulioColectivos2 = new Trafico(2, ventanaCruzARG.getSize().x, nueveJulioColectivos2, false);
    this->barrera2 = new BarreraJersey(ventanaCruzARG.getSize().x, 0.0, newJersey2);
    this->traficoNueveJulioAutos2 = new Trafico(1, ventanaCruzARG.getSize().x, nueveJulioAutos2, true);
    this->traficoCarlosPellegrini = new Trafico(1, ventanaCruzARG.getSize().x, carlosPellegrini, true);


    if(!fuenteTexto.loadFromFile("./assets/fonts/fuenteTexto.ttf")){
        ventanaCruzARG.close();
    }
    temporizadorTexto.setFont(fuenteTexto);
    temporizadorTexto.setCharacterSize(30);
    temporizadorTexto.setFillColor(sf::Color::White);
    temporizadorTexto.setPosition(10.0f, 10.0f);

    Image image;
    image.loadFromFile("./assets/icon.png");
    ventanaCruzARG.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

}

void PantallaDeJuego::loop(RenderWindow& ventanaCruzARG)
{
    while (ventanaCruzARG.isOpen()) //Mientras que la ventanaCruzARG est� abierta
    {
        Event evnt;
        while (ventanaCruzARG.pollEvent(evnt))
        {
            switch(evnt.type)
            {
                case Event::Closed: //Si se toca para cerrar
                    ventanaCruzARG.close(); //Cerrar
                    break;
                case Event::KeyPressed:
                    if(Keyboard::isKeyPressed(Keyboard::Escape))
                    {
                        ventanaCruzARG.close();
                    }
                    break;
                case Event::KeyReleased:
                    if(!barrera1->checkCollision(personaje, ventanaCruzARG) && !barrera2->checkCollision(personaje, ventanaCruzARG)){
                        personaje->move(evnt, ventanaCruzARG.getSize());
                    } else {
                        personaje->push(evnt);
                    }
            }
        }

        //Esto pasa en todos los frames

        Time tiempoTranscurrido = temporizador.getElapsedTime();
        int segundosRestantes = tiempoLimite - tiempoTranscurrido.asSeconds();

        if(segundosRestantes <= 0){
            Derrota perdiste(ventanaCruzARG);
            perdiste.derrotado(ventanaCruzARG);

            temporizador.restart();
        }

        temporizadorTexto.setString("Tiempo: " + std::to_string(segundosRestantes) + "s");


        traficoCerrito->move(ventanaCruzARG.getSize());
        traficoNueveJulioAutos1->move(ventanaCruzARG.getSize());
        traficoNueveJulioColectivos1->move(ventanaCruzARG.getSize());
        traficoNueveJulioColectivos2->move(ventanaCruzARG.getSize());
        traficoNueveJulioAutos2->move(ventanaCruzARG.getSize());
        traficoCarlosPellegrini->move(ventanaCruzARG.getSize());


        traficoCerrito->checkCollision(personaje, ventanaCruzARG);
        traficoNueveJulioAutos1->checkCollision(personaje, ventanaCruzARG);
        traficoNueveJulioColectivos1->checkCollision(personaje, ventanaCruzARG);
        traficoNueveJulioColectivos2->checkCollision(personaje, ventanaCruzARG);
        traficoNueveJulioAutos2->checkCollision(personaje, ventanaCruzARG);
        traficoCarlosPellegrini->checkCollision(personaje, ventanaCruzARG);

        matecito->tomado(personaje, ventanaCruzARG);


        ventanaCruzARG.clear(Color(150, 150, 150)); //Color gris para el fondo de la ventanaCruzARG

        nueveDeJulio->draw(ventanaCruzARG);

        traficoCerrito->draw(ventanaCruzARG);
        traficoNueveJulioAutos1->draw(ventanaCruzARG);
        barrera1->draw(ventanaCruzARG);
        traficoNueveJulioColectivos1->draw(ventanaCruzARG);
        traficoNueveJulioColectivos2->draw(ventanaCruzARG);
        barrera2->draw(ventanaCruzARG);
        traficoNueveJulioAutos2->draw(ventanaCruzARG);
        traficoCarlosPellegrini->draw(ventanaCruzARG);

        matecito->draw(ventanaCruzARG);

        personaje->draw(ventanaCruzARG);

        ventanaCruzARG.draw(temporizadorTexto);

        ventanaCruzARG.display(); //Mostrar
    }
}
