#include<iostream>
using namespace std;

struct Persona{
	string nombre;
	string estatura;
	string peso;
	char genero;
	string fechaNacimiento;
};

struct TDACola{
	Persona info;
	TDACola *sig;
};

TDACola *crearNodo()
{
	Persona persona;
	TDACola *aux;
	cout<<"Ingrese el nombre";
	cin>>persona.nombre;
	cout<<"Ingrese la estatura";
	cin>>persona.estatura;
	cout<<"Ingrese el peso";
	cin>>persona.peso;
	cout<<"Ingrese el genero: M ó F";
	cin>>persona.genero;
	cout<<"Ingrese la fecha de nacimiento d/m/año ejemplo: 25/12/90";
	cin>>persona.fechaNacimiento;
	aux = new (TDACola);
	aux->info = persona;
	aux->sig = NULL;
	return aux;
}

int esColaVacia(TDACola *cola)
{
   return (cola == NULL);
}

TDACola *insertarNodo(TDACola *nodos){
	
	TDACola *nuevo;
	
	if (esColaVacia(nodos)){
		nodos = crearNodo();
	}
	else
	{
		TDACola *cab, *cola, *aux;
		cab = nodos;
		aux = nodos;
		while(aux->sig != NULL){
			aux = aux->sig;
		}
		cola = aux;
		nuevo=crearNodo();
		cola->sig = nuevo;
		cola = nuevo;
	}
	return nodos;	
}
