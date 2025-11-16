#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "figurageometrica.h"

class PutVoxel : public FiguraGeometrica {
    int x, y, z;

public:
    PutVoxel(int x, int y, int z);
    ~PutVoxel();
    void draw(Sculptor &t);
};

#endif // PUTVOXEL_H
