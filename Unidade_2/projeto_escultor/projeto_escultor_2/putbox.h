#ifndef PUTBOX_H
#define PUTBOX_H

#include "figurageometrica.h"

class PutBox : public FiguraGeometrica {
    int x0, y0, z0;
    int x, y, z;
public:
    PutBox(int x0, int y0, int z0, int x, int y, int z);
    ~PutBox();
    void draw(Sculptor &t);
};

#endif // PUTBOX_H
