#include <iostream>

#include "headers/Tree.h"
#include "headers/Queue.h"
#include "headers/Stack.h"
#include "fUsoLibre/random.h"
using std::cout;
using std::cin;
using std::fixed;


int main(void){
    
    Tree<int> a;
    int valor;
    cout << "Escriba 10 valores integer: "<<endl;
    for (int i = 0; i< 10; i++){
        valor = Random(1, 30);
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

    Queue<int> q;

    cout << "Procesando pila de valores integer\n";

    for (int i = 0; i < 6; ++i) {
        q.enQueue(i);
        q.printQueue();
    }
    int deQueue;
    while(!q.isEmptyQueue()){
        q.deQueue(deQueue);
        cout << deQueue << " Se desapilo...\n";
    }

    Stack<int> p;

    cout << "Procesando pila de valores integer\n";

    for (int i = 0; i < 6; ++i) {
        p.push(i);
        p.printStack();
    }

    return 0;
}