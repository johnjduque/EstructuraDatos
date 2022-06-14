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

//Inicializa la variable para posteriormente calcular el # de elementos en la lista
int cuentaNodos = 0;

//Método para crear un nodo
nodo *crearNodo(){
	fecha fechaHoy;
	cuentaNodos++;
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

//Retorna la cantidad de elementos totales que tiene la lista
int cantidadNodos(){
	int contador = cuentaNodos;
	return contador;
}

//Evalúa si la lista esta vacía o ya aputa a un nodo 
int esListaVacia(nodo *lista)
{
	return (lista == NULL);
}

//Permite ingresar un elemento al inicio de la lista
nodo *insertarNodoInicio(nodo *lista){

	nodo *nuevo;
	
	if (esListaVacia(lista)){
		lista = crearNodo();
	}
	else
	{
		nuevo=crearNodo();
		nuevo->sig=lista;
		lista=nuevo;
	}
	return lista;
}

//Permite ingresar un elemento al final de la lista
nodo *insertarNodoFinal(nodo *lista){

	nodo *nuevo, *aux;

	if (esListaVacia(lista)){
		lista = crearNodo();
		return lista;
	}
	else{
		nuevo = crearNodo();
		aux = lista;
		while(aux->sig != NULL){
			aux = aux->sig;	
		}
		aux->sig = nuevo;
		return lista;	
	}	
}

//Permite ingresar elementos en cualquier posicion de la lista
nodo *insertarNodoPosicion(nodo *lista, int posicion){
	
	nodo *nuevo;
	int limite = cantidadNodos() + 1;
	
	if (esListaVacia(lista)){
		lista = crearNodo();
		return lista;
	}
	else{
		if (posicion == 1){
			return insertarNodoInicio(lista);
		}
		else if (posicion == limite){
			return insertarNodoFinal(lista);
		}
		else if (posicion > 1 && posicion < limite)
		{
			nodo *aux1, *aux2;
			nuevo = crearNodo();
			aux1 = lista;
			for(int i=1; i<posicion; i++){
				aux2 = aux1;
				aux1 = aux1->sig;
			}
			aux2->sig = nuevo;
			nuevo->sig = aux1;
			return lista;					
		}
		else{
			cout<<endl<<"Posicion incorrecta";
		}
	}
}

//Permite buscar si una información especifica se encuentra en algún nodo
nodo *buscarInformacionNodo(nodo *lista){
	int cont=1;
	fecha fechaHoy;
	nodo *aux, *aux2;
	cout<<endl<<"Ingrese el dia a buscar: ";
	cin>>fechaHoy.dia;
	cout<<"Ingrese el mes a buscar: ";
	cin>>fechaHoy.mes;
	cout<<"Ingrese el año a buscar: ";
	cin>>fechaHoy.year;
	aux = new (nodo);
	aux->info = fechaHoy;
	aux2 = lista;
	while (aux2 != NULL){
		if (aux2->info.dia == aux->info.dia && aux2->info.mes == aux->info.mes && aux2->info.year == aux->info.year){
			cout<<endl<<"La fecha fue encontrada en la lista, en la posicion: "<<cont;
		}
		cont++;
		aux2 = aux2->sig; 
	}
	cout<<endl<<"Informacion no encontrada, por favor verifique los datos";	
}

//Permite mostrar en consola la información de cada elemento
void mostrarInfo(nodo *Nodo){
	
	cout<<Nodo->info.dia<<"/"<<Nodo->info.mes<<"/"<<Nodo->info.year<<endl;
}

//Permite enviar la orden para que se pueda mostrar la información
void mostrarLista(nodo *Nodo){
	if(esListaVacia(Nodo)){
		cout<<"La lista no contiene elementos"<<endl;
	}
	else{
		nodo *aux = Nodo;
		while(aux != NULL){
			mostrarInfo(aux);
			aux = aux->sig;
		}				
	}
}

nodo *Lista = NULL;
int main(){
		
	mostrarLista(Lista);
	Lista = insertarNodoInicio(Lista);
	mostrarLista(Lista);
	Lista = insertarNodoInicio(Lista);
	mostrarLista(Lista);
	Lista = insertarNodoInicio(Lista);
	mostrarLista(Lista);
	Lista = insertarNodoFinal(Lista);
	mostrarLista(Lista);
	Lista = insertarNodoPosicion(Lista, 2);	
	mostrarLista(Lista);
	Lista = insertarNodoPosicion(Lista, 1);	
	mostrarLista(Lista);
	Lista = insertarNodoPosicion(Lista, 7);	
	mostrarLista(Lista);
	cout<<endl<<cantidadNodos();
	buscarInformacionNodo(Lista);
	
	return 0;
}
