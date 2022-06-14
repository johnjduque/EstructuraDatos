#include "TDAListaCircular.cpp"
#include <time.h>
#include <stdlib.h>

//Crear lista de 20 numeros aleatorios//
int main(){
	TDAListaCircular *listaCircular;
	listaCircular = NULL;
	int numeroPersonas, desfase;
	cout<<"cuantas personas quiere en la lista?: "<<endl;
	cin>>numeroPersonas;
	cout<<"de cuento quiere el desfase?: "<<endl;
	cin>>desfase;
	for (int i=0;i<numeroPersonas;i++){
		listaCircular = insertarNodo(listaCircular, crearNodoDato(i+1));
	}
	
	
	cout<<"La lista generada es: "<<endl;
	cout<<"----------------------------------------------------"<<endl;
	ImprimirLista(listaCircular);
	
	TDANodoCircular *aux, *nodoRepuesto;
	nodoRepuesto = listaCircular->inicio;
	
	while(listaCircular->inicio!=listaCircular->fin){
		aux = nodoRepuesto;
		for(int i=1; i<desfase; i++){
			aux=aux->sig;
		}
		nodoRepuesto=aux->sig;
		borrarElemento(listaCircular, aux->info);
	}
	
	cout<<"La lista después de borrar es: "<<endl;
	cout<<"----------------------------------------------------"<<endl;
	ImprimirLista(listaCircular);
	
}
