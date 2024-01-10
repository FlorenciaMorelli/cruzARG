#include "Vehiculos.h"

Vehiculos::Vehiculos(float posX, float posY, bool direccion) : BaseObject(posX, posY)
{
    this->direccion = direccion;
}
