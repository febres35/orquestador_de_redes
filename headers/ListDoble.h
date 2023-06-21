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
        Node_a<T>* getHead();
        Node_a<T>* getTail();
        Node_a<T>* getNode(long id);
        long getId() const;     
        void printList();
        long size() const;


        //setter
        void setHead(Node_a<T>* head);
        void setTail(Node_a<T>* tail);
        
        void insert(const T, long = 0);
        
        //delete
        bool removeHead(T&);
        bool removeTail(T&);
        bool removeNode(long, T& );
        void clearList();


    private:
    void removeNode(Node_a<T>* node,T&);
    bool addNode(Node_a<T>* node, long = 0);
    Node_a<T>* head;
    Node_a<T>* tail;
    long _size;
    long id;
    static long _id;
    static long idNode;
};

template <class T>
long ListDoble<T>::_id = 0;

template <class T>
long ListDoble<T>::idNode = 0;

template <class T>
ListDoble<T>::ListDoble()
{
    head = NULL;
    tail = NULL;
    _id ++;
    id = _id;
    _size = 0;
}

template <class T>
ListDoble<T>::~ListDoble()
{
    ///cout << "Iniciando la eliminacion de la lista Doble enlazada ID: "<< id<<"\n";
    id--;
}

//getter
template<class T>
bool ListDoble<T>::isEmpty() const{
    return head == NULL;
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
        if(id > 0 && id <=_size){
            Node_a<T>* current = head;
            while (current != NULL){
                if (current->_id == id){
                    return current;
                }
                current = current->rightPtr;
            }
        }
        return NULL;
    }
}


template<class T>
void ListDoble<T>::printList(){
    Node_a<T> *current = this->head;
    if (this->head != NULL){
        while (current != NULL){
        //Se debe mantener el id del nodo. 
        //se procede a cambiar por motivos de pruebas.
        cout << current->dato << "\n";
        current = current->rightPtr;
        }
        cout << "\n";
    }
}

template <class T>
long ListDoble<T>::size() const{
    return _size;
}

template<class T>
long ListDoble<T>::getId() const{
    return id;
}



//setter

template<class T>
void ListDoble<T>::setHead(Node_a<T>* head){
    if (head != NULL){
        if (isEmpty()){
            head->leftPtr = NULL;
            head->rightPtr = NULL;
            this->head = head;
            this->tail = head;
         
        }else {
            head->leftPtr = NULL;
            head->rightPtr = this->head;
            this->head->leftPtr = head;
            this->head = head;
        }
        _size++;
        
    }
}

template <class T>
void ListDoble<T>::setTail(Node_a<T>* tail ){
    if (tail != NULL){
        if (isEmpty()){
            tail -> rightPtr = NULL;
            tail->leftPtr = NULL;
            this->head = tail;
            this->tail = tail;
            
        }else{
            tail -> rightPtr = NULL;
            this->tail->rightPtr = tail;
            tail->leftPtr = this->tail;
            this->tail = tail;
        }
        _size++;
        //No deberia ser necesario asignar el id del Nodo
        //idNode++;
        //tail->_id = idNode;
    } 
    
}


template<class T>
bool ListDoble<T>::addNode(Node_a<T>* node, long posicion){
    if (isEmpty()){
        node->leftPtr = NULL;
        node->rightPtr = NULL;
        this->head = node;
        this->tail = node;
        _size++;
        idNode++;
        node->_id = idNode;
        return true;
    }else{ if (posicion == 0){
        /**
         * Se coloca al final si no se indica la posicion.
         * 
        */
        node->leftPtr = this->tail;
        node->rightPtr = NULL;
        this->tail->rightPtr = node;
        this->tail = node;
        _size++;
        idNode++;
        node->_id = idNode;
        return true;
    }else { 
            Node_a<T>* current = head;
            for (int i = 0; i < posicion - 1 && current != NULL; i++){
                current = current->rightPtr;
            }
            if (current != NULL){
                node->leftPtr = current;
                node->rightPtr = current->rightPtr;
                current->rightPtr = node;
                if (current->rightPtr == NULL){
                    this->tail = node;
                }else{
                    node->rightPtr->leftPtr = node;
                }
                _size++;
                idNode++;
                node->_id = idNode;
                return true;
            }else{
                return false;
            }
        }
    }
}

template<class T>
void ListDoble<T>::insert(const T elem, long posicion){
    Node_a<T>* node = crear(elem);
    
    if (posicion >= 0){
        bool temp = addNode(node, posicion); 
        if (temp){
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
void ListDoble<T>::removeNode(Node_a<T>* node, T &data ){
    //funcion privada
    
    if (node->leftPtr != NULL ){
        node->leftPtr->rightPtr = node->rightPtr;
    }else {
        this->head = node->rightPtr;
    }
    if (node->rightPtr != NULL){
        node->rightPtr->leftPtr = node->leftPtr;
    }else {
        this->tail = node->leftPtr;
    }
    cout <<"Bandera " <<node->dato <<"\n";
    data = node->dato;
    this->_size--;
    delete node;
}

template<class T>
bool ListDoble<T>::removeHead(T &data){
    if (!isEmpty()){  
        Node_a<T>* temp = head;
        this->head = this->head->rightPtr;
        if (this->head != NULL){
            this->head->leftPtr = NULL;
        }else{
            this->tail = NULL;
        }
        data = temp->dato;
        this->_size--;
        delete temp;
        return true;
    }else{
        return false;
    }
}

template<class T>
bool ListDoble<T>::removeTail(T &data){
    if (!isEmpty()){
        Node_a<T>* temp = tail;
        tail = tail->leftPtr;
        if (tail != NULL){
            tail->rightPtr = NULL;
        }else{
            this->head = NULL;
        }
        data = temp->dato;
        this->_size--;
        delete temp;
        return true;
    }
    return false;
}

template<class T>
bool ListDoble<T>::removeNode(long id, T &data){

    /// revisar funcion.
    Node_a<T>* temp = getNode(id);
    // no se decrementa el size porque
    //removeNode lo hace.
    if (temp != NULL){
        return removeNode(temp, data);
        //cout << data;

    }else{
        cout << "No se encontro el nodo con id: " << id << "\n";
        return false;
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