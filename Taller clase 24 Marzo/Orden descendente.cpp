#include<iostream>
using namespace std;

struct Informacion{
	int dia;
	int mes;
	int year;
};

struct TDAnodo{
	Informacion info;
	TDAnodo *sig;
};

TDAnodo *crearNodo()
{
	Informacion fechaHoy;
	TDAnodo *aux;
	cout<<endl<<"Ingrese el dia ";
	cin>>fechaHoy.dia;
	cout<<"Ingrese el mes ";
	cin>>fechaHoy.mes;
	cout<<"Ingrese el año ";
	cin>>fechaHoy.year;
	aux = new (TDAnodo);
	aux->info = fechaHoy;
	aux->sig = NULL;
	return aux;
}

void mostrarInfo(TDAnodo *Nodo){
	cout<<Nodo->info.dia<<"/"<<Nodo->info.mes<<"/"<<Nodo->info.year<<endl;
}

int esListaVacia(TDAnodo *lista)
{
   return (lista == NULL);
}

TDAnodo *insertarNodoInicio(TDAnodo *lista){
	
	TDAnodo *nuevo, *aux1, *aux2;
	aux1 = lista;
	
	if(esListaVacia(aux1)){
		lista = crearNodo();
	}
	else{
		nuevo = crearNodo();
		int convertirFechaLista = (aux1->info.dia) + ((aux1->info.mes)*2) + (aux1->info.year);
		int convertirFechaNuevo = (nuevo->info.dia)+ ((nuevo->info.mes)*2) + (nuevo->info.year);
		while((aux1 != NULL) && (convertirFechaNuevo > convertirFechaLista)){
			aux2 = aux1;
			aux1 = aux1->sig;
		}

		aux2->sig = nuevo;
		nuevo->sig = aux1;
	}
	
	return lista;	
}

void mostrarLista(TDAnodo *inicio){
	if(esListaVacia(inicio)){
		cout<<endl<<"La lista esta vacia"<<endl;
	}
	else{
		TDAnodo *aux=inicio;
		while(aux!=NULL){
			mostrarInfo(aux);
			aux=aux->sig;
		}
	}
}

int main(){
	TDAnodo *Lista = NULL;
	mostrarLista(Lista);
	Lista = insertarNodoInicio(Lista);
	Lista = insertarNodoInicio(Lista);
	Lista = insertarNodoInicio(Lista);
	Lista = insertarNodoInicio(Lista);
	Lista = insertarNodoInicio(Lista);
	mostrarLista(Lista);
	return 0;
}
