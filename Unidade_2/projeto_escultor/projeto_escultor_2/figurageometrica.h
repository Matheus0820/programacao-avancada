#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor.h"

class FiguraGeometrica {
public:
    Sculptor &t;

protected:
    float r, g, b, a;

public:
    FiguraGeometrica();
    virtual ~FiguraGeometrica() = 0;
    virtual void draw(Sculptor &t) = 0;
    void setColor(r, g, b, a);
};

#endif // FIGURAGEOMETRICA_H
