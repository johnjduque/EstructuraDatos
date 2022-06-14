
#include<iostream>
using namespace std;

struct TDAPila{
	char info;
	TDAPila *sig;
};


bool esPilaVacia (TDAPila *pila)
{
	if (pila == NULL)
		return true;
	else
	    return false;
}
void mostrarPila(TDAPila *pila){
	if(esPilaVacia(pila)){
		cout<<"La Pila está vacia";
	}
	else{
		cout<<pila->info<<endl;
	}
}

char devolverInfo(TDAPila *pila) {
	return (pila->info);
}

TDAPila *crearNodo(){
	TDAPila *aux;
	aux = new (TDAPila);
	cout<<"Ingrese el caracter "<<"\n";
	cin>> aux->info;
	aux->sig=NULL;
	return aux;
}

TDAPila *insertarPila(TDAPila *lista){
	TDAPila *tope;
	
	tope=crearNodo();
	tope->sig=lista;
	lista=tope;
	return lista;	
}

TDAPila *insertarPilaInformacion(TDAPila *lista, char informacion){
	TDAPila *tope;
	
	tope=new(TDAPila);
	tope->info = informacion;
	tope->sig=lista;
	lista=tope;
	return lista;	
}

TDAPila *eliminarTope(TDAPila *pila){
  if(pila!=NULL){
    TDAPila *aux=pila;
    pila=pila->sig;
    delete(aux);
    return pila; 
  }
  return pila;
}

TDAPila *destruirPila(TDAPila *pila){

	while (not(esPilaVacia(pila))){
		cout<<"Eliminado ";
		mostrarPila(pila);
		pila=eliminarTope(pila);
	}	
	return pila;
}


