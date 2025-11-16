#include "cutbox.h"

CutBox::CutBox(int x0, int y0, int z0, int x, int y, int z) {
    this->x0 = x0;
    this->y0 = y0;
    this->z0 = z0;
    this->x = x;
    this->y = y;
    this->z = z;
}

CutBox::~CutBox() {}

CutBox::draw(Sculptor &t) {
    // Definindo intervalo padrão no modo crescente
    int aux; // Variável auxíliar
    if(x0 > x1) {
        aux = x0;
        x0 = x1;
        x1 = aux;
    }
    if (y0 > y1) {
        aux = y0;
        y0 = y1;
        y1 = aux;
    }
    if (z0 > z1) {
        aux = z0;
        z0 = z1;
        z1 = aux;
    }
    // Fazendo com que todo voxel dentro dos intervalos dados se tornem invisíveis => show = false;
    for (int i = x0; i < x1; i++) {
        for (int j = y0; j < y1; j++) {
            for(int w = z0; w < z1; w++) {
                t.v[i][j][w].show = false;
            }
        }
    }
}
