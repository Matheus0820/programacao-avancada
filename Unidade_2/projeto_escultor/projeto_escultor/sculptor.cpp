#include "sculptor.h"
#include <cstdlib>
#include <fstream>

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
    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            for(int w = z0; w = z1; w++) {
                v[i][j][w].show = true;
                v[i][j][w].r = r;
                v[i][j][w].g = g;
                v[i][j][w].b = b;
                v[i][j][w].a = a;
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    // Fazer o show dos voxels no intervalo x0 - x1, y0 - y1, z0 - z1 igual a false

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

    // Fazendo com que todo voxel dentro dos intervalos dados tenham a visibilidade (show) igual a false;
    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            for(int w = z0; w = z1; w++) {
                v[i][j][w].show = false;
            }
        }
    }

}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius) {
    // Vê uma forma de ver os pontos que estão contidos pela esfera,
    // ou seja, satisfazem a equação da esfera -> (xcenter - a)**2 + (ycenter - b)**2 + (zcenter - c)**2 <= radius**2
    for (int i = 0; i <= nx; i++) {
        for (int j = 0; j <= ny; j++) {
            for(int w = 0; w = nz; w++) {
                if ((xcenter - i)**2 + (ycenter - j)**2 + (zcenter - w)**2 <= radius**2) {
                    v[i][j][w].show = true;
                    v[i][j][w].r = r;
                    v[i][j][w].g = g;
                    v[i][j][w].b = b;
                    v[i][j][w].a = a;
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius) {
    // Vê uma forma de ver os pontos que estão contidos pela esfera,
    // ou seja, satisfazem a equação da esfera -> (xcenter - a)**2 + (ycenter - b)**2 + (zcenter - c)**2 <= radius**2
    for (int i = 0; i <= nx; i++) {
        for (int j = 0; j <= ny; j++) {
            for(int w = 0; w = nz; w++) {
                if ((xcenter - i)**2 + (ycenter - j)**2 + (zcenter - w)**2 <= radius**2) {
                    v[i][j][w].show = false;
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    // Sendo um ponto contido em um elipsoide tendo que satisfazer a seguinte equação: 
    //  ((i - xcenter)**2 / rx**2) + ((j - ycenter)**2 / ry**2) + ((w - zcenter)**2 / rz**2) <= 1

    for (int i = 0; i <= nx; i++) {
        for(int j = 0; j <= ny; j++) {
            for(int w = 0; w <= nz; w++) {
                if (((i - xcenter)**2 / rx**2) + ((j - ycenter)**2 / ry**2) + ((w - zcenter)**2 / rz**2) <= 1) {
                    v[i][j][w].show = true;
                    v[i][j][w].r = r;
                    v[i][j][w].g = g;
                    v[i][j][w].b = b;
                    v[i][j][w].a = a;
                }
            }
        }   
    }

}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    for (int i = 0; i <= nx; i++) {
        for(int j = 0; j <= ny; j++) {
            for(int w = 0; w <= nz; w++) {
                if (((i - xcenter)**2 / rx**2) + ((j - ycenter)**2 / ry**2) + ((w - zcenter)**2 / rz**2) <= 1) {
                    v[i][j][w].show = false;
                }
            }
        }   
    }

}

void Sculptor::writeOFF(const char* filename) {
    std::ofstream fout;
    
    fout.open(filename);
    if (!fout.is_open()) {
        exit(1);
    }
}
