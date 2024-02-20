#ifndef TILES_H
#define TILES_H

#include "BaseObject.h"
#include <vector>
#include "tipoDeTiles.h"

using namespace sf;

class Tiles : public BaseObject
{
private:
    tipoDeTiles tipoDePiso;

    public:
        Tiles(float posX, float posY, tipoDeTiles tipo);
        tipoDeTiles getTipoDePiso(){ return this->tipoDePiso; }
};

#endif // TILES_H
