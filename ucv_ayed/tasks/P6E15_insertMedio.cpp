#include <iostream>
//#include "Nodo.cpp"
#include "Lista.cpp"


using namespace std;

void insert_a_la_mitad(List *& ,int);

int main(){
    //crar nodo;
    Nodo *n;
    n = new Nodo();

    int x = n->getDiametro();
    cout << x << endl;


    return 0;
}

void insert_a_la_mitad(List *&lista, int info){
    /**
     * @brief La siguiente funcion agrega una la mitad \
     * de la lista la inforacion indicada. si el tamaño
     * de la lista es impar el nuevo nodo se colocara exactamente
     * a la mitad de lo contrario se colocara en la mitad superior al
     * redondear. 
     * @author Leonardo Febres
     * @date 21/05/2023
     * 
    */
    if (lista){
        int medioList = lista->getSize();
        medioList /= 2;
        if (medioList % 2 != 0){
            medioList -=1; // si la lista es de tamaño impar
                            // forzar a que la mitad sea 1 mas
        }
        Nodo *aux = lista->getFront();
        int contador = 1; // como se empieza en el primer nodo, el contador debe empezar en 1
        while(aux->getNext() && contador < medioList){ // cuando contador este en medioList, quiere decir que esta en una posicion 1- si el tamaño de la lista fue impar, si fue par, con el elemento que se incluira quedaria un numero impar entonces es indiferente si se coloca o ma arriba o mas abajo, en este caso se colocara por encima.
            contador++;
            aux = aux->getNext();
        }

        Nodo *newNodo = new Nodo(info, lista->getSize()+1);
        lista->insert(aux->getId(), newNodo);
    }
}