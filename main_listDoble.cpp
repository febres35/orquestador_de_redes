#include "headers/ListDoble.h"

template<class T>
void probarList(ListDoble<T> &, const std::string &);
void instruccione();
using std::cin;

int main(void ){
    
    ListDoble<int> list;
    probarList(list, "integer");
    list.printList();

    return 0;
}

template<class T>
void probarList(ListDoble<T> &list, const std::string &nombreType){
    cout << "Probando una Lista de valores"<< nombreType <<"\n";
    instruccione();
    int option;
    T valor;
    T aux;
    long _size;

    do{
        cout <<"? ";
        cin>>option;
        switch (option)
        {
        case 1:
            cout << "Escriba "<< nombreType << ": ";
            cin >> valor;
            list.insert(valor, 1);
            list.printList();
            break;
        case 2:
            cout << "Escriba "<< nombreType << ": ";
            cin >> valor;
            _size = list.size()+1;
            list.insert(valor, _size);
            list.printList();
            break;

        case 3:
            list.removeHead(aux);
            cout <<  valor << " se quito de la lista\n";

            list.print();
            break;
        case 4:
            _size = list.Size();
            list.Delete(_size, aux);
            if (valor){
                cout <<  valor << " se quito de la lista\n";
            }
            list.print();
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