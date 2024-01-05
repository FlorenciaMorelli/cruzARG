#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main()
{
    //Ventana general
    RenderWindow window(VideoMode(960, 540), "CruzARG", Style::Close);
    RectangleShape chaboncito;

    chaboncito.setSize(Vector2f(50.0f, 50.0f));
    //chaboncito.setOrigin(Vector2f(chaboncito.getSize().x / 2.0f, chaboncito.getSize().y / 2.0f));
    chaboncito.setPosition(Vector2f(window.getSize().x / 2.0f, window.getSize().y - chaboncito.getSize().y));

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
                case Event::KeyPressed:
                    if(Keyboard::Key::Up == evnt.key.code)
                        chaboncito.move(0.0f, -50.0f);
                    if(Keyboard::Key::Down == evnt.key.code)
                        chaboncito.move(0.0f, 50.0f);
                    if(Keyboard::Key::Left == evnt.key.code)
                        chaboncito.move(-50.0f, 0.0f);
                    if(Keyboard::Key::Right == evnt.key.code)
                        chaboncito.move(50.0f, 0.0f);


                    break;
            }
        }

        //Esto pasa en todos los frames
        taxi.move(0.2f, 0.0f);

        if(taxi.getPosition().x > window.getSize().x) //Si el taxi está fuera de la ventana
        {
            taxi.setPosition(Vector2f(-taxi.getSize().x, window.getSize().y / 2.0f - taxi.getSize().y)); //Reaparece en el x = 0, manteniendo la posición de y
        }

        window.clear(Color(150, 150, 150)); //Color gris para el fondo de la ventana
        window.draw(chaboncito);
        window.draw(taxi);


        window.display(); //Mostrar
    }

    return 0;
}
