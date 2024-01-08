#ifndef TILES_H
#define TILES_H

#include "BaseObject.h"

using namespace sf;

class Tiles : public BaseObject
{
    public:
        Tiles(float posX, float posY, int tipo);
        ~Tiles();
};

#endif // TILES_H
