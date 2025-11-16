#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel {
    float r, g, b;
    float a;
    bool show;
}

class Sculptor {
    Voxel ***v;
    int nx, ny, nz;
public:
    Sculptor(int _nx, int _ny, int _nz);
};

#endif // SCULPTOR_H
