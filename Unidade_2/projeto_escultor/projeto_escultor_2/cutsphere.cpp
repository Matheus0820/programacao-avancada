#include "cutsphere.h"

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius) {
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->radius = radius;
}

CutSphere::~CutSphere() {}

CutSphere::draw(Sculptor &t) {
    // Vê uma forma de ver os pontos que estão contidos pela esfera,
    // ou seja, satisfazem a equação da esfera -> (xcenter - a)**2 + (ycenter - b)**2 + (zcenter - c)**2 <= radius**2
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for(int w = 0; w < nz; w++) {
                if (std::pow(xcenter - i, 2) + std::pow(ycenter - j, 2) + std::pow(zcenter - w, 2) <= std::pow(radius, 2)) {
                    v[i][j][w].show = false;
                }
            }
        }
    }
}
