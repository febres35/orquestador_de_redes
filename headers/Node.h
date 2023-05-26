#ifndef NODE_H
#define NODE_H

template<class T> class List;

template<class T>
class Node{
    /**
     * @brief clase platilla de nodo que es amiga de lista
     * @author Harvey M. Deitel Paul J. Deitel
    */
    friend class List<T>; 
    
    public:
        Node(const T &);
        T getInfo() const;
        long ID() const;


    private:
        T info; // informacion 
        Node<T> *next; // nodo siguiente, que solo podra ser accedida por la clase lista.
        int _position;  // numero de position que se encuentra en la lista.
        static long _id;

};

template <class T>
long Node<T>::_id=0;

template <class T>
Node<T>::Node(const T &info):info(info),next(0), _position(0){
    /**
     * @brief constructor de la platilla node
     * 
    */
   _id++;

}

template <class T>
T Node<T>::getInfo() const {
    return info;
}

template <class T>
long Node<T>::ID() const{
    return _id;
}

#endif