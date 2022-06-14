#include <iostream> 
using namespace std; 
/*Nodo Incio de la Lista*/

struct TDANodoCircular {
	int info;
	TDANodoCircular *sig;
};


//crear TDANodoCircular(leer la informacion y crear el espacio en memoria)//
TDANodoCircular *crearNodo(){
    TDANodoCircular *numero;
    numero = new (TDANodoCircular);
    cout<<"Ingrese Valor";
    cin>>numero->info;
    numero->sig=NULL;
       
    return numero;
}


TDANodoCircular *crearNodoDato(int info){
    TDANodoCircular *numero;
    numero = new (TDANodoCircular);
  	numero->info = info;
    numero->sig=NULL;
       
    return numero;
}

//Borrar Nodo
void borrarNodo(TDANodoCircular *nodoBorrar)
{
	delete(nodoBorrar);
}


void modificarNodo(TDANodoCircular *Nuevo)
{   
    cout << endl;
    cout << "Ingrese el dato o informacion nueva: ";
    cin >> Nuevo->info;
}

// metodo para saber si existe un nodo 
bool existeNodo (TDANodoCircular *nodoAverificar){
    
    if (nodoAverificar != NULL ){
        return true;
        
    }else {
        return false;
    }    
}

//funcion modificar apuntador de nodo 
void modificarApuntadoNodo (TDANodoCircular *nodoACambiar, TDANodoCircular *apuntadorNuevo  ){
     
     //comprobamos si existe el nodo
    if (existeNodo(nodoACambiar) == true ){
        
        nodoACambiar->sig =  apuntadorNuevo ;
        
    }else {
        cout << " !!!El nodo no existe���";
    }
     
    
}

void imprimirNodo(TDANodoCircular *imp)
{   
    cout << endl;
    cout << "El dato es: "<<imp->info;
}
struct TDAListaCircular{
	TDANodoCircular *inicio;
	TDANodoCircular *fin;
} ;

void consultarEstado(TDAListaCircular *listaCircularEstado)
{
	TDANodoCircular *recorrer, *recorrer1;
 	recorrer=listaCircularEstado->inicio;
	recorrer1=listaCircularEstado->fin;
	if (recorrer == NULL && recorrer1 == NULL)
	{
		cout<<"La lista circular se encuentra vacia."<<endl;
	} 
	else{
		if (recorrer == NULL || recorrer1 == NULL) {
			cout<<"No es una lista circular."<<endl;
		}
		else{
			cout<<"La lista circular tiene elementos."<<endl;
		}
	}
}
TDANodoCircular *buscarElemento(TDAListaCircular *l, int info) {
	TDANodoCircular *aux=l->inicio;
	while(aux->info!=info && aux->info!=l->fin->info){
	aux=aux->sig;
	}
	
	if(aux->info==info){
	return aux;
	}
	else{
	return NULL;
	}
	}
void recorrerLista(TDANodoCircular *nodoFinal, TDAListaCircular *listaCircular)
{
	TDANodoCircular *recorrer;
	recorrer = listaCircular->inicio;
	while(recorrer != nodoFinal)
	{
		cout << "El elemento es: " << recorrer->info << endl;
		recorrer = recorrer->sig;
	}
}

void borrarElemento(TDAListaCircular *listC, int elemBorrar )
{
	TDANodoCircular *nodoBorrar, *anterior;
	nodoBorrar = buscarElemento(listC, elemBorrar);
	if (nodoBorrar == NULL){
		cout <<"No existe elemento a Borrar\n";
	}
	else
	{
		if (nodoBorrar->sig == nodoBorrar)
		{
			listC->inicio = listC->fin = NULL;
		}
		else
		{
			anterior = nodoBorrar->sig;
			while (anterior->sig != nodoBorrar) 
			{   
				anterior = anterior->sig;
			}
			anterior ->sig = nodoBorrar-> sig;
			if(nodoBorrar->info==listC->inicio->info){
				listC->inicio=listC->inicio->sig;
			}
			if(nodoBorrar->info==listC->fin->info){
				listC->fin=anterior;
			}
			}
		}
		delete nodoBorrar;
	}

}
		

void ImprimirLista(TDAListaCircular *c){
	if (c->inicio==NULL){
		cout<<"\n"<<"La lista no esta creada";
	}
	else {
	    TDANodoCircular *aux;
		aux=c->inicio;
		do{
			cout<<"\n"<<aux->info;
			aux=aux->sig;
		}while (aux!=c->inicio);
	}
    cout<<"\n";
}
TDAListaCircular *insertarNodo(TDAListaCircular *lista, TDANodoCircular *nodo){
    TDAListaCircular *aux;
    if(lista == NULL){
        lista = new TDAListaCircular;
        lista->inicio = lista->fin = nodo->sig = nodo;
    }else{
        lista->fin->sig = nodo;
        nodo->sig = lista->inicio;
        lista->fin = nodo;
    }
    return lista;    
}

