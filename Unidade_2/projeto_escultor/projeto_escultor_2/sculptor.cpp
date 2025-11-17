#include "sculptor.h"

Sculptor::Sculptor(int _nx, int _ny, int _nz) {
    nx = _nx;
    ny = _ny;
    nz = _nz;
}

int Sculptor::getNx() {
    return nx;
}

int Sculptor::getNy() {
    return ny;
}

int Sculptor::getNz() {
    return nz;
}

Voxel Sculptor::getVoxel() {
    return v;
}
