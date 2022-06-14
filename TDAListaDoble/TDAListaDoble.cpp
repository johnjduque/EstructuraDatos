#include <iostream> 
using namespace std; 
/*Nodo Incio de la Lista*/

struct nodoLDE{
	int info;
	nodoLDE *sig, *ant;
} ;

nodoLDE *crearNodo(int dato) 
{
	nodoLDE *nodoC;
	nodoC = new nodoLDE;
	nodoC->info = dato;
	nodoC->sig =NULL;
	nodoC->ant = NULL;
	return nodoC;
}

nodoLDE *crearNodo() 
{
	int info;
	cout<<"Ingrese el valor";
	cin>>info;
	return crearNodo(info);
}

void borrarNodo(nodoLDE *nodoBorrar)
{
	delete(nodoBorrar);
}

void imprimirInfo(nodoLDE *nodo) {

 cout<<"Información del nodo: "<<nodo->info<<endl;

 }


struct TDAListaDoble{
	nodoLDE *inicio;
	nodoLDE *fin;
} ;

TDAListaDoble *Inicilizar(){
	TDAListaDoble *c;
	c = new TDAListaDoble;
	c->fin=NULL;
	c->inicio = NULL;
	return c;
}

TDAListaDoble *crearLista(TDAListaDoble *c, int numero){
    nodoLDE *aux;
	aux =  crearNodo(numero) ;
	if (c->inicio==NULL){
		c->inicio = c->fin = aux;
	}
	else {
		aux->ant=c->fin;
		c->fin->sig = aux;
		c->fin=aux;
    }
	return c;
}


void ImprimirLista(TDAListaDoble *c){
    nodoLDE *aux;
	aux=c->inicio;
	while (aux!=NULL){
		cout<<"\n"<<aux->info;
		aux=aux->sig;
	}
    cout<<"\n";
}


void ImprimirListaAnt(TDAListaDoble *c){
    nodoLDE *aux;
	aux=c->fin;
	while (aux!=NULL){
		cout<<"\n"<<aux->info;
		aux=aux->ant;
	}
   cout<<"\n";
}


TDAListaDoble *BorrarElemento(TDAListaDoble *c, nodoLDE *nodBorrar){
	nodoLDE *ant;
	
	if (c->inicio==nodBorrar && c->fin==nodBorrar ){
		c=Inicilizar();
	}
	else {
		if(c->inicio!=nodBorrar && c->fin!=nodBorrar) {
			nodBorrar->ant->sig = nodBorrar->sig;
			nodBorrar->sig->ant = nodBorrar->ant;
		} else if(c->inicio ==nodBorrar) {
			c->inicio->ant=NULL;
			c->inicio = c->inicio->sig;
			nodBorrar->sig->ant = NULL;
		} else if(c->fin ==nodBorrar) {
			c->fin->ant->sig=NULL;
			c->fin=c->fin->ant;
			nodBorrar->ant->sig = NULL;
		}
	}
	delete(nodBorrar);
	return c;
}

void InsertarPorCabeza(TDAListaDoble *c, nodoLDE *nodo) {
	nodo->sig = c->inicio;
	c->inicio->ant = nodo;
	c->inicio = nodo;

}

void InsertarPorFinal(TDAListaDoble *c, nodoLDE *nodo) {

	nodo->ant = c->fin;
	c->fin->sig = nodo;
	c->fin = nodo;

}

nodoLDE *buscarNodo(int elemento, TDAListaDoble *c){
	int encontrado;
	nodoLDE *aux;
	if (c->inicio==NULL){
		encontrado= 0;
	}
	else{
		aux=c->inicio;
		while(aux!=NULL && !encontrado){
			if(aux->info==elemento){
				encontrado=1;
			}
			else {			
				aux = aux ->sig;
			}
		}
	}	
	return aux;
}

void InsertarEntre(TDAListaDoble *c, nodoLDE *nuevo, int elemento) {
	nodoLDE *p = buscarNodo(elemento, c);
	if (p !=NULL) {
		if (p==c->inicio)
		{
			InsertarPorCabeza(c,nuevo);
		}
		else {
			if (p==c->fin)
			{
				InsertarPorFinal(c,nuevo);
			}
			else {
				nuevo->sig = p->sig;
				p->sig = nuevo;
				nuevo->ant = p;
				nuevo->sig->ant = nuevo;
			}
		}
	}
	else {
		
		cout<<"\nNo se ingresa nodo, elemento no encontrado!!!!\n";
	}
		
}

void imprimirInicio(TDAListaDoble *c) {
	cout<<"El inicio de la lista: ";
	imprimirInfo(c->inicio);
}

void imprimirFin(TDAListaDoble *c) {
	cout<<"El final de la lista: ";
	imprimirInfo(c->inicio);
}

bool esVacia(TDAListaDoble *c) {
	return c == NULL;
}

TDAListaDoble *destruirLista(TDAListaDoble *list)
{
    nodoLDE *borrarANodo;
    borrarANodo = list->inicio;
    
	while(borrarANodo!= NULL)
    {
		BorrarElemento(list,borrarANodo);
        borrarANodo = list->inicio;
    }
    delete(list);
    list = NULL;
    return list;
}

