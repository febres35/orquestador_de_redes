#include <iostream>
using namespace std;
/**15.
 *  En una ferretería se venden segmentos de cable, los clientes suelen pedir varios metros de
cable, por lo que siempre quedan pedazos cortos de cable sin vender. Por ello se ha decidido
soldar todos los pedazos para vender cables de ​ 100 ​ metros, a un precio razonablemente
menor. El ferretero entiende que este problema es complejo, pues tiene que tomar un
conjunto que pedazos de cable que sumen exactamente ​ 100 ​ metros. Por esa razón el
ferretero recurre a los estudiantes de AYED para que le resuelvan su problema, que en
resumen consiste en: dada las longitudes de cada uno de los n pedazos de cable existentes,
indicar si se puede generar un cable de ​ 100 ​ metros, y en dado caso, saber qué segmentos de
cable se soldaron para generar uno de ​ 100 ​ metros con la menor cantidad de soldaduras
posibles, para mantener los bajos costos.
 * 
*/

/** Razonamiento:
 * 
 * Dada una lista de diametros de cable, se debe buscar entre la lista las sumas parciales
 * de los retazos que lleguen a los 100m.
 * 
 * paso 1: Registrar una lista de diametros de retazos de cable. Listo
 * paso 2: crear una funcion sumaParcial para realizar las permutaciones.
 * paso 3: crear el esquema de backtraking para la busqeda de solucion.
*/


class Nodo{
    /**
    * @brief Class que contendra la informacion de cada.
    * @author: Leonardo Febres
    * @date 06/05/2023
    */
    public:
        Nodo();
        Nodo(int, int);
        ~Nodo();
        int getDiametro(); // consultar la informacion del nodo
        void setDiametro(int); // setear la informacio del nodo
        void setNext(Nodo *); // setear el nodo next de la clase.
        Nodo *getNext(); // retorna la dir de espacio en memoria al que apunta
        int getId(); // retorna el id 
        void setId(int);  

    private:
        int id; // identificador unico de cada instancia.
        int diametro; // informacion que alamcena la clase¿.
        Nodo *next; // nodo siguiente de la lista. 
        
};
/**
 * Definicion de las funciones de la clase Nodo
*/


/// @brief Inicializa el objeto vacia.
/// @author Leonardo Febres
/// @date 06/05/2023
Nodo::Nodo(){
     // incremetar el numero de instancias de la clase
    id = 0; // asignar el identificador a la clase, segun el orden en que se creo
    diametro = 0; 
    next = NULL;
}


Nodo::Nodo(int diametro, int id){
    /**
     * @brief Inicializa el nodo con una clave foranea pertenecesiente a la posicion de la\
       estructura de tipo lista(List), cola(Queen), pila(stack).
     * @param diametro diametro del objeto cable.
     * @param id identificador del objeto.
     * @author Leonardo Febres
     * @date 06/05/2023
    */


    this->id = id; // se le asigna el numero de oren al que pertenece en la lista, cola o pila.
    this->diametro = diametro;
    this->next = NULL;
}


/// @brief Destructor de la clase.
/// @author Leonardo Febres
/// @date 06/05/2023
Nodo::~Nodo(){
    cout << "Se procede a eliminar el nodo " << id << " con "<< diametro << "m."<< endl;
}


int Nodo::getDiametro(){
/** @brief consulta el diametro de objeto.
    @return diametro de cable.
    @author Leonardo Febres
    @date 06/05/2023
*/
    return diametro;
}

/// @brief Settear las dimensiones del objeto. 
/// @param diametro 
/// @author Leonardo Febres
/// @date 06/05/2023
void Nodo::setDiametro(int diametro){
    this->diametro = diametro;
}


/// @brief settear el objeto que le sigue al objento actual
/// @param next nodo u objeto que le sigue.
/// @author Leonardo Febres
/// @date 06/05/2023
void Nodo::setNext(Nodo *next){
    this->next = next;
}

/// @brief Consulta el objeto al que apunta el next.
/// @return object type Nodo.
/// @author Leonardo Febres
/// @date 06/05/2023
Nodo *Nodo::getNext(){
       return next;
}

/// @brief consulta el identificador del objeto.
/// @return object type int.
/// @author Leonardo Febres
/// @date 06/05/2023
int Nodo::getId(){
    return id;
}

/// @brief Settear el identificador del objeto.
/// @param object type int.
/// @author Leonardo Febres
/// @date 06/05/2023
void Nodo::setId(int id){
    this->id = id;
}

/**Prototipo de la clase List
 * 
*/

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
        void setNodo(int, Nodo*);
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


void List::setNodo(int id, Nodo *nodo){
    /**
     * @brief Se utiliza para agregar un nodo despues del nodo con el id indicado.
     * @param id object type int. se utiliza para buscar el nodo con el id
     * @param nodo object type point Nodo. nodo que se asignara despues del nodo al que le pertenece el id.
     * @author Leonardo Febres
     * @date 06/05/2023
    */
    Nodo *nodo2 = getNodo(id);
    nodo2->setNext(nodo->getNext());
    nodo->setNext(nodo2);
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

int Random(int, int);

void addEList(List *);

void finSum(Nodo *, int, int , int, List *&);

int main_old (){
    /**
     * @brief la venta de retasos de cable, empates de cable a menor precio.
     * @author Leonardo Febres
     * @date 06/05/2023
    */

    List *lista = new List();
    addEList(lista);
    List *solucion = new List();
    lista->print();
    finSum(lista->getFront(), lista->getSize(), 0, 100, solucion);
    //lista->removeNodo();
    
    return 0;
}

int Random(int i, int j) {
    /**
     * @brief genera un numero aleatorio entre @param i y @param j
     * @author Leonardo Febres
     * @date 06/05/2023
    */
    return i+rand() % j;
}

void addEList(List *lista){
    /**
     * @brief agregar de manera aleatoria diametros a una lista de retazos de cable.
     * @author Leonardo Febres
     * @date 06/05/2023z
    */

    List *list = lista;
    for (int i = 0; i < 20; i++){
        list->add(Random(1, 30));
    }
}

void finSum(Nodo *lista, int len, int parcial, int total, List *&solucion)
{
    if (!solucion){
        solucion = NULL;
    }
    /*******************************/

    if ( parcial == total)
    {
        cout << "imprimiendo: ";
        solucion->print();
        /************************/
    }else
    {
        for (int i = 0; i < len; i++)
        {
            if(lista){ 
                if ( parcial + lista->getDiametro() <= total) // la solucion parcial sigue siendo menor que el total.
                {
                    if (solucion->get(lista->getId()) == 0 )// Es candidato para la solucion.
                    {   
                        
                        solucion->addNodo(lista);
                        solucion->print();
                        finSum(lista, len,  parcial + lista->getDiametro(), total, solucion);
                        solucion->removeNodo();
                        
                    }
                    
                    
                } 
                  
            }
            lista = lista->getNext();


             
        }
            
    }
}

/* se debe adecuar la funcion.
void finSum(int *&arr, int len, int parcial, int total, nodo *&root){
		if (total == parcial){
				setPrint(root);
		}else{
				for (int i = 0; i < len; i++){
						if (parcial + arr[i] <= total ) {
								 if (!existe(arr[i], root)) {
									addset(arr[i], root);
									finSum(arr, len, parcial+arr[i], total, root);
									removeSet(root);
									
						}
				}
				
		}
}
}
*/

/*
bool existe(int x, List *lista){
    Nodo *nodo = lista->getNodo(x);
    if (nodo){
        return true;
    }
    return false;
}

*/

