#ifndef CUTBOX_H
#define CUTBOX_H

#include "figurageometrica.h"

class CutBox : public FiguraGeometrica
{
    int x0, y0, z0;
    int x, y, z;
public:
    CutBox(int x0, int y0, int z0, int x, int y, int z);
    ~CutBox();
    void draw(Sculptor &t);
};

#endif // CUTBOX_H
