//cola//

#include<iostream>
using namespace std;


struct Cliente{
	string nombre;
	int transaccion;
	int cantidad;
 };
 

struct TDANodo{
	Cliente info;
	TDANodo *sig;
};


struct TDACola{
	TDANodo *inicio;
	TDANodo  *fin;
};


TDANodo *crearNodo(){
	
	TDANodo *aux;
	aux = new (TDANodo);
	cout<<endl<<"Ingrese la nombre "<<" \n";
	cin>> aux->info.nombre;
	cout<<"Ingrese la transacción: 1. deposito, 2. retiro, 3. transferencia, 4. otros "<<" \n";
	cin>> aux->info.transaccion;
	cout<<"Ingrese la cantidad "<<" \n";
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

	cout<<endl<<"Nombre: "<<cola->inicio->info.nombre<<endl;
	cout<<"Transaccion: "<<cola->inicio->info.transaccion<<endl;
	cout<<"Cantidad: "<<cola->inicio->info.cantidad<<endl;
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

