#ifndef NODE_A_H
#define NODE_A_H

template<class T> class Tree;
template<class T> class ListDoble;

template <class T>
class Node_a{
    public:
    
        Node_a(const T &d):leftPtr(0),  rightPtr(0), dato(d), _id(0){

        }

        T getDato() const{
            return dato;
        }
        
        friend class ListDoble<T>;
        friend class Tree<T>;

    private:
        Node_a<T> *leftPtr;
        Node_a<T> *rightPtr;
        T dato;
        long _id;
        
        
};



#endif
