#include "putellipsoid.h"
#include <cstdlib>
#include <cmath>

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
}


PutEllipsoid::~PutEllipsoid() {}

PutEllipsoid::draw(Sculptor &t) {
    // Sendo um ponto contido em um elipsoide tendo que satisfazer a seguinte equação:
    //  ((i - xcenter)**2 / rx**2) + ((j - ycenter)**2 / ry**2) + ((w - zcenter)**2 / rz**2) <= 1

    for (int i = 0; i < nx; i++) {
        for(int j = 0; j < ny; j++) {
            for(int w = 0; w < nz; w++) {
                if ((std::pow(i - xcenter, 2) / std::pow(rx, 2)) + (std::pow(j - ycenter, 2) / std::pow(ry, 2)) + (std::pow(w - zcenter, 2) / std::pow(rz, 2)) <= 1) {
                    v[i][j][w].show = true;
                    v[i][j][w].r = r;
                    v[i][j][w].g = g;
                    v[i][j][w].b = b;
                    v[i][j][w].a = a;
                }
            }
        }
    }
}
