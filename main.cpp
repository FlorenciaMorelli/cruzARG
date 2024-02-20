#include "tau/tau.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINITIONS.h"
#include "Juego.h"
#include "Personaje.h"
#include "Mate.h"
#include "Trafico.h"


using namespace sf;
using namespace std;


TAU_MAIN()

TEST(CruzARG, Victoria) {
    Juego juego;
    RenderWindow ventanaTest;

    Personaje personaje(ventanaTest.getSize());
    Mate mate(ventanaTest.getSize());

    personaje.setPosicion(100.0f, 100.0f);
    mate.setPosicion(100.0f, 100.0f);

    CHECK(mate.tomado(&personaje, ventanaTest) == true, "Falla mate.tomado()");

    personaje.setPosicion(0.0, 100.0);
    mate.setPosicion(100.0, 0.0);

    CHECK(mate.tomado(&personaje, ventanaTest) == false, "Falla mate.tomado()");
}

TEST(CruzARG, MovimientoDelPersonaje) {
    Vector2u tamanioVentana(800, 600);
    Personaje personaje(tamanioVentana);

    Event eventoArriba, eventoAbajo, eventoIzquierda, eventoDerecha;
    eventoArriba.key.code = Keyboard::Key::Up;
    eventoAbajo.key.code = Keyboard::Key::Down;
    eventoIzquierda.key.code = Keyboard::Key::Left;
    eventoDerecha.key.code = Keyboard::Key::Right;

    personaje.setPosicion(100.0f, 100.0f);
    personaje.move(eventoArriba, tamanioVentana);
    CHECK(personaje.getShape().getPosition().x == 100.0f && personaje.getShape().getPosition().y == 100.0f - PERSONAJE_CANT_MOVIMIENTO, "Falla al mover el personaje hacia arriba");

    personaje.setPosicion(100.0f, 100.0f);
    personaje.move(eventoAbajo, tamanioVentana);
    CHECK(personaje.getShape().getPosition().x == 100.0f && personaje.getShape().getPosition().y == 100.0f + PERSONAJE_CANT_MOVIMIENTO, "Falla al mover el personaje hacia abajo");

    personaje.setPosicion(100.0f, 100.0f);
    personaje.move(eventoDerecha, tamanioVentana);
    CHECK(personaje.getShape().getPosition().x == 100.0f + PERSONAJE_CANT_MOVIMIENTO && personaje.getShape().getPosition().y == 100.0f, "Falla al mover el personaje hacia la derecha");

    personaje.setPosicion(100.0f, 100.0f);
    personaje.move(eventoIzquierda, tamanioVentana);
    CHECK(personaje.getShape().getPosition().x == 100.0f - PERSONAJE_CANT_MOVIMIENTO && personaje.getShape().getPosition().y == 100.0f, "Falla al mover el personaje hacia la izquierda");
}

TEST(CruzARG, Derrota) {
    RenderWindow ventanaTest;
    Personaje personaje(ventanaTest.getSize());
    Trafico trafico(2, ventanaTest.getSize().x, 100.0f, true);

    personaje.setPosicion(100.0, 100.0);
    CHECK(trafico.checkCollision(&personaje, ventanaTest) == false, "Falla checkCollision()");


    personaje.setPosicion(50.0, 50.0);
    CHECK(trafico.checkCollision(&personaje, ventanaTest) == false, "Falla checkCollision()");
}
