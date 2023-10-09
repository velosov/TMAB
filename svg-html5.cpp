/*
 * UFRJ
 * DMA/IM
 *
 * TMAB - Programação C++ & BD
 *
 * Autor: Prof. Milton Ramirez
 * Criação: 7 de junho de 2016
 *
 * AULA 11: Gravando arquivo HTML com gráficos SVG
 *
 */
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream arq("saida1.html");

    arq << "<!DOCTYPE html>" << endl;
    arq << "<html>" << endl;
    arq << "<body>" << endl;

    arq << "<h1>Meu 1o HTML via C++: Gráficos (1.0)!</h1>" << endl;
    arq << "<p> Vamos fazer alguns círculos. </p>" << endl;

    arq << " <svg width=\"200\" height=\"200\"> " << endl;
    for( unsigned raio = 10; raio <= 100; raio += 5)
        arq << "<circle cx=\"100\" cy=\"100\" r=\" " << raio << "\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" fill-opacity=\"0\"/>" << endl;
    for( unsigned y = 0; y <= 200; y += 10)
        arq << "<line x1=\"0\" y1=\" " << y << "\" x2=\"200\" y2=\" "<< (200 - y) << "\" style=\"stroke:rgb("<< y << ",0,0);stroke-width:2\" /> " << endl;

    arq << "</svg>" << endl;
    arq << "</html>" << endl;
    arq << "</body>" << endl;


    return 0;
}
