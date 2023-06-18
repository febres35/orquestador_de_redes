#ifndef LISTDOBLE_H
#define LISTDOBLE_H

#include <iostream>

#include <new>
#include"Node_a.h"
using std::cout;
/**
    Nota:
        EL Id del nodo dara dentifica el nodo,
        Pero el id de la lista, puede permitr
        hubicar la lista donde se encuentra el
        pudiendo identificar mas rapido la ubicacion
        del nodo.

        Una consulta de nodo, puede estar relacionada
        con la lista donde se encuentra el nodo.
*/

template<class T>
class ListDoble 
{


    public:

        ListDoble(/* args */);
        ~ListDoble();

        Node_a<T>* crear(const T &);

        //getter
        bool isEmpty() const;
        long getNodeId(Node_a<T>* ) const;
        Node_a<T>* getHead();
        Node_a<T>* getTail();
        Node_a<T>* getNode(long id);
        long getId() const;     
        void printList();
        long size() const;

        //setter
        void setNodeId(long id);
        void setHead(Node_a<T>* head);
        void setTail(Node_a<T>* tail);
        void setId(long id);
        bool addNode(Node_a<T>* node, long = 0);
        void insert(T, long = 0);
        
        //delete
        void removeHead(T);
        void removeTail(T);
        void removeNode(long, T );
        void clearList();


    private:
    void removeNode(Node_a<T>* node,T data);
    Node_a<T>* head;
    Node_a<T>* tail;
    static long _size;
    long _id;
};

template <class T>
long ListDoble<T>::_size = 0;

template <class T>
ListDoble<T>::ListDoble()
{
    head = NULL;
    tail = NULL;
    _id = 0;
}

template <class T>
ListDoble<T>::~ListDoble()
{
    cout << "Iniciando la eliminacion de la lista Doble enlazada ID: "<< _id<<"\n";
}

//getter
template<class T>
bool ListDoble<T>::isEmpty() const{
    return head == NULL;
}

template<class T>
long ListDoble<T>::getNodeId(Node_a<T> *p) const{
    /**
        Validar su usabilidad
    */
   if (p != NULL){
    return p->_id;
   }
   return 0;
}

template<class T>
Node_a<T>* ListDoble<T>::getHead(){
    return head;
}

template<class T>
Node_a<T>* ListDoble<T>::getTail(){
    return tail;
}

template<class T>
Node_a<T>* ListDoble<T>::getNode(long id){
    if (isEmpty() ){
        return NULL;
    }else{
        Node_a<T>* p = head;
        while (p != NULL){
            if (p->_id == id){
                return p;
            }
            p = p->rightPtr();
        }
        return NULL;
    }
}

template<class T>
long ListDoble<T>::getId() const{
    return _id;
}

template<class T>
void ListDoble<T>::printList(){
    Node_a<T>* p = head;
    while (p != NULL){
        cout << p->_id() << " ";
        p = p->leftPtr;
    }
    cout << "\n";
}

template <class T>
long ListDoble<T>::size() const{
    return _size;
}

//setter
template<class T>
void ListDoble<T>::setNodeId(long id){
    _id = id;
}

template<class T>
void ListDoble<T>::setHead(Node_a<T>* head){
    if (isEmpty()){
        this->head = head;
        this->tail = head;
    }else {
        this->head->leftPtr = head;
        head->rightPtr = this->head;
        this->head = head;
    }
}

template <class T>
void ListDoble<T>::setTail(Node_a<T>* tail){
    if (isEmpty()){
        this->head = tail;
        this->tail = tail;
    }else{
        this->head->rightPtr = tail;
        tail->leftPtr = this->tail;
        this->tail = tail;
    }
}

template<class T>
void ListDoble<T>::setId(long id){
    _id = id;
}

template<class T>
bool ListDoble<T>::addNode(Node_a<T>* node, long posicion){
    if (isEmpty()){
        this->head = node;
        this->tail = node;
        return true;
    }else{ if (posicion == 0){
        this->tail->rightPtr = node;
        node->leftPtr = this->tail;
        this->tail = node;
        return true;
    }else { 
            Node_a<T>* p = head;
            for (int i = 0; i < posicion - 1 && p != NULL; i++){
                p = p->rightPtr;
            }
            if (p != NULL){
                p->rightPtr->leftPtr = node;
                node->rightPtr = p->rightPtr;
                p->rightPtr = node;
                node->leftPtr = p;
                return true;
            }else{
                return false;
                }
            
        }
    }
}

template<class T>
void ListDoble<T>::insert(T elem, long posicion){
    Node_a<T>* node = crear(elem);
    
    if (posicion >= 0){
        bool temp = addNode(node, posicion); 
        if (temp){
            _size++;
        }else{
            cout << "Valide la posicion de la Lista Donde desea colocar el nodo\n";
        }   
    }else{
        cout << "No puede insertar el nodo en una posicion negativa\n";
        return;
    } 
}

template <class T>
Node_a<T> *ListDoble<T>::crear(const T &datos){
    return new Node_a<T>(datos);
}

//delete


template<class T>
void ListDoble<T>::removeNode(Node_a<T>* node, T data ){
    //funcion privada, modificar
    if (node != NULL){
        node->leftPtr->rightPtr = node->rightPtr;
        node->rightPtr->leftPtr = node->leftPtr;
        data = node->dato;
        delete(node);
    }
}

template<class T>
void ListDoble<T>::removeHead(T data){
    if (!isEmpty()){  
        Node_a<T>* temp = head;
        head = head->rightPtr;
        head->leftPtr = NULL;
        data = temp->dato;
        delete(temp);
    }
}

template<class T>
void ListDoble<T>::removeTail(T data){
    if (!isEmpty()){
        Node_a<T>* temp = tail;
        tail = tail->leftPtr;
        tail->rightPtr = NULL;
        data = temp->dato;
        delete(temp);
    }
}

template<class T>
void ListDoble<T>::removeNode(long id, T data){
    Node_a<T>* temp = getNode(id);
    if (temp != NULL){
        removeNode(temp);
    }
}

template<class T>
void ListDoble<T>::clearList(){
    T temp;
    while (!isEmpty()){
        removeHead(temp);
    }
}









#endif