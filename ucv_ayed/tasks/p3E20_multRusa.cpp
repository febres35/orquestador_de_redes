#include <iostream>
using namespace std;

void multRusa(int, int, int&);

int main(){
    int a, b, c=0;
    cout << "Indica los valores que desea multiplicar: ";
    cin >> a >> b;
    //cout << endl;
    multRusa(a, b, c);
    cout << a << " * " << b << " = " << c<< endl;

    //system("Pause");
    return 0;
}

void multRusa(int a, int b, int& c){
    if (a <= 1){
        c += b;
    }else {
        if(a % 2 != 0){
            c += b;
        }
        multRusa(a / 2, b*2, c);
    }
}
