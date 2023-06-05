#include <iostream>

#include "headers/Stack.h"

void combinar(Stack<float> &, Stack<float> &);

void combinarAux(Stack<float>&, Stack<float> &, float);

int main(void){
    Stack<float> s1; 
    Stack<float> s2;
    cout << "Procesando pila de valores integer\n";
    float s[] = { 20.8, 5.5, 10.2, 38.8, 20.5, 25.2};

    s1.push(s[0]);
    s1.push(s[1]);
    s1.push(s[2]);

    s2.push(s[3]);
    s2.push(s[4]);
    s2.push(s[5]);

    combinar(s1, s2);

    s1.printStack();
    s2.printStack();
    return 0;
}


void combinar(Stack<float> &s1, Stack<float> &s2){
    float temp;
    if (!s1.isEmptyStack()){
        s1.pop(temp);
        combinar(s1,s2);
        combinarAux(s2, s1, temp);  
    }
    
}

void combinarAux(Stack<float> &s1, Stack<float> &resultado, float temp){
    float aux;
    if(!s1.isEmptyStack()){
        s1.pop(aux);
        resultado.push(temp+aux);
    }
}