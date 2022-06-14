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

int cuentaNodos = 0;

//Método para crear un nodo
nodo *crearNodo(){
	cuentaNodos++;	
	fecha fechaHoy;
	nodo *aux;
	cout<<endl<<"Ingrese el dia: ";
	cin>>fechaHoy.dia;
	cout<<"Ingrese el mes: ";
	cin>>fechaHoy.mes;
	cout<<"Ingrese el año: ";
	cin>>fechaHoy.year;
	aux = new (nodo);
	aux->info = fechaHoy;
	aux->sig = NULL;
	return aux;
}

//Evalúa si la lista esta vacía o ya aputa a un nodo 
int esListaVacia(nodo *lista){
	
	return (lista == NULL);
}

int cantidadNodos(){
	int contador = cuentaNodos;
	return contador;
}

//Permite ingresar un elemento al inicio de la lista
nodo *insertarNodoInicio(nodo *lista){

	nodo *nuevo;

	if (esListaVacia(lista)){
		lista = crearNodo();
	}
	else{
		nuevo=crearNodo();
		nuevo->sig=lista;
		lista=nuevo;
	}
	
	return lista;
}

//Permite ingresar un elemento al final de la lista
nodo *insertarNodoFinal(nodo *lista){

	nodo *auxiliar;

	if (esListaVacia(lista)){
		lista = crearNodo();
		return lista;
	}
	else{
		auxiliar = lista;
		while(auxiliar->sig != NULL){
			auxiliar = auxiliar->sig;	
		}
		return auxiliar->sig = crearNodo();		
	}	
}

//Permite ingresar un elemento en cualquier posición de la lista
nodo *insertarNodoPosicion(nodo *lista, int posicion){

	nodo *nuevo, *auxiliar, *auxiliar1;

	if (esListaVacia(lista)){
		nuevo = crearNodo();
	}
	else{
		if(posicion == 1){
			nuevo = insertarNodoInicio(lista);
		}
		else if(posicion == (cantidadNodos() + 1)){
			nuevo = insertarNodoFinal(lista);
		}
		else if(posicion > 1 && posicion < (cantidadNodos() + 1)){
			auxiliar = nuevo;
			for(int i=1; i<posicion; i++){
				auxiliar1 = auxiliar;
				auxiliar = auxiliar->sig;
			}
			auxiliar1->sig = nuevo;
			nuevo->sig = auxiliar;
		}
		else{
			cout<<"posicion incorrecta";
		}		
	}
	return nuevo;
}

//Permite mostrar en consola la información de cada elemento
void mostrarInfo(nodo *Nodo){
	
	cout<<Nodo->info.dia<<"/"<<Nodo->info.mes<<"/"<<Nodo->info.year<<endl;
}

//Permite enviar la orden para que se pueda mostrar la información
void mostrarLista(nodo *Nodo){
	if(esListaVacia(Nodo)){
		cout<<"La lista no contiene información";
	}
	else{
		nodo *aux = Nodo;
		while(aux != NULL){
			mostrarInfo(aux);
			aux = aux->sig;
		}				
	}
}

int main(){
	nodo *Lista = NULL;	
	nodo *Listaaux;		
	Lista = insertarNodoInicio(Lista);
	Listaaux = Lista;
	Lista = insertarNodoInicio(Lista);	
	Lista = insertarNodoFinal(Lista);
	mostrarLista(Listaaux);	
	cout<<cantidadNodos()<<endl;
	Lista = insertarNodoPosicion(Lista, 2);
	mostrarLista(Listaaux);	
	cout<<cantidadNodos()<<endl;
	
	return 0;
}
