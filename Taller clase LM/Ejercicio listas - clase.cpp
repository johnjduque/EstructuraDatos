#include<iostream>
using namespace std;

struct fecha{
	int dia;
	string mes;
	int year; 
};

struct nodo{
	fecha info;
	nodo *sig; 
};

nodo *crearNodo(){
	fecha fechaHoy;
	nodo *aux;
	
	cout<<"Ingrese el dia"<<endl;
	cin>>fechaHoy.dia;
	cout<<"Ingrese el mes"<<endl;
	cin>>fechaHoy.mes;
	cout<<"Ingrese el año"<<endl;
	cin>>fechaHoy.year;
	cout<<"Ingrese el año"<<endl;
	cin>>registro.year;
	aux = new (nodo);
	aux->info = fechaHoy;
	aux->sig = NULL;
	
	return aux;	
}

void mostrarInfo(nodo *Nodo){
	cout<<Nodo->info.dia<<"/"<<Nodo->info.mes<<"/"<<Nodo->info.year;
}

int main(){
	
	nodo *nodoEjemplo;
	nodoEjemplo= crearNodo();
	
	mostrarInfo(nodoEjemplo);
	
	return 0;
}
