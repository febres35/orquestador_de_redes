#ifndef TREE_H
#define TREE_H


#include<iostream>
using std::cout;
using std::endl;

#include<new>
#include "Node_a.h"

template<class T>
class Tree{
    public:

        Tree();
        void insert(const T &);
        /** @brief Tipos de Recorridos */
        void preOrden() const;
        void inOrden() const;
        void postOrden() const;

    private:
        Node_a<T> *rootPtr;

        /** @brief funciones de utileria */
        void insertAux(Node_a<T> **, const T &);
        void preOrdenAux(Node_a<T> * ) const;
        void inOrdenAux(Node_a<T> *) const;
        void postOrdenAux(Node_a<T> *) const;
};


template<class T>
Tree<T>::Tree():rootPtr(0){

}

template<class T>
void Tree<T>::insert(const T &d){
    insertAux(&rootPtr,d);
}

template<class T>
void Tree<T>::insertAux(Node_a<T> **ptr, const T &d){
    /**
     * @brief Funcion de utileria llamada por la funcion insert
     * recibe un apuntador de un apuntador para modificar el valor de ese puntero.
     * @param Node_a** 
     * @param const_datos
     * 
    */

    if ((*ptr) == 0){
        /** evalua si el subarbol esta vacio.*/
        *ptr = new Node_a<T>(d);
    }else{
        if(d < (*ptr)->dato){
            /**  avanza por el lado izquierdo. */
            insertAux(&(*ptr)->leftPtr, d);
        }else{
            /**  avanza por el lado derecho */
            if (d > (*ptr)->dato){
                insertAux(&(*ptr)->rightPtr, d);
            }else{
                /** Dato duplicado es decir d =  (*current)->dato*/
                cout << d << " Duplicado\n";
            }           
        }
    }
}

template<class T>
void Tree<T>::preOrden() const{
    preOrdenAux(rootPtr);
}

template<class T>
void Tree<T>::preOrdenAux(Node_a<T> *ptr) const{
    if(ptr != 0){
        cout << ptr->dato << ' ';
        preOrdenAux(ptr->leftPtr);
        preOrdenAux(ptr->rightPtr);
    }
}

template<class T>
void Tree<T>::inOrden() const{
    inOrdenAux(rootPtr);
}

template<class T>
void Tree<T>::inOrdenAux(Node_a<T> *ptr) const{
    if(ptr != 0){
        inOrdenAux(ptr->leftPtr);
        cout<< ptr->dato<< ' ';
        inOrdenAux( ptr->rightPtr);
    }
}

template<class T>
void Tree<T>::postOrden() const{
    postOrdenAux(rootPtr);
}


template<class T>
void Tree<T>::postOrdenAux(Node_a<T> *ptr) const{
    if (ptr != 0){
        postOrdenAux(ptr->leftPtr);
        postOrdenAux(ptr->rightPtr);
        cout << ptr->dato <<' ';
    }
}
#endif