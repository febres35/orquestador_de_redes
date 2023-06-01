#include <iostream>
#include<stdlib.h>
#include<fstream>

using std::cout;

#include "headers/Dispositivo.h"
#include "headers/List.h"
using std::ifstream;
using std::ios;

int main(void){
    ifstream f;
    f.open("Dispositivos.dat", ios::in );
    List<Dispositivo> q;


    if (f.fail() ){
        cout << "Open File fail";
    }else{
        
        string hostname, ip;
        while(!f.eof()){
            Dispositivo *temp = new Dispositivo();
            f >> hostname >> ip;
            temp->setHn(hostname);
            temp->setIp(ip);
            q.insert(*temp);
        }
        cout << left <<" ID "<< setw(5)<<" "<<" HOSTNAME "<<setw(10)<<" "<<" IP "<<endl;
        q.print();
    }

    f.close();
    return 0;
}