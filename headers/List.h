#ifndef LIST_H
#define LIST_H

#include <iostream>
using std::cout;
using std::cin;

#include <new>
#include "Node.h"

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
        void Delete( long, T &) ;
        void Delete();
        long Size() const;
        void print() const;
        Node<T> *objInfo(Node<T> *instancia) const;     

    private:
        Node<T> *crear(const T &, long);
        long _size;
        static long _id;
        Node<T> *head;
        Node<T> *tail;
};




template <class T>
long List<T>::_id = 0;

template <class T>
List<T>::List():head(0),tail(0){
    _size = 0;
}

template <class T>
List<T>::List(T info):head(info),tail(info) {
    _size = 0;

}

template <class T>
List<T>::~List(){
    /**
     * @brief Desrtuctor de lista.
     * 
     * @author Leonardo Febres usando como refenrencia
     * el libre de Harvey M. Deitel Paul J. Deitel
    */
    cout<<"\n        Destruyendo Nodos\n             ..........\n";
    Node<T> *current = head; // Nodo actual
    Node<T> *tempNode; // Nodo temporal

    while(current != 0){
        tempNode = current;
        //cout << tempNode->info<< "\n";
        current = current->next;
        delete tempNode;
        _size--;
    }
    cout << "Se destruyeron todos los nodos\n";
}

template <class T>
bool List<T>::isEmpty() const{

    /**
     * @brief retorna true si la lista esta vacia
     * de lo contrario retorna false.
     * @author Leonardo Febres
    */
    return head == 0;
}

template <class T>
long List<T>::getId() const{
    /** 
     * @brief return the id
     * @return  id
     * @author Leonardo Febres
     * 
    */

   return this->_id;
}

template <class T>
Node<T> * List<T>::getHead(){
    /**
     * @brief return first element of list
     * @author Leonardo Febres
     * @return head
    */
    return this->head;
}

template <class T>
void List<T>::setHead(const Node<T> *head){
    /**
     * @brief set first _position
     * @param Node point
     * @author Leonardo Febres
    */
   this->head=head;
}

template <class T>
Node<T> * List<T>::getTail(){
    /**
     * @brief retorna el ultimo de la lista
     * @return head
     * @author Leonardo Febres
    */

   return this->tail;
}

template <class T>
void List<T>::setTail(const Node<T> *tail){
    /**
     * @brief set first position
     * @param Node point
     * @author Leonardo Febres
    */
   this->tail=tail;
}



template <class T>
Node<T> * List<T>::get(long p)
{
   /**
    * @brief busca el nodo por la posicion en la lita
    * @param position_node
    * @return Node point
    * @if 0: no se encontro
    * @author Leonardo Febres
    *
    */
 
   if(p == 0){
    return 0;
   }
    Node<T> *current = this->head;
   while(current!=0){
    if(current->getPosition() == p){
        return current;
    }
    current=current->next;
   }

   return 0;
}

template <class T>
void List<T>::insert(T info, long p){
    /**
     * @brief incluir en la lista, dada una posicion.
     * de no incluir la posicion en la lista se colocara al final 
     * siendo p = size+1
     * 
     * @param long<unsigned> posicion en la lita
     * @param info informacion del nodo
     * @author Leonardo Febres
    */

    
    _size++; // incrementa el numero de elementos de la lista
    Node<T> *newNode = crear(info, _size); //set info en nodo
    if (p == 0){ // en caso de que sea el parametro por default incluir al final.
        p = Size();
    }
    if(!isEmpty()){
        //cout <<newNode->getPosition()<<"\n";
        if(p == head->getPosition()){ // si p es igual a la posicion del head entonces se coloca al principio
            newNode->next = head;
            newNode->setPosition(head->getPosition());
            head = newNode;
            order(newNode);
        }else if (p > tail->getPosition()){ // si p es mayor que la ultima poicion de la lista entonces se incluye al final
            tail->next = newNode;
            tail = newNode;
            /* garantiza que si el parametro p es una posicion mayor a size+1 
            se asigne el valor correspondiente al ultimo de la lista.*/
        }else{
            Node<T> *current = head->next; //se crea el nodo actual para iterar la lista 
            while(current != 0  && current->getPosition() != p-1){
            /**
             * Por las validaciones previas se asume que la posicion
             * donde se colocara estara entre el primero y el ultimo
             * por esta razon solo se busca el anterior a la posicon
             * donde se colocara el nuevo nodo.
            */
                current = current->next;
            }
            newNode->next = current->next; // asignamos en la posicion de la lista buscada
            newNode->setPosition(current->next->getPosition()); // se asigna el numero de la posicion
            current->next = newNode; // se alinea el nuevo nodo en la lista
            order(newNode); // se ordena la lista.
        
        }
    }else{
            this->head =  newNode;
            this->tail = head;
        }

}


