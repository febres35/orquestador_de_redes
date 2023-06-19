#include "headers/ListDoble.h"

template<class T>
void probarList(ListDoble<T> &, const std::string &);
void instruccione();
using std::cin;
#include <new>

int main(void ){
    
    ListDoble<int> list;
    
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    int temp;
    list.removeNode(10, temp);
    std::cout << temp << "\n";
    list.printList();
    //probarList(list, "integer");

    return 0;
}

template<class T>
void probarList(ListDoble<T> &list, const std::string &nombreType){
    cout << "Probando una Lista de valores"<< nombreType <<"\n";
    instruccione();
    int option;
    T valor;
    T aux;

    do{
        cout <<"? ";
        cin>>option;
        switch (option)
        {
        case 1:
            cout << "Escriba "<< nombreType << ": ";
            cin >> valor;
            list.setHead(list.crear(valor));
            list.printList();
            break;

        case 2:
            cout << "Escriba "<< nombreType << ": ";
            cin >> valor;
            list.setTail(list.crear(valor));
            list.printList();
            break;

        case 3:
            list.removeHead(aux);
            cout <<  aux << " se quito de la lista\n";
            list.printList();
            break;
   
        case 4:
            list.removeTail(aux);
            if (valor){
                cout <<  aux << " se quito de la lista\n";
            }
            list.printList();
            break;  

        case 5:

            cout << "Saliendo...\n";
            break;
        
        default:
            cout << "Opcion no valida.\n";
            break;
        }
    }while(option != 5);

    cout << "fin de la prueba de lista.\n\n";
}

void instruccione(){
    cout << "Escriba una de las siguiente opciones: \n";
    cout << "1. Insertar al inicio de la lista \n";
    cout << "2. Insertar al final de la lista \n";
    cout << "3. Eliminar al frente de la lista \n";
    cout << "4. Eliminar al final de la lista \n";
    cout << "5. Salir";


}