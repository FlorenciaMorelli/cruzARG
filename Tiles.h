#ifndef TILES_H
#define TILES_H

#include "BaseObject.h"
#include <vector>

using namespace sf;

class Tiles : public BaseObject
{
    public:
        Tiles(float posX, float posY, int tipo);
};

#endif // TILES_H
