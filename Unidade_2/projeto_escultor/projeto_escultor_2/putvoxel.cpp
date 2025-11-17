#include "putvoxel.h"
#include "sculptor.h"

PutVoxel::PutVoxel(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

PutVoxel::~PutVoxel() {}

void PutVoxel::draw(Sculptor &t) {
    t.getVoxel()[x][y][z].show = true;
    t.getVoxel()[x][y][z].r = r;
    t.getVoxel()[x][y][z].g = g;
    t.getVoxel()[x][y][z].b = b;
    t.getVoxel()[x][y][z].a = a;
}
