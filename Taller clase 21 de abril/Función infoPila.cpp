#include<iostream>
using namespace std;

struct TDAPila{
	char info;
	TDAPila *sig;
};

void mostrarInfoPila(TDAPila *pila){
	if(esPilaVacia(pila)){
		cout<<"La Pila est� vacia";
	}
	else{
		mostrarInfo(pila);
		}
	}
}

void mostrarInfo(TDAPila *Nodo){
	cout<<Nodo->info;
}
