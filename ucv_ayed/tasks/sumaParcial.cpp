#include <iostream>
#include <string>
using namespace std;

void Dateinput(int *&, const int);
const unsigned int inicio(int *&);

struct nodo{
		int candidato;
		nodo *next;
};

void incluirList(nodo *, nodo *);
void addset(int, nodo *&);
void finSum(int *&, int , int , int , nodo *&r);
bool existe(int , nodo *&);

int main(){
		int *arr;
		const unsigned int len = inicio(arr);
		Dateinput(arr, len);
		nodo *lista = NULL;
		finSum(arr, len, 0, 4, lista);
		
		return 0;
	}
  
const unsigned int inicio(int *&arr){
		cout << "Ingrese tamaño de la lista de numero: ";
		unsigned int length;
  cin >> length;
  cout <<endl;
		 arr = new int(length);
		const unsigned int len = length;
		 return len;
		
}

void Dateinput(int *&arr, const int len){
  arr = new int[len];
  for (int i = 0; i < len; i++){
  		cin >> arr[i];
  }
}

void addset(int x, nodo *&first){
		if(first == NULL){
		  nodo *aux;
		  aux = new nodo;
		  aux->candidato = x;
		  aux->next = NULL;
		  first= aux;
		}else{
		  addset(x, first->next);
		}
		
}

void setPrint(nodo *root){
		if (root ==NULL){
				cout << "END "<< endl;
				
		}else{
				cout << root->candidato << ", ";
				setPrint(root->next);
		}
}
  
void removeSet(nodo *&root){
				if(root -> next == NULL){
				  nodo *aux = root;
				  root=NULL;
				  delete aux;
				}else{
				  removeSet(root->next);
				}
}
  
void finSum(int *&arr, int len, int parcial, int total, nodo *&root){
		if (total == parcial){
				setPrint(root);
		}else{
				for (int i = 0; i < len; i++){
						if (parcial + arr[i] <= total ) {
								 if (!existe(arr[i], root)) {
									addset(arr[i], root);
									finSum(arr, len, parcial+arr[i], total, root);
									removeSet(root);
									
						}
				}
				
		}
}
}

bool existe(int x, nodo *&lista){
  nodo *actual = new nodo();
  actual = lista;
  if (actual == NULL ){
    return false;
  }else{
    if ( actual->candidato == x){
		cout <<actual->candidato << ", " << x<< endl;
      return true;
     }else{
         existe(x, actual->next);
     }
  }
}
