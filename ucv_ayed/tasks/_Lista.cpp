#include <iostream>
#include "Nodo.cpp"
using namespace std;



/// @brief estructura dinamica lineal.
/// @author Leonardo Febres
/// @date 06/05/2023
class List{
    public:
        List();
        List(int);

        ~List();
        void add(int); // agrega un nodo al final de la list.
        void remove(int); // buscar por id en la lista y elimina el nodo
        void print(); // imprime toda la lista. 
        int getSize(); // imprime el tamaño de la lista. 
        Nodo *getFront(); // retorna la informacion el primer nodo
        void setFront(int); // modifica la informacion del primero de la lista
        int getRear(); // retorna la informacion del ultimo de la lista
        void setRear(int); // modifica la informacion del ultimo de la lista
        int get(int); // consulta la informacion del nodo, al que pertenece el id
        void set(int, int); // modifica el nodo al que pertenece el id.
        void addNodo(Nodo*); // agrega un nodo al final de la lista
        void printNodo(Nodo*); 
        Nodo *getNodo(int);
        Nodo *getNodo(int, Nodo *&);
        void insert(int, Nodo*); //inserta un nodo despues del nodo con el id indicado. 
        bool isEmpty();
        void removeNodo();
        

    
    private:
        Nodo *front, *rear; // front inicio de la lista, rear: fin de la lista. 
        int size;
        int id;
        static int _Identity;
};

/**Definicion de las funciones de la clase List
 * 
*/


/// @brief Inicializa los datos estaticos.size el tamaño de la lista e identificador de cada objeto de tipo Nodo,\
            _Identity identificador de las instancias de la lista.
/// @author Leonardo Febres
/// @date 06/05/2023
//int List::size = 0; //contador de instancias de la clase list
int List::_Identity = 0;



/// @brief Constructor de la clase List.
/// @author Leonardo Febres
/// @date 06/05/2023
List::List(){
    size = 0;
    _Identity++;
    this->id=_Identity;
    front = NULL;
    rear = NULL;
}


/// @brief constructor de la clase List con el primer objecto de tipo nodo, el cual se inicializa con el parametro diametro.
/// @param object type int.
/// @author Leonardo Febres
/// @date 06/05/2023
List::List(int diametro){
    /**
     * Se suma 1 a size, haciendo refenrencia al objeto que se creara en la lista.
     * se incrementa el identificador de la clase.
     * se inicializa el nodo con  @param diametro y @param size 
     * 
    */
    _Identity++; 
    id=_Identity;
    front = new Nodo(diametro, this->size);
    rear = front;        
}


List::~List(){
    /**
     * @brief destructor de la clase.
     * @author Leonaro Febres
     * @date 06/05/2023
    */
    _Identity--;
    clog<< "\nSe procede a eliminar toda la lista. "<<endl;
}

int List::getSize(){

    /**
     * @brief consulta el numero de objeto que contiene la lista.
     * @return object type int.
     * @author Leonardo Febres
     * @date 06/05/2023
    */
    return size;
}

Nodo *List::getFront(){
    /**
     * @brief retorna la informacion del primer nodo.
     * @return object type point Nodo.
     * @author Leonardo Febres
     * @date 06/05/2023
    */
    return front;
}


void List::setFront(int diametro){
    /**
     * @brief modifica la informacion del primer nodo.
     * @param object type int.
     * @author Leonardo Febres
     * @date 06/05/2023
    */
    front->setDiametro(diametro);
}

int List::getRear(){
    /**
     * @brief retorna la informacion del ultimo nodo.
     * @return object type int.
     * @author Leonardo Febres
     * @date 06/05/2023
    */
    return rear->getDiametro();
}

void List::setRear(int diametro){
    /**
     * @brief modifica la informacion del ultimo nodo.
     * @param object type int.
     * @author Leonardo Febres
     * @date 06/05/2023
    */
    rear->setDiametro(diametro);
}

int List::get(int id){
    /**
     * @brief retorna la informacion del nodo(diametro), al que pertenece el id. si es 0, entonces no existe el id en la lista.
     * @param object type int.
     * @author Leonardo Febres
     * @date 06/05/2023
    */
    Nodo *nodo = getNodo(id);
    if (nodo == NULL){
        return 0;
    }
    return nodo->getDiametro();
}


void List::set(int id, int diametro){
    /**
     * @brief modifica el nodo(diametro), al que pertenece el id. si es 0, entonces no existe el id en la lista.
     * @param object type int.
     * @author Leonardo Febres
     * @date 06/05/2023
    */
    Nodo *nodo = getNodo(id);
    if (nodo == NULL){
        return;
    }
    nodo->setDiametro(diametro);
}


