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
    FiguraGeometrica *pfig; // Ponteiro para figura geometrica
    Sculptor *psct;
    vector<FiguraGeometrica*> figs; // Vetor para ponteiros dos filhos da classe FiguraGeometrica

    // Abrindo arquivo
    fin.open("C:\\Users\\Matheus Ramos\\Documents\\repositorios\\programacao-avancada\\Unidade_2\\projeto_escultor\\projeto_escultor_2\\figura3d_in.txt");

    if(!fin.is_open()) { // Se o arquivo não foi aberto ele encerra o programa
        cout << "Deu errado" << endl;
        exit(0);

    }
    cout << "Deu certo" << endl;

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
            cout << "Interacao inicio - word: " << word << endl;

            if(word.compare("putvoxel")) {
                int x0, y0, z0;
                fin >> x0 >> y0 >> z0 >> r >> g >> b >> a;

                // Criando objeto
                pfig = new PutVoxel(x0, y0, z0);
                pfig->setColor(r, g, b, a);
                figs.push_back(pfig);

            }
            else if(word.compare("cutvoxel")) {
                int x0, y0, z0;
                fin >> x0 >> y0 >> z0;

                // Criando objeto
                pfig = new CutVoxel(x0, y0, z0);
                figs.push_back(pfig);
            }
            else if(word.compare("putbox")) {
                int x0, x1, y0, y1, z0, z1;
                fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;

                // Criando objeto
                pfig = new PutBox(x0, y0, z0, x1, y1, z1);
                pfig->setColor(r, g, b, a);
                figs.push_back(pfig);
                cout << "PutBox: "<< x0 << " -  " << y0 << " - " << z0 << endl;
            }
            else if(word.compare("cutbox")) {
                int x0, x1, y0, y1, z0, z1;
                fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;

                // Criando objeto
                pfig = new CutBox(x0, y0, z0, x1, y1, z1);
                figs.push_back(pfig);
                cout << "CutBox: "<< x0 << " -  " << y0 << " - " << z0 << endl;
            }
            else if(word.compare("putsphere")) {
                int x0, y0, z0, raio;
                fin >> x0 >> y0 >> z0 >> raio >> r >> g >> b >> a;

                // Criando Objeto
                pfig = new PutSphere(x0, y0, z0, raio);
                pfig->setColor(r, g, b, a);
                figs.push_back(pfig);
            }
            else if(word.compare("cutsphere")) {
                int x0, y0, z0, raio;
                fin >> x0 >> y0 >> z0 >> raio;

                // Criando objeto
                pfig = new CutSphere(x0, y0, z0, raio);
                figs.push_back(pfig);
            }
            else if(word.compare("putellipsoid")) {
                int x0, y0, z0, rx, ry, rz;
                fin >> x0 >> y0 >> z0 >> rx >> ry >> rz >> r >> g >> b >> a;

                // Criando Objeto
                pfig = new PutEllipsoid(x0, y0, z0, rx, ry, rz);
                pfig->setColor(r, g, b, a);
                figs.push_back(pfig);
            }
            else if(word.compare("cutellipsoid")) {
                int x0, y0, z0, rx, ry, rz;
                fin >> x0 >> y0 >> z0 >> rx >> ry >> rz;

                // Criando Objeto
                pfig = new CutEllipsoid(x0, y0, z0, rx, ry, rz);
                figs.push_back(pfig);

            }

        }
    }

    /* Desenhando cada Figura Geometrica no Sculptor e deletando os ponteiros para cada figura geometrica */
    for(int i = 0; i < figs.size(); i++) {
        figs[i]->draw(*psct);
        delete figs[i];
    }
    cout << "Gerando imagem 3d" << endl;
    /* Gerando a Figura 3D */
    psct->writeOFF("saida.off");



    fin.close();
    delete psct;
    delete pfig;
    cout << "Código finalizado" << endl;
    return 0;

}
