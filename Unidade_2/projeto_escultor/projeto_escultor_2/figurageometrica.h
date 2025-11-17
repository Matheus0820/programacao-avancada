#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor.h"

class FiguraGeometrica {
protected:
    float r, g, b, a;
    Sculptor &t;

public:
    FiguraGeometrica();
    virtual ~FiguraGeometrica() = 0;
    virtual void draw(Sculptor &t) = 0;
    void setColor(float r, float g, float b, float a);
};

#endif // FIGURAGEOMETRICA_H
