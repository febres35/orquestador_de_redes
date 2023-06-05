#include <iostream>
using std::cout;
#include <string.h>

int main(void){

    char *x = new char[5];
    char *y = new char [6];
    x[0] ='c';
    x[1] ='o';
    x[2] ='m';
    x[3] ='e';
    x[4] ='r';
    
    y[0] ='c';
    y[1] ='o';
    y[2] ='m';
    y[3] ='e';
    y[4] ='r';
    y[5] ='\0';

    if (strcmp(x, y) == 0){
        cout << "Son iguales";
    }else
        cout << "no es igual";

    return 0;
}