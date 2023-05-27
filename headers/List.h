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
        long getId() const;
        Node<T> * getHead();
        void setHead(const Node<T> *);
        Node<T> *getTail();
        void setTail(const Node<T> *);
        Node<T> * get(long);
        void insert(T, long = 0);
        void order(Node<T> *);
        void Delete( long, T &);
        void Delete();
        long Size() const;
        void print() const;       

    private:
        long _size;
        static long _id;
        Node<T> *head;
        Node<T> *tail;
};

#endif