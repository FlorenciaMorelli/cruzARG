#include <SFML/Graphics.hpp>
#include <iostream>
#include "Personaje.h"

using namespace sf;

int main()
{
    //Ventana general
    RenderWindow window(VideoMode(960, 540), "CruzARG", Style::Close);
    Personaje chaboncito(window.getSize());

    RectangleShape taxi;

    taxi.setSize(Vector2f(90.0f, 60.0f));
    taxi.setFillColor(Color::Yellow);
    taxi.setPosition(Vector2f(taxi.getPosition().x, window.getSize().y / 2.0f - taxi.getSize().y));

    //Ícono de la ventana
    Image image;
    image.loadFromFile("./assets/icon.png");
    window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

    while (window.isOpen()) //Mientras que la ventana esté abierta
    {
        Event evnt;
        while (window.pollEvent(evnt))
        {
            switch(evnt.type)
            {
                case Event::Closed: //Si se toca para cerrar
                    window.close(); //Cerrar
                    break;
                case Event::KeyReleased:
                    chaboncito.move(evnt);
            }
        }

        //Esto pasa en todos los frames
        taxi.move(0.2f, 0.0f);

        if(taxi.getPosition().x > window.getSize().x) //Si el taxi está fuera de la ventana
        {
            taxi.setPosition(Vector2f(-taxi.getSize().x, window.getSize().y / 2.0f - taxi.getSize().y)); //Reaparece en el x = 0, manteniendo la posición de y
        }

        if(chaboncito.getShape().getGlobalBounds().intersects(taxi.getGlobalBounds()))
            window.close();

        window.clear(Color(150, 150, 150)); //Color gris para el fondo de la ventana

        chaboncito.draw(window);
        window.draw(taxi);


        window.display(); //Mostrar
    }

    return 0;
}
