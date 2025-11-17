#include "putbox.h"

PutBox::PutBox(int x0, int y0, int z0, int x1, int y1, int z1) {
    this->x0 = x0;
    this->y0 = y0;
    this->z0 = z0;
    this->x1 = x1;
    this->y1 = y1;
    this->z1 = z1;

}

PutBox::~PutBox() {}

void PutBox::draw(Sculptor &t) {
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
    // Fazendo com que todo voxel dentro dos intervalos dados sejam visivéis e com a cor atual do desenho;
    for (int i = x0; i < x1; i++) {
        for (int j = y0; j < y1; j++) {
            for(int w = z0; w < z1; w++) {
                t.getVoxel()[i][j][w].show = true;
                t.getVoxel()[i][j][w].r = r;
                t.getVoxel()[i][j][w].g = g;
                t.getVoxel()[i][j][w].b = b;
                t.getVoxel()[i][j][w].a = a;
            }
        }
    }

}
