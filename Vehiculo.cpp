#include "Vehiculo.h"

#include <SFML/Graphics.hpp>
#include "BaseObject.h"
#include "DEFINITIONS.h"

using namespace sf;

Vehiculo::Vehiculo(float posX, float Y, bool direccion)
{
    this->direccion = direccion;
}
