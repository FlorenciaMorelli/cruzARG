#include <SFML/Graphics.hpp>
#include <iostream>
#include "Personaje.h"
#include "Taxi.h"

using namespace sf;

int main()
{
    //Ventana general
    RenderWindow window(VideoMode(960, 540), "CruzARG", Style::Close);
    Personaje chaboncito(window.getSize());
    Taxi taxi(0.0, window.getSize().y / 2);
    Taxi taxi2(0.0, window.getSize().y / 4);
    Taxi taxi3(0.0, 0.0);

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
                case Event::KeyPressed:
                    if(Keyboard::isKeyPressed(Keyboard::Escape))
                        window.close();
                    break;
                case Event::KeyReleased:
                    chaboncito.move(evnt);
            }
        }

        //Esto pasa en todos los frames

        taxi.move(window.getSize());
        taxi2.move(window.getSize());
        taxi3.move(window.getSize());


        if(chaboncito.getShape().getGlobalBounds().intersects(taxi.getShape().getGlobalBounds()))
            window.close();
        if(chaboncito.getShape().getGlobalBounds().intersects(taxi2.getShape().getGlobalBounds()))
            window.close();
        if(chaboncito.getShape().getGlobalBounds().intersects(taxi3.getShape().getGlobalBounds()))
            window.close();


        window.clear(Color(150, 150, 150)); //Color gris para el fondo de la ventana

        chaboncito.draw(window);
        taxi.draw(window);
        taxi2.draw(window);
        taxi3.draw(window);



        window.display(); //Mostrar
    }

    return 0;
}
