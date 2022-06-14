#include<iostream>
using namespace std;

struct Informacion{
	int dia;
	string mes;
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
	cout<<"Ingrese el dia";
	cin>>fechaHoy.dia;
	cout<<"Ingrese el mes";
	cin>>fechaHoy.mes;
	cout<<"Ingrese el a�o";
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

TDAnodo *buscarElemento(TDAnodo *inicio, Informacion elemento){
	TDAnodo *buscar = NULL;
	int encontrado = 0;
	
	if(esListaVacia(inicio)){
		return buscar;
	}
	else{
		buscar=inicio;
		while(buscar!=NULL && !encontrado){
			if (buscar->info.dia==elemento.dia && buscar->info.mes==elemento.mes && buscar->info.year==elemento.year) {
				encontrado =1;
			}
			else {
				buscar = buscar->sig;
			}
		}
	}
	return buscar;
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
	Informacion fechaDespues;
	
	if (esListaVacia(lista)){
		lista = crearNodo();
	}
	else
	{
		cout<<"Despu�s de Que Fecha\n";
		cout<<"Ingrese el dia:   ";
		cin>>fechaDespues.dia;
		cout<<"Ingrese el mes:   ";
		cin>>fechaDespues.mes;
		cout<<"Ingrese el a�o:   ";
		cin>>fechaDespues.year;
		aux = buscarElemento(lista,fechaDespues);
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

TDAnodo *insertarNodoParaOtraLista(TDAnodo *lista){
	
	TDAnodo *nuevo;
	TDAnodo *lista2;
	
	if (esListaVacia(lista)){
		lista2 = lista;
	}
	else
	{
		nuevo=new(TDAnodo);
		nuevo->sig=lista2;
		lista2=nuevo;
	}
	return lista2;	
}

TDAnodo *eliminarElementoInicioOFinal(TDAnodo *lista){
	
	if (lista != NULL){
		TDAnodo *auxBorrar = buscarElemento(lista, lista->info);
		TDAnodo *anterior = NULL;
		
		while(auxBorrar != NULL && auxBorrar->info != lista->info){
			anterior = auxBorrar;
			auxBorrar = auxBorrar->sig;
		}
		if (auxBorrar == NULL){
			cout<<endl<<"Elemento no existe en la lista";
		}
		else if (anterior == NULL){
			lista = lista->sig;
			delete auxBorrar;
		}
		else{
			anterior->sig = auxBorrar->sig;
			delete auxBorrar;
		}
	}
	else{
		cout<<endl<<"No es un elemento tipo nodo";
	}	
}

TDAnodo *duqueFechasMes(TDAnodo *john, string jairo){
	
	TDAnodo *aux = john;
	TDAnodo *nuevo;
	
	if(esListaVacia(john)){
		cout<<"No hay datos que mostrar en la lista";
	}
	else{
		while(aux->sig != NULL){
			if(strcmp(aux->info.mes == jairo){
				insertarNodoParaOtraLista(aux);
				nuevo = aux;
				aux = aux->sig;
			}
			else{
				cout<<"No hay mes de "<<jairo<<" para mostrar";
			}
			return john;
		}
	}
}

void mostrarLista(TDAnodo *inicio){
	if(esListaVacia(inicio)){
		cout<<"La lista est� vacia";
	}
	else{
		TDAnodo *aux=inicio;
		while(aux!=NULL){
			mostrarInfo(aux);
			aux=aux->sig;
		}
	}
}

