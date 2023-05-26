#include <iostream>
using namespace std;
#include "p4E15_optimizarCortesDeCable.cpp"



struct arbol{
    
};

class hojas:List{
    private:
        Tree* tree;

};

class Tree{
    private:
        static int _id;
        Tree *Root;
        List *chield;

    public:
        Tree();
        ~Tree();
        Nodo *getRoot(); // return Nodo raiz del sub arbol.
        Nodo *getLChild; // return Nodo mas a la izquierda
        Nodo *getRChild; // return Nodo mas a la derecha
        





};


/**
 * void postOrden(Tree root){
 *      if (root == NULL){
 *           postOrden()
 *       }
 * }
*/

int main (){

    cout << "Welcome" << endl;


    return 0;
}