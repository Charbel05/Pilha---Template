//Aluno: Charbel Daher Boulos
//Matricula: 2020025270
//Lab 8 - ex 3, 4 e 5

#include<iostream>
#include"pilha.h"

using namespace std;

int main(){
    CPilha<int> p1;
    CPilha<float> p2;
    CPilha<char> p3;
    CPilha<CPilha<int>> p4;

    cout << "-------PILHA DE 4INT------\n";
    cin >> p1;
    cout << p1;
    
    cout << "\n-------PILHA DE FLOAT------\n";
    cin >> p2;
    cout << p2;
    
    cout << "\n-------PILHA DE CHAR------\n";
    cin >> p3;
    cout << p3;
    
    cout << "\n-------PILHA DE PILHA DE INT------\n";
    cin >> p4;
    cout << p4;


    return 0;
}