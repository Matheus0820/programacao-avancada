#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "figurageometrica.h"

class PutEllipsoid : public FiguraGeometrica {
    int xcenter, ycenter, zcenter, rx, ry, rz;

public:
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    ~PutEllipsoid();
    void draw(Sculptor &t);
};

#endif // PUTELLIPSOID_H