void List::add(int diametro){
    /**
     * @brief crea un objeto de tipo nodo con la diametro del parametro y colocalo al final de la lista. 
     * @param diametro object type int.
     * @param size se utiliza para asignarle el id al nodo. segun su posicion en la lista
     * @author Leonardo Febres
     * @date 06/05/2023
    */
    this->size++;
    Nodo *nodo = new Nodo(diametro, getSize());
    if(!front){
        front = nodo;
        rear = nodo;
    }else{
        
        rear->setNext(nodo);
        rear = nodo;
    }
}



void List::remove(int id){
    /**
     * @brief busca por id en la lista y elimina el nodo.
     * @param id object type int.
     * @author Leonardo Febres
     * @date 06/05/2023
    */

    if (!isEmpty()){
        Nodo *prev = NULL;
        Nodo *aux = front;
        while(aux != NULL && aux->getId()!= id){
            prev = aux;
            aux = aux->getNext();
        }
        if(aux == NULL){
            cout << "El nodo " << id << " no ecnontrado<<endl";
        }else{ 
            if (prev == NULL){
                front = aux->getNext();
                delete aux;
            }else{
                prev->setNext(aux->getNext());
                delete aux;
            }
        }
        size--;
    }
}

void List::print(){
    /**
     * @brief imprime la lista.
     * @author Leonardo Febres
     * @date 06/05/2023
    */   
    Nodo *nodo = front;
    while(nodo){
        cout << nodo->getDiametro() << " ";
        nodo = nodo->getNext();
    }
    cout << endl;
}

void List::addNodo(Nodo *nodo){
    /**
     * @brief agrega un nodo al final de la lista. pero no la referencia, crea la misma data y el mismo id del nodo que se esta pasando para tener una copia en la lista.
     * @param nodo object type point Nodo.
     * @author Leonardo Febres
     * @date 06/05/2023
    */
   if (nodo){
        size++;
        Nodo *aux = new Nodo(nodo->getDiametro(), nodo->getId());
        if(!front){
            front = aux;
            rear = aux;
        }else{
            rear->setNext(aux);
            rear = aux;
        }

    }else{
        clog << "nodo vacio "<<endl;
    }
}


void List::printNodo(Nodo *nodo){
    /**
     * @brief imprime el nodo.
     * @param nodo object type point Nodo.
     * @author Leonardo Febres
     * @date 06/05/2023
    */
    cout << nodo->getDiametro() << " ";
}

Nodo *List::getNodo(int id){
    /**
     * @brief busca por id en la lista y retorna el nodo.
     * @param id object type int.
     * @author Leonardo Febres
     * @date 06/05/2023
    */

    Nodo *nodo = front;
    while(nodo){
        if(nodo->getId() == id){
            return nodo;
        }
        nodo = nodo->getNext();
    }
    return NULL;
}   

Nodo *List::getNodo(int id, Nodo *&prev){ 
    
    /**
     * @brief busca por id en la lista y retorna el nodo. se utiliza en la funcion remove.
     * @param id object type int.
     * @param prev object type point Nodo. utilizado para almacenar el nodo anterior
     * @author Leonardo Febres
     * @date 06/05/2023
    */

    Nodo *nodo = front;
    while(nodo){
        if(nodo->getId() == id){
            if ( nodo->getNext()-> getId() == id){
                prev = nodo;
            }
            return nodo;
        }

        nodo = nodo->getNext();
    }
    return NULL;
}   


void List::insert(int id, Nodo *nodo){
    /**
     * @brief Se utiliza para agregar un nodo despues del nodo con el id indicado.
     * @param id object type int. se utiliza para buscar el nodo con el id
     * @param nodo object type point Nodo. nodo que se asignara despues del nodo al que le pertenece el id.
     * @author Leonardo Febres
     * @date 06/05/2023
    */
    size++;
    Nodo *nodo2 = getNodo(id);
    nodo->setNext(nodo2->getNext());
    nodo2->setNext(nodo);
    //nodo2->setNext(nodo->getNext());
}


bool List::isEmpty(){
    /**
     * @brief verifica si la lista esta vacia. 
     * @return object type boolean, si esta vacia la lista retrn true de lo contrario retorna false.
     * @author Leonardo Febres
     * @date 06/05/2023
    */
    return (front == NULL);
}

void List::removeNodo(){
    /**
     * @brief se utiliza para remover toda la lista.
     * @author Leonardo Febres
     * @date 06/05/2023
    */
    while (front != NULL){
        Nodo *nodo = front;
        size--;
        front = nodo->getNext();
        delete nodo;
    }
    rear = NULL;
}