#include "sculptor.h"

Sculptor::Sculptor(int _nx, int _ny, int _nz) {
    nx = _nx;
    ny = _ny;
    nz = _nz;
}

void Sculptor::setColor(float r, float g, float b, float a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Sculptor::putVoxel(int x, int y, int z) {
    v[x][y][z].show = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z) {
    v[x][y][z].show = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {
// Criar voxels no intervelo de x0 - x1, y0 - y1, z0 - z1 e definir a cor como a atual, o show como true
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    // Fazer o show dos voxels no intervalo x0 - x1, y0 - y1, z0 - z1 igual a false
}
