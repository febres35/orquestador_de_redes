#ifndef RANDOM_H
#define RANDOM_H
#include <iostream>

int Random(int i, int j) {
    /**
     * @brief genera un numero aleatorio entre @param i y @param j
     * @author Leonardo Febres
     * @date 06/05/2023
    */
    return i+rand() % j;
}


#endif