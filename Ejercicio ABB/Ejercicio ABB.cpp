#include<iostream>
using namespace std;

struct TDAArbol{
	int info;
	TDAArbol *izq, *der;
};

TDAArbol *crearNodo(){
	int numero;
	TDAArbol *aux;
	cout<<"Ingrese el numero: ";
	cin>>numero;
	
	aux = new (TDAArbol);
	aux->info = numero;
	aux->der = NULL;
	aux->izq = NULL;
	return aux;
}

void ingresarNodo(TDAArbol *raiz, TDAArbol *nodo){

	if(raiz == NULL){
		raiz = nodo;
	}
	else{
		if(nodo->info < raiz->info){
			ingresarNodo(raiz->izq, nodo);
		}
		else{
			ingresarNodo(raiz->der, nodo);
		}
	}
}