template <class T>
void List<T>::order(Node<T> *current){

    /**
     * @brief Ordena una lista desde un nodo dado
     * siendo el siguiente nodo el que se va a modificar 
     * el indice de la posicion.
     * modificanto el valor del atributo p
     * del nodo next.
     * @param Node actual con la posicion correcta.
     * @author Leonardo Febres
    */
    if( current != 0){
        long index = current->getPosition(); // index de posicion de los nodos 
        Node<T> *temp = current->next;// iterado de nodos
        while(temp != 0){ // mientras no haya llegado a final.
            index++; // incrementa el index ya que sera el nuevo valor del atributo _position
            temp->setPosition(index); // itera al siguiente nodo
            temp = temp->next;
        }
    }
}

template <class T>
void List<T>::Delete(long position, T &info) {
    /**
     * @brief elimina un nodo segun una posicion dada y salva la informacion\
     * en el parametro info.
     * @param long
     * @param info para salvar la informacion eliminada. 
     * @return info
     * @author Leonardo Febres
    */
   if( !isEmpty() ){
    Node<T> *current = head; // actual
    Node<T> *forme = 0; // anterior

    /** EN CASO DE QUE EL NUMERO P SEA MAYOR QUE EL TAÑO DE LA LISTA*/
    if(position > tail->getPosition() || position < 0){
        cout<< "Posicion fuera de alcance\n";
        return;
    }
    if(position > 0){ // si es 1 get retorna 0, por ende es el primer node
        forme = get(position-1);
            /*while(current != 0 && current->_position != p){ 
                forme = current;
                current = forme->next;
            } */
            /* Es el primero y por eso el get retorno 0*/
        if(forme == 0){ 
            head = current->next;
            info = current->getInfo();
            if(current->next){
                head->setPosition(1);
                order(head);
            }
            delete current;

        }else{ //cualquiera entre la lista.
            current = forme->next;
            forme->next = current->next;
            
            info = current->getInfo();
            order(forme);
            delete current;
        }
    }
    _size--;
   }
   
    
}

template<class T>
void List<T>::Delete(){
        /**
     * @brief Desrtuctor de lista.
     * @author Leonardo Febres usando como refenrencia
     * el libre de Harvey M. Deitel Paul J. Deitel
    */
    if(!isEmpty()){
        cout<<"Destruyendo Nodos ... \n";
        Node<T> *current = head; // Nodo actual
        Node<T> *tempNode; // Nodo temporal

        while(current != 0){
            tempNode = current;
            cout << tempNode->getInfo()<< "\n";
            current = current->next;
            delete tempNode;
            _size--;
        }
    }
    cout << "Se destruyeron todos los nodos\n";


}

template<class T>
long List<T>::Size() const{
    /**
     * @brief retorna el numero de elementos en la lista
     * @return unsigned long 
     * 
     * */
    return _size;
}

template<class T>
void List<T>::print() const{
    /**
     * @brief debido a que no se tiene
     * definido el tipo de dato es complicado
     * hacer la imprsion el wchar_t se usa como prueba.
     * @author Leonardo Febres
    */
    Node<T> *current = head;

    while (current != 0)
    {
        //cout <<current->getPosition() << " " << current->getInfo();
        cout << current->getInfo() <<" ";
        current = current->next;
    }
    
}

template <class T>
Node<T> *List<T>::crear(const T &datos,long x){
    return new Node<T>(datos, x);
}


template<class T>
Node<T> *List<T>::objInfo(Node<T> *instancia) const{
    /**
     * @brief recibe un nodo para retornar su siguiente en la lista.
    */
    return instancia->next;
}


#endif