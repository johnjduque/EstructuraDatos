#include<iostream>
using namespace std;

struct Informacion{
	int numero;
};

struct TDAnodo{
	Informacion info;
	TDAnodo *sig;
};

TDAnodo *crearNodo()
{
	Informacion numeroEntero;
	TDAnodo *aux;
	cout<<"Ingrese el numero:   ";
	cin>>numeroEntero.numero;

	aux = new (TDAnodo);
	aux->info = numeroEntero;
	aux->sig = NULL;
	return aux;
}

void mostrarInfo(TDAnodo *Nodo){
	cout<<Nodo->info.numero<<endl;
}

int esListaVacia(TDAnodo *lista)
{
   return (lista == NULL);
}

TDAnodo *buscarElemento(TDAnodo *inicio, Informacion elemento){
	TDAnodo *buscar = NULL;
	int encontrado = 0;
	
	if(esListaVacia(inicio)){
		return buscar;
	}
	else{
		buscar=inicio;
		while(buscar!=NULL && !encontrado){
			if (buscar->info.numero==elemento.numero) {
				encontrado =1;
			}
			else {
				buscar = buscar->sig;
			}
		}
	}
	return buscar;
}


TDAnodo *insertarNodoConInfo(TDAnodo *lista, TDAnodo *nuevo){
	/*Insercion al inicio*/
	if(esListaVacia(lista)){
		lista=nuevo;
	}
	else{
		nuevo->sig=lista;
		lista=nuevo;
	}
	return lista;
}


TDAnodo *borrarInicio(TDAnodo *lista)
{
	TDAnodo *aux;
	aux = lista;
	lista = lista->sig;
	delete(aux);
	return lista;
}

TDAnodo *borrarMedio(TDAnodo *lista, TDAnodo *nodoBorrar)
{
	TDAnodo *aux;
	
	aux = lista;
	while (aux->sig!= nodoBorrar){
		aux = aux->sig;
	}
	aux->sig = nodoBorrar -> sig;
	
	delete(nodoBorrar);
	
	return lista;
}

TDAnodo *borrarNodo(TDAnodo *lista, TDAnodo *nodoBorrar){
	/*Borrado de un nodo*/
	
	if(lista == nodoBorrar){
		lista = borrarInicio(lista);
	}
	else{
		
		lista=borrarMedio(lista, nodoBorrar);
	}
	return lista;
}

TDAnodo *insertarNodoInicio(TDAnodo *lista){
	
	TDAnodo *nuevo;
	
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


TDAnodo *insertarNodoFinal(TDAnodo *lista){
	
	TDAnodo *nuevo, *aux;
	
	if (esListaVacia(lista)){
		lista = crearNodo();
	}
	else
	{
		aux = lista;
		while (aux->sig!=NULL){
			aux = aux ->sig;
		}
		nuevo=crearNodo();
		aux->sig=nuevo;
	}
	return lista;	
}

TDAnodo *insertarNodoDespuesOtro(TDAnodo *lista){
	
	TDAnodo *nuevo, *aux;
	Informacion numeroDespues;
	
	if (esListaVacia(lista)){
		lista = crearNodo();
	}
	else
	{
		cout<<"Después de Qué  nummero\n";
		cout<<"Ingrese el Número:   ";
		cin>>numeroDespues.numero;
		aux = buscarElemento(lista,numeroDespues);
		if (aux!=NULL){
			nuevo = crearNodo();
			nuevo->sig = aux->sig;
			aux ->sig = nuevo;
		}
		else {
			cout<<"No fue posible el ingreso !!!\n";
		}

	}
	return lista;	
}

TDAnodo *johnCrearNodoMultiplicacion(TDAnodo *duque)
{
	TDAnodo *aux;
	Informacion zuluagaMultiplicar;
	zuluagaMultiplicar.numero = 2;

	aux = new (TDAnodo);
	aux->info.numero = (duque->info.numero) * zuluagaMultiplicar.numero;
	aux->sig = NULL;
	return aux;
}

TDAnodo *johnJairoInsertarNodoParaOtraLista(TDAnodo *zuluaga)
{
	
	TDAnodo *nuevo, *aux;
	TDAnodo *lista2;
	aux=zuluaga;
	
	if (esListaVacia(zuluaga)){
		cout<<"No hay lista para multiplicar";
	}
	else
	{
		while (aux != NULL){
			nuevo=johnCrearNodoMultiplicacion(zuluaga);
			nuevo->sig=lista2;
			lista2=nuevo;
			aux->sig = aux->sig;
		}
	}
	return lista2;	
}

void mostrarLista(TDAnodo *inicio){
	if(esListaVacia(inicio)){
		cout<<"La lista está vacia";
	}
	else{
		TDAnodo *aux=inicio;
		while(aux!=NULL){
			mostrarInfo(aux);
			aux=aux->sig;
		}
	}
}

