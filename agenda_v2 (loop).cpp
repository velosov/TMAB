/*
   UFRJ
   IM/DMA

   TMAB 2016.1

   Prof. Milton Ramirez (c)

   Programa: Agenda versao 1
   Data: 14/04/2016
*/


#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

typedef struct
{
    string logradouro;
    long numero;
    long CEP;
    string cidade;
    string UF;
} TEndereco;

typedef struct
{
    string nome;
    TEndereco endereco;
    long tels[10];
} TPessoa;

void Apresentacao(void)
{
    cout << "#####################################" << endl;
    cout << "#### 2o programa; AULA 1 (c) MR2 ####" << endl;
    cout << "#####################################" << endl;

    cout << "\n\n\t Olá eu sou o seu 2o programna!" << endl;
}

TPessoa Agenda[50];

void LeDados(TPessoa& p1)
{
    cout << "Qual o nome? "; getline(cin, p1.nome);
    cout << "Qual o endereco? "; getline(cin, p1.endereco.logradouro);
    cout << "Qual o telefone? "; cin >> p1.tels[0];
    cout << endl << endl;
}

void ApresentaDados(TPessoa p1)
{
    cout << "Nome     : " << p1.nome << endl;
    cout << "Endereco : " << p1.endereco.logradouro << endl;
    cout << "Telefone : " << p1.tels[0] << endl;
}
void Run(void)
{
    cout << "Rodando... \n\n";

    int i = 0;
    char resp;

    do {
        cout << "Deseja entrar com um nova pessoa na agenda ? (s/n)";
        cin.clear(); cin.ignore(INT_MAX,'\n');
        cin >> resp;
        cin.clear(); cin.ignore(INT_MAX,'\n');
        if  ( resp == 's' ) {
            cout << "Entre com os dados da " << i << "-esima pessoa\n\n";
            LeDados(Agenda[i]);
            i++; // i = i + 1;
        }
        else break;
    } while( i < 50 );

    for ( int n = 0; n < i; n++) ApresentaDados(Agenda[n]);
}
void Fecha(void)
{
    cout << "\n\n#### saindo ####" << endl;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Apresentacao();
    Run();
    Fecha();
    return 0;
}
