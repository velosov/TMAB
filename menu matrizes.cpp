/*
   UFRJ
   IM/DMA

   TMAB 2016.1

   Prof. Milton Ramirez (c)

   Programa: Estudo Dirigido I - Menu & Matrizes.1
   Data: 03/05/2016
*/

#include <iostream>

using namespace std;

float A[2][2] = {{1,2},{3,4}};
float B[2][2], C[2][2];

void PrintMatriz(float M[2][2])
{
    for( int i = 0; i < 2; i++)
    {
        for( int j = 0; j < 2; j++) cout << M[i][j] << " ";
        cout << endl;
    }
}

void InsereMatriz(float M[2][2])
{
    for( int i = 0; i < 2; i++)
        for( int j = 0; j < 2; j++)
        {
            cout << "\tEntre o elemento (" << i+1 << "," << j+1 << ") = " ;
            cin >> M[i][j];
        }
}

void SomaAeB()
{
    cout << "Somando matrizes: A + B..." << endl;
    for( int i = 0; i < 2; i++)
        for( int j = 0; j < 2; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
}

void ApresentaMenu(void)
{
    cout << "---------------------------------" << endl;
    cout << "  1 - Insere Matriz A." << endl;
    cout << "  2 - Insere Matriz B." << endl;
    cout << "  3 - Soma A + B." << endl;
    cout << "  4 - Sai do programa." << endl;

    cout << " \n  Digite uma opcao." << endl;
}

void menu(void)
{
    char opcao;

    do  {
        // escreve na tela o MENU
        ApresentaMenu();
        // pega a OPCAO do USR
        cin >> opcao;
        // chama a rotina correspondente a OPCAO escolhida
        switch (opcao)
        {
            case '1' : InsereMatriz(A); PrintMatriz(A); break;
            case '2' : InsereMatriz(B); PrintMatriz(B); break;
            case '3' : SomaAeB(); PrintMatriz(C); break;
            case '4' : cout << "Saindo....\n"; break;
            default  : cout << "\tOpcao Invalida!\n";
        }
        // REPETE isso ate que FIM/SAIR
    } while ( opcao != '4');
}

int main()
{
    cout << "Programa: Estudo Dirigido 01 - MR2(c)" << endl;
    menu();

    return 0;
}
