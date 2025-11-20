// Bibliotecas
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

// Classes
#include "figurageometrica.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include "sculptor.h"

using namespace std;

int main() {
    // Objetos
    ifstream fin; // Objeto da classe fstream - Guarda o arquivo de entrada
    string word; // Objeto da classe String
    FiguraGeometrica *pfig = nullptr; // Ponteiro para figura geometrica
    Sculptor *psct = nullptr;
    vector<FiguraGeometrica*> figs; // Vetor para ponteiros dos filhos da classe FiguraGeometrica

    // Abrindo arquivo
    fin.open("..\\..\\figura3d_in.txt");

    if(!fin.is_open()) { // Se o arquivo não foi aberto ele encerra o programa
        cout << "Arquivo não encontrado. Verifique o endereço do arquivo 'figura3d_in.txt'" << endl;
        exit(0);

    }
    cout << "Arquivo encontrado. Iniciando o processo de leitura." << endl;

    // Lendo as primeira linha do arquivo .txt -> Definindo as dimensões do Sculptor
    int nx, ny, nz;
    fin >> word >> nx >> ny >> nz;
    psct = new Sculptor(nx, ny, nz);

    /* Lendo arquivo e criando objetos */
    cout << "Entrando no while" << endl;
    while(fin.good()) { // Contina no laço se arquivo estiver bom para leitura
        if(fin.good()) { // Se estiver bom para leitura ele ler
            fin >> word; // Pega a primeira palavra da linha

            // Variáveis bastantes utilizadas
            float r, g, b, a;
            cout << "Implementando metodo: " << word << endl;

            if(word.compare("putvoxel") == 0) {
                int x0, y0, z0;
                fin >> x0 >> y0 >> z0 >> r >> g >> b >> a;

                // Criando objeto
                pfig = new PutVoxel(x0, y0, z0);
                pfig->setColor(r, g, b, a);
                figs.push_back(pfig);

            }
            else if(word.compare("cutvoxel") == 0) {
                int x0, y0, z0;
                fin >> x0 >> y0 >> z0;

                // Criando objeto
                pfig = new CutVoxel(x0, y0, z0);
                figs.push_back(pfig);
            }
            else if(word.compare("putbox") == 0) {
                int x0, x1, y0, y1, z0, z1;
                fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;

                // Criando objeto
                pfig = new PutBox(x0, y0, z0, x1, y1, z1);
                pfig->setColor(r, g, b, a);
                figs.push_back(pfig);
            }
            else if(word.compare("cutbox") == 0) {
                int x0, x1, y0, y1, z0, z1;
                fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;

                // Criando objeto
                pfig = new CutBox(x0, y0, z0, x1, y1, z1);
                figs.push_back(pfig);
            }
            else if(word.compare("putsphere") == 0) {
                int x0, y0, z0, raio;
                fin >> x0 >> y0 >> z0 >> raio >> r >> g >> b >> a;

                // Criando Objeto
                pfig = new PutSphere(x0, y0, z0, raio);
                pfig->setColor(r, g, b, a);
                figs.push_back(pfig);
            }
            else if(word.compare("cutsphere") == 0) {
                int x0, y0, z0, raio;
                fin >> x0 >> y0 >> z0 >> raio;

                // Criando objeto
                pfig = new CutSphere(x0, y0, z0, raio);
                figs.push_back(pfig);
            }
            else if(word.compare("putellipsoid") == 0) {
                int x0, y0, z0, rx, ry, rz;
                fin >> x0 >> y0 >> z0 >> rx >> ry >> rz >> r >> g >> b >> a;

                // Criando Objeto
                pfig = new PutEllipsoid(x0, y0, z0, rx, ry, rz);
                pfig->setColor(r, g, b, a);
                figs.push_back(pfig);
            }
            else if(word.compare("cutellipsoid") == 0) {
                int x0, y0, z0, rx, ry, rz;
                fin >> x0 >> y0 >> z0 >> rx >> ry >> rz;

                // Criando Objeto
                pfig = new CutEllipsoid(x0, y0, z0, rx, ry, rz);
                figs.push_back(pfig);

            }

        }
    }

    /* Desenhando cada Figura Geometrica no Sculptor e deletando os ponteiros para cada figura geometrica */
    cout << "Inicidando a chamada do metodo 'draw'..." << endl;
    for(int i = 0; i < figs.size(); i++) {
        figs[i]->draw(*psct);
        delete figs[i];
    }

    cout << "Gerando imagem 3d..." << endl;
    /* Gerando a Figura 3D */
    psct->writeOFF("..\\..\\figura3d_out.off");
    cout << "Figura 3d gerada!" << endl;

    // Deletando os ponteiros
    fin.close();
    delete psct;
    delete pfig;
    return 0;

}
