//cola//

#include<iostream>
using namespace std;

struct clientes{
	string nombre;
	int transaccion;
	int cantidad;
 };
 

struct TDANodo{
	clientes info;
	TDANodo *sig;
};


struct TDACola{
	TDANodo *inicio;
	TDANodo  *fin;
};


TDANodo *crearNodo(){
	TDANodo *aux;
	aux = new (TDANodo);
	cout<<"Ingrese el nombre "<<"\n";
	cin>> aux->info.nombre;
	cout<<"Ingrese la transacción.  1, Deposito, 2. Retiro  3.  Transferencia  4. Otros "<<" \n";
	cin>> aux->info.transaccion;
	cout<<"Ingrese la cantidad "<<"\n";
	cin>> aux->info.cantidad;
	aux->sig =NULL;
	return aux;
}

bool esColaVacia(TDACola *cola){
	if (cola==NULL) 
		return true;		
	else
		return false;
}

TDACola *insertarCola(TDACola *cola){
	if (esColaVacia(cola )){
		cola = new(TDACola);
		cola->inicio = cola->fin = crearNodo();
	}
	else{
		TDANodo *Nuevo = crearNodo();
		cola->fin-> sig = Nuevo;
		cola->fin = Nuevo;
	}
	return cola;
}

void mostrarNodo(TDACola *cola){

	cout<<"Nombre "<<cola->inicio->info.nombre<<"\n";
	cout<<"Transacción "<<cola->inicio->info.transaccion<<" \n";
	cout<<"Cantidad "<<cola->inicio->info.cantidad<<"\n";

}
void mostrarCola(TDACola *cola){
	if(esColaVacia(cola)){
		cout<<"La Cola está vacia";
	}
	else{
		mostrarNodo(cola);
	}
}

TDACola *eliminarCola(TDACola *cola){
  if(!esColaVacia(cola)){
    TDANodo *aux=cola->inicio;
    if (cola->inicio == cola->fin) {
    	cola=NULL;
	}
    else {
    	cola->inicio=cola->inicio->sig;
	}
    delete(aux);
  }
  return cola;
}

TDACola *destruirCola(TDACola *cola){

	while (not(esColaVacia(cola))){
		cout<<"Eliminado ";
		mostrarCola(cola);
		cola=eliminarCola(cola);
	}	
	return cola;
}
