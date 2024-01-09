#ifndef TILES_H
#define TILES_H

#include "BaseObject.h"
#include <vector>

using namespace sf;

class Tiles : public BaseObject
{
private:
    int tipoDePiso;

    public:
        Tiles(float posX, float posY, int tipo);
        int getTipoDePiso(){ return this->tipoDePiso; }
};

#endif // TILES_H
