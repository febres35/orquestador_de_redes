#ifndef NODE_A_H
#define NODE_A_H

template<class T> class Tree;

template <class T>
class Node_a{
    friend class Tree<T>;

    public:
        Node_a(const T &d):leftPtr(0),  rightPtr(0), dato(d){

        }

        T getDato() const{
            return dato;
        }

    private:
        Node_a<T> *leftPtr;
        Node_a<T> *rightPtr;
        T dato;
};



#endif
