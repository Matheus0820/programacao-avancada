#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel {
    float r, g, b;
    float a;
    bool show;
};

class Sculptor {
    Voxel ***v;
    int nx, ny, nz;
public:
    Sculptor(int _nx, int _ny, int _nz);
    void writeOFF(const char* filename);
    int getNx();
    int getNy();
    int getNz();
    Voxel*** getVoxel();
};

#endif // SCULPTOR_H
