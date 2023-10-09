/*
   UFRJ
   IM/DMA

   TMAB 2016.1

   Prof. Milton Ramirez (c)

   Programa: Matrizes com Objetos (aula I)
   Data: 04/05/2016
*/

#include <iostream>
#include <fstream>

using namespace std;

struct TMatriz {
    unsigned m,n;
    float a[100][100];

    TMatriz(unsigned pm=0, unsigned pn=0) : m(pm), n(pn) {}
    void  Print(void);
    void LeMatrizDeArquivo(string);
    //Soma(???);
};

void TMatriz::Print(void)
{
    for ( unsigned i = 0 ; i < m ; i++) {
        for (unsigned j = 0; j < n; j++ ) cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void TMatriz::LeMatrizDeArquivo(string nome_arquivo_entrada)
{
    ifstream arq(nome_arquivo_entrada.c_str());

    if ( !arq.good() ) cout << "problema ao abrir o arquivo: " << nome_arquivo_entrada << endl;
    else {
        arq >> m >> n;
        for ( unsigned i = 0 ; i < m ; i++)
            for (unsigned j = 0; j < n; j++ ) arq >> a[i][j];
    }
}

void SomaM(TMatriz A, TMatriz B, TMatriz & C)
{
    //C = A + B;
    if ( A.m == B.m ) C.m = A.m;
    else {
        cout << "Matrizes soma incompativeis!" << endl;
        return;
    }
    if ( A.n == B.n ) C.n = A.n;
    else {
        cout << "Matrizes soma incompativeis!" << endl;
        return;
    }
    for ( unsigned i = 0 ; i < C.m ; i++)
        for (unsigned j = 0; j < C.n; j++ )
            C.a[i][j] = A.a[i][j] + B.a[i][j];
}


int main()
{
    cout << "Aula 4: Objeto Matriz, MR2(c)" << endl;

    TMatriz A, B, C;

    A.LeMatrizDeArquivo("A.mat");
    A.Print();

    B.LeMatrizDeArquivo("B.mat");
    B.Print();

    SomaM(A,B,C);
    C.Print();

    return 0;
}
