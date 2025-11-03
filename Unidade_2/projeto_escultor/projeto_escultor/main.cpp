#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "sculptor.h"

using namespace std;

int main() {
    int tam = 300; // Tamanho da área de pintura

    // Gerando semente do random com base no tempo
    std::srand(std::time(nullptr));

    // Criando objeto da classe sculptor
    Sculptor obj1(300, 300, 300);

    // Gerando asteroides aleatórios
    obj1.setColor(1.0, 1.0, 1.0, 0.5);
    for (int i = 0; i < tam * 10; ++i) {
        int x = std::rand() % tam;
        int y = std::rand() % tam;
        int z = std::rand() % tam;
        obj1.putVoxel(x, y, z);
    }


    // Fazendo um buraco negro

    // Disco de acreção
    obj1.setColor(1.0, 1.0, 0, 0.5);
    obj1.putEllipsoid(tam/2, tam/2, tam/2, 60, 3, 60);
    obj1.cutEllipsoid(tam/2, tam/2, tam/2, 45, 3, 45);

    obj1.putEllipsoid(tam/2, tam/2, tam/2, 60, 60, 3);
    obj1.cutEllipsoid(tam/2, tam/2, tam/2, 45, 45, 3);

    // Esfera negra
    obj1.setColor(0, 0, 0, 1);
    obj1.putSphere(tam/2, tam/2, tam/2, 25);

    // Planeta miler
    obj1.setColor(0.24, 0.32, 0.56, 1);
    obj1.putSphere(80, 80, 80, 5);

    // Endurance
    obj1.setColor(0.5, 0.5, 0.5, 0.5);
    obj1.putEllipsoid(90, 90, 90, 3, 3, 1);




    // Criando arquivo
    obj1.writeOFF("saida.off");
  
}
