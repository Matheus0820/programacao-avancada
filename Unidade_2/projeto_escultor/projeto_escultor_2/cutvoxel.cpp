#include "cutvoxel.h"

CutVoxel::CutVoxel(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

CutVoxel::~CutVoxel() {}

CutVoxel::draw(Sculptor &t) {
    t.v[x][y][z].show = false;
}
