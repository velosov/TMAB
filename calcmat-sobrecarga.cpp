/*
   UFRJ
   IM/DMA

   TMAB 2016.1

   Prof. Milton Ramirez (c)

   Programa: Estudo Dirigido II - Classe Matriz
   Data: 10/05/2016
*/
#include <iostream>
#include <fstream>

using namespace std;

class Matriz {
  public:

    unsigned m,n;
    float a[100][100];

    Matriz(unsigned pm=0, unsigned pn=0) : m(pm), n(pn) {}
    Matriz(string);
    void Print(void);
    void GravaMatriz(string);
    Matriz operator +(Matriz B);
    Matriz operator -(Matriz B);
    Matriz operator *(Matriz B);
};

Matriz::Matriz(string nome_arquivo_entrada)
{
    ifstream arq(nome_arquivo_entrada.c_str());

    if ( !arq.good() ) {
            cout << "problema ao abrir o arquivo: " << nome_arquivo_entrada << endl;
    }
    else {
        arq >> m >> n;
        for ( unsigned i = 0 ; i < m ; i++)
            for (unsigned j = 0; j < n; j++ ) arq >> a[i][j];
    }
}

Matriz Matriz::operator +(Matriz B)
{
    Matriz C;

    if ( m == B.m && n == B.n) { C.m = m; C.n = n; }
    else {
        cout << "Matrizes soma incompativeis!" << endl;
        return C;
    }
    for ( unsigned i = 0 ; i < C.m ; i++)
        for (unsigned j = 0; j < C.n; j++ )
            C.a[i][j] = a[i][j] + B.a[i][j];
   return C;
}

Matriz Matriz::operator -(Matriz B)
{
    Matriz C;

    if ( m == B.m && n == B.n) { C.m = m; C.n = n; }
    else {
        cout << "Matrizes soma incompativeis!" << endl;
        return C;
    }
    for ( unsigned i = 0 ; i < C.m ; i++)
        for (unsigned j = 0; j < C.n; j++ )
            C.a[i][j] = a[i][j] - B.a[i][j];
   return C;
}

Matriz Matriz::operator *(Matriz B)
{
    Matriz C;
    unsigned k;
    float cij;

    if ( n == B.m ) { C.m = m; C.n = B.n; }
    else {
        cout << "Matrizes produto incompativeis!" << endl;
        return C;
    }
    for ( unsigned i = 0 ; i < C.m ; i++)
        for (unsigned j = 0; j < C.n; j++ )
        {
            for( k = 0, cij = 0.0; k < n; k++ )
                cij += a[i][k]*B.a[k][j];
            C.a[i][j] = cij;
        }
   return C;
}

void Matriz::Print(void)
{
    for ( unsigned i = 0 ; i < m ; i++) {
        for (unsigned j = 0; j < n; j++ ) cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

Matriz operator *(float esc, Matriz B)
{
    Matriz C;

    C.m = B.m; C.n = B.n;
    for ( unsigned i = 0 ; i < C.m ; i++)
        for (unsigned j = 0; j < C.n; j++ )
            C.a[i][j] = esc * B.a[i][j];
   return C;
}

void ApresentaMenu(void)
{
    cout << "--------------------------------- ^.^ --" << endl;
    cout << "  1 - Carrega Matriz A." << endl;
    cout << "  2 - Carrega Matriz B." << endl;
    cout << "  3 - C = A + B." << endl;
    cout << "  4 - C = A - B." << endl;
    cout << "  5 - C = a * A." << endl;
    cout << "  6 - C = A x B." << endl;
    cout << "  7 - C = A^2." << endl;
    cout << "  8 - Sai do programa." << endl;

    cout << " \n  Digite uma opcao." << endl;
}

void menu(void)
{
    char opcao;
    Matriz A,B,C;
    float escalar;

    do  {
        ApresentaMenu();
        cin >> opcao;
        switch (opcao)
        {
            case '1' : A = Matriz("A.mat"); A.Print(); break;
            case '2' : B = Matriz("B.mat"); B.Print(); break;
            case '3' : C = A + B; C.Print(); break;
            case '4' : C = A - B; C.Print(); break;
            case '5' : cout << "Escalar = "; cin >> escalar;
                       C = escalar * A; C.Print(); break;
            case '6' : C = A * B; C.Print(); break;
            case '7' : C = A*A; C.Print(); break;
            case '8' : cout << "Saindo....\n"; break;
            default  : cout << "\tOpcao Invalida!\n";
        }
    } while ( opcao != '8');
}

int main()
{
    cout << "Programa: Estudo Dirigido 02 - MR2(c)" << endl;
    menu();

    return 0;
}
