#include<iostream>

//using std::cout;
//using std::cin;
//using std::endl;
//using std::ios;
//using std::cerr;
//using std::left;
//using std::right;
//using std::fixed;
//using std::showpoint;
#include<stdlib.h>
#include<fstream>
#include<iomanip>
//using std::setw;
//using std::setprecision;
#include<cstdlib> // prototipo de exit

//#include <string>
//using std::ifstream;

#include "headers/List.h"

using namespace std;

void mostrarLinea(string ,string);



int main(void){

    ifstream f;
    f.open("Dispositivos.dat", ios::in);

    if( f.fail() ){
        cerr <<"No se pudo abrir el archivo."<< endl;
        exit(1);
    }

    string hostname, ip;
    cout <<left << setw(10) << " Hostname "<< setw(13) <<"IP"<<endl <<fixed << showpoint;
    while(!f.eof()){
        f >> hostname>> ip;
        mostrarLinea(ip, hostname);
    }
    f.close();
    return 0;
}

void mostrarLinea(string ip, string hostname) {

        cout << left << setw(10) << hostname << setw(10) << ip << setw(13) << setprecision(2)<< right<< endl;
}