#include <iostream>
#include <cstdlib>
#include <fstream>
#include "sculptor.h"

using namespace std;

int main() {
  // Criando objeto da classe sculptor
    Sculptor obj1(3, 3, 3);
  
  // Setando a  cor padrao para branco
    obj1.setColor(1.0, 1.0, 1.0, 1.0);
    obj1.putVoxel(0, 0, 0);

  // Criando uma caixa branca vazada e sem o topo
  // obj1.putBox(1, 3, 1, 3, 1, 3);
  // obj1.cutBox(2, 2, 2, 2, 2, 2);

  // Criando arquivo
    obj1.writeOFF("saida.off");
  
}
