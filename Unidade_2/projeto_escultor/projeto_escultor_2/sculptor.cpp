#include "sculptor.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>

Sculptor::Sculptor(int _nx, int _ny, int _nz) {
    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel**[nx];
    for (int i = 0; i < nx; i++) {
        v[i] = new Voxel*[ny];
        for (int j = 0; j < ny; j++) {
            v[i][j] = new Voxel[nz];
            for (int w = 0; w < nz; w++) {
                v[i][j][w].show = false;
            }
        }
    }
}

Sculptor::~Sculptor() {
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v;
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

Voxel*** Sculptor::getVoxel() {
    return v;
}

void Sculptor::writeOFF(const char* filename) {
    std::ofstream fout;

    // Abrindo arquivo
    fout.open(filename);
    if (!fout.is_open()) {
        exit(1);
    }

    // Definindo que todos os número do tipo float vão ter duas casas decimais após a virgula
    fout << std::fixed << std::setprecision(2);

    // Calculando a quantidade de voxels, vertices e faces
    int nVoxel = 0;
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int w = 0; w < nz; w++) {
                if (v[i][j][w].show == true) {
                    nVoxel++;
                }
            }
        }
    }
    int nVertices = nVoxel * 8;
    int nFaces = nVoxel * 6;

    // Escrevendo parte inicial do arquivo
    fout << "OFF" << std::endl;
    fout << nVertices << " " << nFaces << " " << 0 << std::endl;

    // Definindo Propriedades e escrevendo os vertices
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int w = 0; w < nz; w++) {
                if (v[i][j][w].show == true) {
                    float x = (float) i;
                    float y = (float) j;
                    float z = (float) w;


                    // Definindo as posições dos 8 vértices do cubo unitário para cada ponto da matriz de voxel

                    // V0
                    fout << x - 0.5 << " " << y + 0.5 << " " << z - 0.5 << " " << std::endl;

                    // V1
                    fout << x - 0.5 << " " << y - 0.5 << " " << z - 0.5 << " " << std::endl;

                    // V2
                    fout << x + 0.5 << " " << y - 0.5 << " " << z - 0.5 << " " << std::endl;

                    // V3
                    fout << x + 0.5 << " " << y + 0.5 << " " << z - 0.5 << " " << std::endl;

                    // V4
                    fout << x - 0.5 << " " << y + 0.5 << " " << z + 0.5 << " " << std::endl;

                    // V5
                    fout << x - 0.5 << " " << y - 0.5 << " " << z + 0.5 << " " << std::endl;

                    // V6
                    fout << x + 0.5 << " " << y - 0.5 << " " << z + 0.5 << " " << std::endl;

                    // V7
                    fout << x + 0.5 << " " << y + 0.5 << " " << z + 0.5 << " " << std::endl;
                }
            }
        }
    }

    int indexVertice = 0; // Variável que vai interar, por meio dos for, sobre as posições de cada vertice para montar as faces
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int w = 0; w < nz; w++) {
                if (v[i][j][w].show == true) {
                    // Pegando as cores de cada voxel
                    float red = v[i][j][w].r;
                    float green = v[i][j][w].g;
                    float blue = v[i][j][w].b;
                    float alpha = v[i][j][w].a;

                    // Definindo Faces dos blocos unitários
                    // Face 1 -> Seguindo padrão informado no matérial do site do professor
                    fout << 4 << " " << indexVertice << " " << indexVertice + 3 << " " << indexVertice + 2 << " " << indexVertice + 1 << " " << red << " " << green << " " << blue << " " << alpha << std::endl;

                    // Face 2
                    fout << 4 << " " << indexVertice + 4 << " " << indexVertice + 5 << " " << indexVertice + 6 << " " << indexVertice + 7 << " " << red << " " << green << " " << blue << " " << alpha << std::endl;

                    // Face 3
                    fout << 4 << " " << indexVertice << " " << indexVertice + 1 << " " << indexVertice + 5 << " " << indexVertice + 4 << " " << red << " " << green << " " << blue << " " << alpha << std::endl;

                    // Face 4
                    fout << 4 << " " << indexVertice << " " << indexVertice + 4 << " " << indexVertice + 7 << " " << indexVertice + 3 << " " << red << " " << green << " " << blue << " " << alpha << std::endl;

                    // Face 5
                    fout << 4 << " " << indexVertice + 3 << " " << indexVertice + 7 << " " << indexVertice + 6 << " " << indexVertice + 2 << " " << red << " " << green << " " << blue << " " << alpha << std::endl;

                    // Face 6
                    fout << 4 << " " << indexVertice + 1 << " " << indexVertice + 2 << " " << indexVertice + 6 << " " << indexVertice + 5 << " " << red << " " << green << " " << blue << " " << alpha << std::endl;

                    // Incrementando mais 8 vertices na variavel de controle "indexVertice"
                    indexVertice += 8;
                }
            }
        }
    }

    // Fechando arquivo;
    fout.close();
}
