#include "putvoxel.h"

PutVoxel::PutVoxel(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

PutVoxel::~PutVoxel() {}

PutVoxel::draw(Sculptor &t) {
    t.v[x][y][z].show = true;
    t.v[x][y][z].r = r;
    t.v[x][y][z].g = g;
    t.v[x][y][z].b = b;
    t.v[x][y][z].a = a;
}
