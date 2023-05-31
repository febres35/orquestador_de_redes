#include <iostream>

#include "headers/Tree.h"
using std::cout;
using std::cin;
using std::fixed;


int main(void){
    
    Tree<int> a;
    int valor;
    cout << "Escriba 10 valores integer: "<<endl;
    for (int i = 0; i< 10; i++){
        cin>>valor;
        a.insert(valor);
    }


    cout << "Recorrido preOrden: \n";
    a.preOrden();
    cout <<endl;


    cout << "\nRecorrido inOrden: \n";
    a.inOrden();
    cout <<endl;

    cout << "\nRecorrido postOrden: \n";
    a.postOrden();
    cout <<endl;


    return 0;
}