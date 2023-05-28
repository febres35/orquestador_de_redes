#include "/home/earp/trabajo/orquestador_de_redes/headers/List.h"



template <class T>
long List<T>::_id = 0;

template <class T>
List<T>::List():head(0),tail(0){

}

template <class T>
List<T>::List(T info):head(info),tail(info) {

}

template <class T>
List<T>::~List(){
    /**
     * @brief Desrtuctor de lista.
     * 
     * @author Leonardo Febres usando como refenrencia
     * el libre de Harvey M. Deitel Paul J. Deitel
    */
    if(!isEmpty()){
        cout<<"Destruyendo Nodos ... \n";
        Node<T> *current = head; // Nodo actual
        Node<T> *tempNode; // Nodo temporal

        while(current != 0){
            tempNode = current;
            cout << tempNode->info<< "\n";
            current = current->next;
            delete tempNode;
            _size--;
        }
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
   Node<T> *current = this->head;
   while(current!=0){
    if(current->_position == p){
        return current;
    }
   }

   return 0;
}

template <class T>
void List<T>::insert(T info, long p){
    /**
     * @brief incluir en la lista, dada una posicion.
     * de no incluir la posicion en la lita se colocara al final 
     * siendo p = size+1
     * 
     * @param long<unsigned> posicion en la lita
     * @param info informacion del nodo
     * @author Leonardo Febres
    */

    Node<T> *newNode = new Node<T>(info); //set info en nodo
    _size++; // incrementa el numero de elementos de la lista
    newNode->_position=p; // set _position
    if(p == head->_position){ // si p es igual a la posicion del head entonces se coloca al principio
        newNode->next = head;
        newNode->_position = head->_position;
        head = newNode;
        order(newNode);
        _size++;
    }else if (p > tail->_position){ // si p es mayor que la ultima poicion de la lista entonces se incluye al final
        tail->next = newNode;
        tail = newNode;
        newNode->_position=_size; /* garantiza que si el parametro p es una posicion mayor a size+1 
                                se asigne el valor correspondiente al ultimo de la lista.*/
        _size++;
    }else{
        Node<T> current = head->next; //se crea el nodo actual para iterar la lista 
        while(current->_position == p-1){
        /**
         * Por las validaciones previas se asume que la posicion
         * donde se colocara estara entre el primero y el ultimo
         * por esta razon solo se busca el anterior a la posicon
         * donde se colocara el nuevo nodo.
        */
            newNode = current->next; // asignamos en la posicion de la lista buscada
          
        newNode->_position = current->next->_position; // se asigna el numero de la posicion
        current->next = newNode; // se alinea el nuevo nodo en la lista
           
           
        }

        _size++;
        order(newNode); // se ordena la lista.
    
    }

}


template <class T>
void List<T>::order(Node<T> *current){

    /**
     * @brief Ordena una lista desde un nodo dado
     * siendo el siguiente nodo el que se va a modificar 
     * el indice de la posicion.
     * modificanto el valor del atributo _position
     * del nodo next.
     * @param Node actual con la posicion correcta.
     * @author Leonardo Febres
    */
    if( current != 0){
        unsigned long index = current->_position; // index de posicion de los nodos 
        Node<T> temp = current->next;// iterado de nodos
        while(temp->next != 0){ // mientras no haya llegado a final.
            index++; // incrementa el index ya que sera el nuevo valor del atributo _position
            temp->_position = index; // itera al siguiente nodo
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
    if(position > tail->_position){
        cout<< "Posicion fuera de alcance\n";
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
                info = current->info;
                head->_position=1;
                order(head);
                delete current;

            }else{ //cualquiera entre la lista.
                current = forme->next;
                forme->next = current->next;
                
                info = current->info;
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
            cout << tempNode->info<< "\n";
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
    Node<T> current = head;

    while (current != 0)
    {
        wchar_t c = current->info;
        cout <<current->_position << " - " << current->_id<<" - "<< c << "\n";
    }
    
}

