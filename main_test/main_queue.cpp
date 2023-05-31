#include <iostream>

#include "headers/Queue.h"

int main(void){
    Queue<int> p;

    cout << "Procesando pila de valores integer\n";

    for (int i = 0; i < 6; ++i) {
        p.enQueue(i);
        p.printQueue();
    }
    int deQueue;
    while(!p.isEmptyQueue()){
        p.deQueue(deQueue);
        cout << deQueue << " Se desapilo...\n";
    }

    return 0;
}