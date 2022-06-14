//cola//

#include<iostream>
using namespace std;

struct Fecha{
	int dia;
    string mes;
    int year;
};

struct Persona{
	string nombre;
	int estatura; 
	int peso;
	Fecha fechaNacimiento;
 };
 

struct TDANodo{
	Persona info;
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
	cout<<"Ingrese la estatura "<<" \n";
	cin>> aux->info.estatura;
	cout<<"Ingrese el peso "<<"\n";
	cin>> aux->info.peso;
	cout<<"Ingrese el dia"<<"\n";
	cin>> aux->info.fechaNacimiento.dia;
	cout<<"Ingrese el mes  "<<" \n";
	cin>> aux->info.fechaNacimiento.mes;
	cout<<"Ingrese el año"<<"\n";
	cin>> aux->info.fechaNacimiento.year;
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
	cout<<"Estatura "<<cola->inicio->info.estatura<<" \n";
	cout<<"Peso "<<cola->inicio->info.peso<<"\n";
	cout<<"Dia  "<<cola->inicio->info.fechaNacimiento.dia<<"\n";
	cout<<"Mes  "<<cola->inicio->info.fechaNacimiento.mes<<" \n";
	cout<<"Año  "<<cola->inicio->info.fechaNacimiento.year<<"\n";
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

