#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

template <class T>
class Queue : private List<T>{
    public:
        void enQueue(const T &datos){
            this->insert(datos, this->Size()+1);
        }

        bool deQueue(T &datos){
            this->Delete(1, datos);
            if(datos){
                return true;
            }
            return false;       
        }

        bool isEmptyQueue() const{
            return this->isEmpty();
        }

        void printQueue() const {
            this->print();
        }
};

#endif