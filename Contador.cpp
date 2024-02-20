#include "Contador.h"

using namespace sf;

Contador::Contador(Vector2u tamanioVentana) : temporizador()
{
    fuenteTexto.loadFromFile("./assets/fonts/fuenteTexto.ttf");
    temporizadorTexto.setFont(fuenteTexto);
    temporizadorTexto.setCharacterSize(30);
    temporizadorTexto.setFillColor(sf::Color::White);
    temporizadorTexto.setPosition(10.0f, tamanioVentana.y - 50.0f);
    temporizadorTexto.setOutlineColor(Color::Blue);
    temporizadorTexto.setOutlineThickness(3);
}

void Contador::cuentaRegresiva(RenderWindow& window)
{
    Time tiempoTranscurrido = temporizador.getElapsedTime();
    int segundosRestantes = tiempoLimite - tiempoTranscurrido.asSeconds();

    if(segundosRestantes <= 0){
        Derrota perdiste(window);
        perdiste.derrotado(window);

        temporizador.restart();
    }

    temporizadorTexto.setString("Tiempo: " + std::to_string(segundosRestantes) + "s");
}

void Contador::draw(RenderWindow& window) {
    window.draw(temporizadorTexto);
}
