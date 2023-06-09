#include "../headers/List.h"

template<class T>
void probarList(List<T> &, const std::string &);
void instruccione();

int main(void ){
    
    List<int> list;
    probarList(list, "integer");
    list.print();



    return 0;
}

template<class T>
void probarList(List<T> &list, const std::string &nombreType){
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
            list.print();
            break;
        case 2:
            cout << "Escriba "<< nombreType << ": ";
            cin >> valor;
            _size = list.Size()+1;
            list.insert(valor, _size);
            list.print();
            break;

        case 3:
            list.Delete(1, aux);
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