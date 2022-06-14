#include "TDAListaCircular.cpp"
#include <time.h>
#include <stdlib.h>

//Crear lista de 20 numeros aleatorios//
int main(){
	
	TDAListaCircular *listaCircular;
	listaCircular = NULL;
	TDANodoCircular *nodo;
	nodo = NULL;
	
	for(int i=0; i<10; i++){
		nodo = crearNodoDato(rand() % 100 + 1);
		listaCircular = insertarNodo(listaCircular, nodo);
	}
	cout<<"Lista inicial";
	ImprimirLista(listaCircular);
	
	for(int i=0; i<5; i++){
		TDANodoCircular *aux;
		aux = listaCircular->inicio;
		for(int j=0; j<3; j++){
			aux = aux->sig;
		}
		borrarElemento(listaCircular, aux->info);
	}
	cout<<"Lista despues de borrado";
	ImprimirLista(listaCircular);	

	return 0;
}
