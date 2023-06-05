#ifndef RELACION_H
#define RELACIION_H

#include <iostream>
#include"Node.h"
#include"Dispositivo.h"

class Relacion {
    public:
        friend std::ostream& operator<<(const std::ostream& os, const Relacion &dt);
        Relacion();
        Dispositivo *getDispositivo() const;
        int getPing() const;
        int getJum() const;
        std::string getConexion() const;

        void setPing(int);
        void setJum(int);
        void setConex(std::string);
        void setDispositivo(Dispositivo *);

    private:
        Dispositivo *ptrDispositivo;
        int ping;
        int jums;
        std::string conexion;       
};

Relacion::Relacion(){
    /**
     * @brief constructor
    */
    ptrDispositivo = 0;
    ping = 0;
    jums = 0;
    conexion = "";
}

Dispositivo *Relacion::getDispositivo() const{
    /**
     * @brief consultar el nodo al que apunta.
    */
    return this->ptrDispositivo;
}

int Relacion::getPing() const{
    /**
     * @brief consultar el ping
    */
    return this->ping;
}

int Relacion::getJum() const{
    /**
     * @brief valor de los saltos del nodo inicial al nodo de la relacion.
    */
   return jums;
}

std::string Relacion::getConexion() const{
    /**
     * @brief retorna el tipo de conexion
     * 5G, Fibra Optica, ambos
    */
    return this->conexion;
}

void Relacion::setDispositivo(Dispositivo *dt){
    /**
     * @brief asigna el nodo con el que tiene relacion.
    */
   this->ptrDispositivo = dt;
}

void Relacion::setPing(int p){
    /**
     * @brief Asigna el ping de la relacion. 
    */
    this->ping = p;
}

void Relacion::setJum(int j){
    /**
     * @brief asigna la suma de los saltos
    */
   this->jums = j;
}

void Relacion::setConex(std::string tipo){
    /**
     * @brief asigna el tipo de conexion
     * tranforma el todas las letras en minusculas
    */
    if( tipo.length() > 1){
        for (int x=0; x < tipo.length(); x++){
            putchar(tolower(tipo[x]));   
        }

        if (tipo == "5g" || tipo == "firbra optica" || tipo == "ambos"){
            this->conexion = tipo;
        }else{
            std::cout << "Los tipos de conexion validos son: 5G | Fibra Optica | Ambos \n";
        }
    }else{
        std::cout << "Debe indicar el tipo de conexion.";
    }
}

std::ostream& operator<<(std::ostream& os, const Relacion &dt){
    os << "Dispositivo: "<< *(dt.getDispositivo()) <<" Ping: " << dt.getPing() << " Saltos: " << dt.getJum() << " Tipo de conexion: "<<dt.getConexion();
    return os;
}

#endif