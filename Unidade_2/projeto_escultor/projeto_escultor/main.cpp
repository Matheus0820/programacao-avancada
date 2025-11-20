#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "sculptor.h"

using namespace std;

int main() {
    cout << "Gerando a figura 3d..." << endl;
    int tam = 300; // Tamanho da área de pintura

    // Gerando semente do random com base no tempo
    std::srand(std::time(nullptr));

    // Criando objeto da classe sculptor
    Sculptor obj1(tam, tam, tam);

    // Gerando asteroides aleatórios
    obj1.setColor(1.0, 1.0, 1.0, 0.5);
    for (int i = 0; i < tam * 10; ++i) {
        int x = std::rand() % tam;
        int y = std::rand() % tam;
        int z = std::rand() % tam;
        obj1.putVoxel(x, y, z);
    }

    // Gerando asteroides maiores aletoriamente
    obj1.setColor(0.50, 0.50, 0.50, 1); // Cinza opaco
    // Asteroide 1
    obj1.putBox(12, 16, 45, 49, 100, 104);
    obj1.cutBox(13, 15, 46, 48, 101, 103);
    obj1.cutSphere(14, 47, 102, 1);

    // Asteroide 2
    obj1.putBox(200, 205, 10, 14, 250, 255);
    obj1.cutBox(201, 204, 11, 13, 251, 254);
    obj1.cutSphere(202, 12, 252, 1);

    // Asteroide 3
    obj1.putBox(80, 85, 199, 203, 33, 37);
    obj1.cutBox(81, 84, 200, 202, 34, 36);
    obj1.cutSphere(82, 201, 35, 1);

    // Asteroide 4
    obj1.putBox(150, 154, 150, 154, 150, 154);
    obj1.cutBox(151, 153, 151, 153, 151, 153);
    obj1.cutSphere(152, 152, 152, 1);

    // Asteroide 5
    obj1.putBox(5, 9, 290, 294, 120, 124);
    obj1.cutBox(6, 8, 291, 293, 121, 123);
    obj1.cutSphere(7, 292, 122, 1);

    // Asteroide 6
    obj1.putBox(250, 254, 40, 44, 60, 64);
    obj1.cutBox(251, 253, 41, 43, 61, 63);
    obj1.cutSphere(252, 42, 62, 1);

    // Asteroide 7
    obj1.putBox(100, 104, 100, 104, 280, 284);
    obj1.cutBox(101, 103, 101, 103, 281, 283);
    obj1.cutSphere(102, 102, 282, 1);

    // Asteroide 8
    obj1.putBox(30, 34, 200, 204, 170, 174);
    obj1.cutBox(31, 33, 201, 203, 171, 173);
    obj1.cutSphere(32, 202, 172, 1);

    // Asteroide 9
    obj1.putBox(220, 224, 120, 124, 5, 9);
    obj1.cutBox(221, 223, 121, 123, 6, 8);
    obj1.cutSphere(222, 122, 7, 1);


    /* Fazendo um buraco negro */
    // Disco de acreção
    obj1.setColor(1.0, 1.0, 0, 0.5);
    obj1.putEllipsoid(tam/2, tam/2, tam/2, 60, 3, 60);
    obj1.cutEllipsoid(tam/2, tam/2, tam/2, 45, 3, 45);

    obj1.putEllipsoid(tam/2, tam/2, tam/2, 60, 60, 3);
    obj1.cutEllipsoid(tam/2, tam/2, tam/2, 45, 45, 3);

    // Esfera negra
    obj1.setColor(0, 0, 0, 1);
    obj1.putSphere(tam/2, tam/2, tam/2, 25);
    obj1.cutSphere(tam/2, tam/2, tam/2, 23);

    // Planeta miler
    obj1.setColor(0.24, 0.32, 0.56, 1);
    obj1.putSphere(80, 80, 80, 5);
    obj1.cutSphere(80, 80, 80, 3);

    // Endurance
    obj1.setColor(0.5, 0.5, 0.5, 0.5);
    obj1.putEllipsoid(90, 90, 90, 3, 3, 1);

    // Criando arquivo
    obj1.writeOFF("..//..//figura3d_out.off");
    cout << "Figura 3d gerada!" << endl;
  
}
