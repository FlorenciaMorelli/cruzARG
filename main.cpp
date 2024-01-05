#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //Ventana general
    sf::RenderWindow window(sf::VideoMode(960, 540), "CruzARG", sf::Style::Close);

    //Ícono de la ventana
    sf::Image image;
    image.loadFromFile("./assets/icon.png");
    window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

    while (window.isOpen()) //Mientras que la ventana esté abierta
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch(evnt.type)
            {
                case sf::Event::Closed: //Si se toca para cerrar
                    window.close(); //Cerrar
                    break;
            }
        }

        window.clear(sf::Color(150, 150, 150)); //Color gris para el fondo de la ventana

        window.display(); //Mostrar
    }

    return 0;
}
