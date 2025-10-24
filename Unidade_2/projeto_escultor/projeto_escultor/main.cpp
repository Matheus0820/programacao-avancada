#include <iostream>
#include <cstdlib>
#include <fstream>
#include "sculptor.h"

using namespace std;

int main() {
  // Criando objeto da classe sculptor
  Sculptor obj1(30, 30, 30);
  
  // Setando a  cor padrao para branco
  obj1.setColor(1.0, 1.0, 1.0, 1.0);
  
  // Criando uma caixa branca vazada e sem o topo
  obj1.putBox(5, 25, 5, 25, 5, 25);
  obj1.cutBox(6, 24, 6, 24, 4, 24);

  // Criando arquivo
  obj1.writeOFF("saida.off");
  
}
