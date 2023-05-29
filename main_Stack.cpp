#include <iostream>

#include "headers/Stack.h"

int main(void){
    Stack<int> p;

    cout << "Procesando pila de valores integer\n";

    for (int i = 0; i < 6; ++i) {
        p.push(i);
        p.printStack();
    }
    return 0;
}