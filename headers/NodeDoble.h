#ifndef NODEDOBLE_H
#define NODEDOBLE_H

#include "Node.h"

template<class T> class ListDoble;

template <class T>
class NodeDoble : private Node<T>{
        Node<T> *back;
};


#endif