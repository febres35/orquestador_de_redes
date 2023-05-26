#include <iostream>
using namespace std;


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
