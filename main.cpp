#include "headers/List.h"

template<class T>
void probarList(List<T> &, const std::string &);
void instruccione();

int main(void ){
    
    List<int> list;
    probarList(list, "integer");



    return 0;
}

template<class T>
void probarList(List<T> &list, const std::string &nombreType){
    cout << "Probando una Lista de valores"<< nombreType <<"\n";
    instruccione();
    int option;
    T valor;

    do{
        cout <<"? ";
        cin>>option;
        switch (option)
        {
        case 1:
            cout << "Escriba "<< nombreType << ": ";
            cin >> valor;
            list.insert(valor);
            list.print();
            break;
        case 2:
            cout << "Escriba "<< nombreType << ": ";
            cin >> valor;
            list.insert(list.Size()+1, valor);
            list.print();
            break;
        case 3:
            list.Delete(1, valor)
            cout <<  valor << " se quito de la lista\n";

            list.print();
            break;
        case 4:
            if(list.Delete(list->Size(), valor)){
                cout <<  valor << " se quito de la lista\n";
            }
            list.print();
            break;       
        default:
            break;
        }
    }while(opcion != 5);

    cout << "fin de la prueba de lista.\n\n";
}

void intruccion(){
    cout << "Escriba una de las siguiente opciones: \n";
    cout << "1. insertar al inicio de la lista \n";
    cout << "2. insertar al final de la lista \n";
    cout << "3. Eliminar al frente de la lista \n";
    cout << "4. Eliminar al final de la lista \n";


}