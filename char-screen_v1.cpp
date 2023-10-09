#include <iostream>
#include <vector>

using namespace std;

class Tela
{
    vector<vector<char> > buffer;
public:
    unsigned Xmax;
    unsigned Ymax;
    Tela(unsigned txmax, unsigned tymax);
    void print(void);
    void Moldura(void);
    void putCharXY(int,int,char);
};

Tela::Tela(unsigned txmax, unsigned tymax)
{
    Xmax = txmax; Ymax = tymax;

    buffer.resize(Ymax);
    for(unsigned y=0; y < Ymax; y++) buffer[y].resize(Xmax);

    for(unsigned y=0; y < Ymax; y++)
        for(unsigned x=0; x < Xmax; x++)
            buffer[y][x] = ' ';
}

void Tela::Moldura(void)
{
    for(unsigned x = 0; x < Xmax; x++ ) buffer[0][x] = '#';
    for(unsigned y = 1; y < Ymax-1; y++) buffer[y][0] = buffer[y][Xmax-1] = '#';
    for(unsigned x = 0; x < Xmax; x++ ) buffer[Ymax-1][x] = '#';
}

void Tela::putCharXY(int xp,int yp,char c)
{
    buffer[yp][xp] = c;
}

void Tela::print(void)
{
    for(unsigned y=0; y < Ymax; y++) {
       for(unsigned x=0; x < Xmax; x++) cout << buffer[y][x];
       cout << endl;
    }
}
class Reta
{
    int x,y;
public:
    Reta (int px, int py) :x(px), y(py) {};
    void desenha(Tela & t);
};

void
Reta::desenha(Tela & t)
{
    unsigned yt;

    for(unsigned xt = 1; xt < x; xt++) {
        yt = (y*xt)/x;
        t.putCharXY(xt,yt,'o');
    }
}
int main()
{
    char c;

    cout << "Aula10 - Hierarquia de classes - TMAB 2016.1 - MR2(c)" << endl;

    Tela t1(99,39);
    t1.Moldura();
    t1.print();

    Reta r(80,15);
    r.desenha(t1);
    t1.print();
    cin >> c;

    Tela t2(80,20);
    t2.Moldura();
    r.desenha(t2);
    t2.print();


    return 0;
}
