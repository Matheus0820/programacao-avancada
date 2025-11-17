#ifndef PUTBOX_H
#define PUTBOX_H

#include "figurageometrica.h"

class PutBox : public FiguraGeometrica {
    int x0, y0, z0;
    int x1, y1, z1;
public:
    PutBox(int x0, int y0, int z0, int x1, int y1, int z1);
    ~PutBox();
    void draw(Sculptor &t);
};

#endif // PUTBOX_H
