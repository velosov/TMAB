#include <iostream>
#include <fstream>

using namespace std;

struct Pessoa
{
    string nome;
    unsigned idade;

    Pessoa(string n = "SEM NOME N", unsigned i = 1000) { nome = n; idade = i; }
    //Pessoa(void) { nome = "SEM_NOME"; idade = 0; }
    //Pessoa(string n) { nome = n; idade = 0;}
    void Imprime(void);
};

void Pessoa::Imprime(void)
{
    cout << "\n\tNome  : " << nome << endl;
    cout << "\tIdade : " << idade << endl;
}

void operator << (ostream & saida, Pessoa p)
{
    saida << "\n\tNome  : " << p.nome << endl;
    saida << "\tIdade : " << p.idade << endl;
}

void Run(void)
{
    Pessoa p1("MAriano",20), p2, p3("Antonio");

    p1.Imprime();
    p2.Imprime();
    //p3.Imprime();

    ofstream arq("teste2.txt");
    //Imprime(cout, p3); //
    cout << p3;
    //Imprime(arq, p3); //
    arq << p3 << p2;
    arq << p2;
    arq << p1;

    arq.close();

}

int main()
{
    cout << " --- Aula 1 de Criacao de Classes MR2(c)" << endl;

    Run();

    return 0;
}
