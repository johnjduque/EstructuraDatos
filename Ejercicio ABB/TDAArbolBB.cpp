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

TDAArbol *crearArbol(int n){
	int numero = n;
	TDAArbol *aux;
	
	aux = new (TDAArbol);
	aux->info = numero;
	aux->der = NULL;
	aux->izq = NULL;
	return aux;
}

TDAArbol *insertarNodo(TDAArbol *raiz, int n){
	
	cout<<" - "<<n<<" - ";
	TDAArbol *aux=raiz, *ant;
	if(raiz==NULL){
		raiz=crearArbol(n);
	}
	else{	
		while(aux !=NULL){
			ant = aux;
			if(n > aux->info)
			aux=aux->der;
			else
			aux = aux->izq;
		}
		
		if(ant->info<n ){
			ant->der =crearArbol(n);
		}
		else {
			ant->izq=crearArbol(n);
		}
	}
	return raiz;
}

bool estaArbolVacio(TDAArbol *raiz){
	
	bool esVacio = false;
	if(raiz == NULL){
		esVacio = true;
	}
	return esVacio;
}

TDAArbol *buscarNodo(TDAArbol *raiz, int informacion){
	
	TDAArbol *aux=raiz;
	bool encontrado = false;
	
	if(estaArbolVacio(raiz)){
		cout<<endl<<"El árbol no tiene información, esta vacío";
	}
	else{
		while(aux !=NULL && !encontrado){
			if(informacion > aux->info)
				aux=aux->der;
			else
				aux = aux->izq;
			if(aux->info == informacion or aux == NULL)
				encontrado = true;
		}
	}
	return aux;
}

void preOrden(TDAArbol *aux){
	
	if(aux!=NULL){
		cout<<endl<<aux->info<<endl;
		preOrden(aux->izq);
		preOrden(aux->der);
	}
}
