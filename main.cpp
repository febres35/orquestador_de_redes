#include<iostream>


#include<stdlib.h>
#include<fstream>
#include<iomanip>
#include<cstdlib> 
#include "headers/List.h"
#include "headers/datosRelacionados.h"


using namespace std;

void mostrarLinea(string ,string);
void LeerFile(List<DatosRelacionados> &);

int main(void){
    List<DatosRelacionados> lista;
    LeerFile(lista);
    lista.print();
    return 0;
}

void LeerFile(List<DatosRelacionados> &lista){
    ifstream f;
    f.open("Dispositivos.dat", ios::in);

    if( f.fail() ){
        cerr <<"No se pudo abrir el archivo."<< endl;
        exit(1);
    }

    int cont = 0;
    int nDispositivo = 0 ;
    int nRelaciones = 0;
    
    while (!f.eof())
    {   
        DatosRelacionados temp;
        string hn, ip;
        cont++;
        if (cont == 2){
            f>>nDispositivo;
        }else if (cont <= nDispositivo+2 && cont > 2  ){
            f >> hn >> ip;
            bool aux = temp.setDispositivo(hn, ip);
            cout << temp <<" ";
            if(aux){
                //lista.insert(temp);
            }
        }else{
            string temp;
            std::getline(f, temp);
        }
    }
    f.close();

}

void mostrarLinea(string ip, string hostname) {

        cout << left << setw(10) << hostname << setw(10) << ip << setw(13) << setprecision(2)<< right<< endl;
}