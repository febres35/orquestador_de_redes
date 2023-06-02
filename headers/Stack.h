
#ifndef STACK_H
#define STACK_H

#include "List.h"

template <class T>
class Stack : private List<T> {
    public:
    void push(const T &datos){
        this->insert(datos, 1); 
    }

    bool pop(T &datos){
        this->Delete(1, datos);
        if(datos){
            return true;
        }
        return false;       
    }
    bool isEmptyStack() const{
        return this->isEmpty();
    }
    void printStack() const{
        this->print();
    }


};

#endif