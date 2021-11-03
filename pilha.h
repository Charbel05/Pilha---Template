//Aluno: Charbel Daher Boulos
//Matricula: 2020025270
//Lab 8 - ex 3, 4 e 5

#include<iostream>
using namespace std;

#ifndef PILHA_H
#define PILHA_H

template<typename T>
class CPilha
{
    private:
        T *dados; // ponteiro para dados da pilha
        int ponteirodaPilha; // apontador do topo da pilha
        int tamanho; // espaço de memória reservado para o objeto

    public:
        CPilha(int);// construtor com parâmetros
        CPilha(); // construtor sem parâmetros
        ~CPilha(); 
        CPilha (const CPilha<T>&);

        template<typename T1>        
        friend istream& operator>>(istream&, CPilha<T1>&);
        template<typename T1>
        friend ostream& operator<<(ostream&, const CPilha<T1>&);

        CPilha& operator=(const CPilha&);

        bool pop (T &pop_to); 
        bool push (T push_this);
};

template<typename T>
CPilha<T>::CPilha(int p){
    ponteirodaPilha = -1;
    if(p>0)
        tamanho = p;
    else
        tamanho = 10;
    dados = new T[tamanho];
}

template<typename T>
CPilha<T>::CPilha(){
    ponteirodaPilha = -1;
    tamanho = 10;
    dados = new T[tamanho];
}

template<typename T>
CPilha<T>::~CPilha(){
    delete [] dados;
}

template<typename T>
CPilha<T>::CPilha(const CPilha& p){
    ponteirodaPilha = p.ponteirodaPilha;
    tamanho = p.tamanho;
    dados = new T[tamanho];
    for(int i = 0; i <= ponteirodaPilha ; i++)
        dados[i] = p.dados[i];
}

template<typename T>
CPilha<T>& CPilha<T>::operator=(const CPilha& p){
    delete [] dados;
    ponteirodaPilha = p.ponteirodaPilha;
    tamanho = p.tamanho;
    dados = new T[tamanho];
    for(int i=0; i<tamanho; i++)
        dados[i] = p.dados[i];
    return *this;
}

template<typename T>
bool CPilha<T>::pop(T &pop_to){ //remover
    if (ponteirodaPilha == -1) 
        return false;
    pop_to = dados[ponteirodaPilha--];
    return true;
}

template<typename T>
bool CPilha<T>::push(T push_this){ //colocar
    if (ponteirodaPilha == tamanho-1) 
        return false;
    dados[++ponteirodaPilha] = push_this;
    return true;
}

template<typename T>
istream& operator>>(istream& in, CPilha<T>& p){
    T aux;
    p.ponteirodaPilha = -1;

    cout << "Dados da Pilha: ";
    for(int i=0; i<p.tamanho; i++){
        in >> aux;
        if(!p.push(aux)) //caso nao consiga inserir
            break;
    }
    return in;
}

template<typename T>
ostream& operator<<(ostream& out, const CPilha<T>& p){
    for(int i=0; i<p.tamanho; i++){
        out << p.dados[i] << " ";
    }
    return out;
}

#endif