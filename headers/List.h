#ifndef LIST_H
#define LIST_H

#include <iostream>
using std::cout;
using std::cin;

#include <new>
#include "../headers/Node.h"

template <class T> 
class List {
    /**
     * @brief plantilla de List, se tomo como referencia el libro de
     * los @author's Harvey M. Deitel Paul J. Deitel pero se agregaron otras cosas.
    */
    public:
        List();
        List(T);
        ~List();
        bool isEmpty() const;
        unsigned long getId() const;
        T *getHead();
        void setHead(const Node<T> *);
        Node<T> *getTail();
        void setTail(const Node<T> *);
        Node<T> get(unsigned long);
        void insert(unsigned long = 0, const T);
        void order(Node<T> *);
        void Delete(unsigned long, T &) const;
        void Delete();
        unsigned long Size() const;
        void print() const;       

    private:
        unsigned long size;
        static unsigned long _id;
        Node<T> *head, *tail;
};

#endif