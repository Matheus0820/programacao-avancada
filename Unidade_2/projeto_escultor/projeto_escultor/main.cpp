#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "sculptor.h"

using namespace std;

int main() {
    // Gerando semente do random com base no tempo
    std::srand(std::time(nullptr));

    // Criando objeto da classe sculptor
    Sculptor obj1(100, 100, 100);

    // Gerando asteroides aleatórios
    obj1.setColor(1.0, 1.0, 1.0, 0.5);
    for (int i = 0; i < 300; ++i) {
        int x = std::rand() % 100;
        int y = std::rand() % 100;
        int z = std::rand() % 100;
        obj1.putVoxel(x, y, z);
    }

    // Fazendo um buraco negro

    // Disco de acreção
    obj1.setColor(1.0, 1.0, 0, 0.5);
    obj1.putEllipsoid(50, 50, 50, 30, 3, 30);
    obj1.cutEllipsoid(50, 50, 50, 20, 3, 20);

    obj1.putEllipsoid(50, 50, 50, 30, 30, 3);
    obj1.cutEllipsoid(50, 50, 50, 20, 20, 3);

    // Esfera negra
    obj1.setColor(0, 0, 0, 1);
    obj1.putSphere(50, 50, 50, 10);

    // Planeta miler
    obj1.setColor(0.24, 0.32, 0.56, 1);
    obj1.putSphere(80, 80, 80, 5);

    // Endurance
    obj1.setColor(0.5, 0.5, 0.5, 0.5);
    obj1.putEllipsoid(85, 85, 85, 2, 2, 1);

    obj1.setColor(0.7, 0.7, 0.7, 0.7);
    obj1.putBox(84, 86, 84, 86, 83, 87);




    // Criando arquivo
    obj1.writeOFF("saida.off");
  
}
