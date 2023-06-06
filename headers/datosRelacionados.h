#ifndef DATOSRELACIONADOS_H
#define DATOSRELACIONADOS_H

#include<iostream>

#include "Dispositivo.h"
#include "Relacion.h"
#include "List.h"
#include <string.h>

using std::cout;

class DatosRelacionados {
    public:
        friend std::ostream& operator<<(const std::ostream&, const DatosRelacionados &);

        DatosRelacionados();
        bool setDispositivo(string, string);
        Node<Relacion> *getRelacion(string, bool = true);
        bool setRelacion(Dispositivo *, int, int, string);
        Dispositivo getSrcDisp() const;
        void printtRl();
           
    private:
        
        Dispositivo dispositivo;
        List<Relacion> rl;


        Node<Relacion> *getDispositivo(string, bool = true);
        Node<Relacion> *getRAux(Node<Relacion> *, char *, bool = true);
        bool comprar(char *, char *);
        
};

DatosRelacionados::DatosRelacionados(){
    
}

bool DatosRelacionados::setDispositivo(string hostName, string IP){
    if (!hostName.empty() && !IP.empty()){
        this->dispositivo.setHn(hostName);
        this->dispositivo.setIp(IP);
        cout << this->dispositivo<< "\n";
        return true;
    }
    return false;
}

Node<Relacion> *DatosRelacionados::getRelacion(string dato, bool tipo){
    /**
     * @brief Si @param tipo es true, entonces se buscara por hostname
     * sino entonces se buscara por IP, por default buscara por hostname.
    */
    Node<Relacion> *dt = 0;
    dt = getDispositivo(dato, tipo);
    if( dt == 0){
        cout << "No existe relacion.\n";
    }
    return dt;
}

Node<Relacion> *DatosRelacionados::getDispositivo(string dato, bool tipo){
    /**
     * 
     * @brief  busca con ayuda de la funcion getRAux el nodo
     * en la lista de relacion que contiene al dispositivo con el mismo 
     * dato siendo el @param tipo quien define si es hostname o ip.
     * @return Node<Relacion>
     *
     * */

    if(!rl.isEmpty()){
        
        Node<Relacion> *temp = rl.getHead();
        char *aux = new char[dato.length()+1];
        std::strcpy(aux, dato.c_str());
        Node<Relacion> *d = getRAux(temp, aux, tipo);
        
        return d;
    }
    return 0;
}

Node<Relacion> *DatosRelacionados::getRAux(Node<Relacion> *current, char *temp, bool tipo){
    /**
     * @brief busca el dispositivo que con el mismo hostname el cual debe ser unico. 
     * @return obj dispositivo or 0
     * recibe un nodo para extraer la informacion y un array de caracteres
     * que es el que se busca en la estructura. 
     * 
    */
    
    if(current != 0){
        Relacion *aux = new Relacion();
        *aux = current->getInfo();  //
        Dispositivo *x = aux->getDispositivo();
        if (tipo){
             if (comprar(x->getHn(), temp)){
                return current;
             }
        }else{
            if (comprar(x->getIp(), temp)){
                return current;
            }
        }
        
        getRAux(rl.objInfo(current), temp);
    }
    return 0;
}

bool DatosRelacionados::comprar(char *local, char *dato){
    /**
     * @brief strcmp compara una array de caracteres. pertenece a la lib stirng
     * el @param local es el dato de la estructura donde se esta buscando
     * y el @param dato es el dato que se esta buscando a ver si existe en la estructura. 
    */
    return strcmp(local, dato) == 0;
}

bool DatosRelacionados::setRelacion(Dispositivo *dt, int p, int j, string conex){
    if (dt == 0){
        return false;
    }else{
        Relacion x;
        x.setDispositivo(dt);
        x.setPing(p);
        x.setJum(j);
        x.setConex(conex);
        this->rl.insert(x);
        return true;
    }
}

Dispositivo DatosRelacionados::getSrcDisp() const{
    return dispositivo;
    
}

void DatosRelacionados::printtRl(){
    rl.print();
}

std::ostream& operator<<(std::ostream& os, const DatosRelacionados &instancia){
    os << "Dispositivo: " << instancia.getSrcDisp();
    return os;
}

#endif