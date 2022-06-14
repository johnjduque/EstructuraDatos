#include<iostream>
using namespace std;

struct tdaArbol{
    int info;
    tdaArbol *izq, *der;
};

tdaArbol *crearArbol(int n){
    tdaArbol *nuevo=new(tdaArbol);
    nuevo->info=n;
    nuevo->izq=nuevo->der=NULL;
    return nuevo;
}

tdaArbol *crearArbol(){
    tdaArbol *nuevo;
    int n;
    cout<<"¿Que numero quieres que haya en tu nodo?: ";
    cin>>n;
    nuevo=crearArbol(n);
    return nuevo;
}

tdaArbol *insertarNodo(tdaArbol *raiz, int n){
    //cout<<" - "<<n<<" - ";
    tdaArbol *aux=raiz, *ant;
    if(raiz==NULL){
        raiz=crearArbol(n);
    }
    else{

	    while(aux !=NULL){
	    	ant = aux;
	    	if(n > aux->info)
	    		aux=aux->der;
	    	else
	    		aux = aux->izq;
	    }
	    
	    if(ant->info<n ){
	        ant->der =crearArbol(n);
	    }
	    else {
	        ant->izq=crearArbol(n);
	    }
	}
	    return raiz;
}

bool esvacia(tdaArbol *raiz){
	if(raiz == NULL){
		cout<<"la raiz esta vacia "<<endl;
		return true;
	}
	return false;
}

tdaArbol *buscar(tdaArbol *raiz, int n){
	tdaArbol *aux=raiz;
	if(esvacia(raiz)==true){
		return NULL;
	}
	else{
		
		while(aux != NULL && aux->info != n ){
			if(n > aux->info)
				aux=aux->der;
			else
				aux = aux->izq;
		}
		return aux;

	}
	
}

void inorden(tdaArbol *r)
{
	if (r!=NULL){
		inorden(r->izq);
		cout<<endl<<"info: \t"<<r->info;
		inorden(r->der);
	}
}

void preorden(tdaArbol *r)
{
	if (r!=NULL){
		cout<<endl<<"info: \t"<<r->info;
		preorden(r->izq);
		preorden(r->der);
	}
}

void postorden(tdaArbol *r)
{
	if (r!=NULL){
		postorden(r->izq);
		postorden(r->der);
		cout<<endl<<"info: \t"<<r->info;
	}
}

void eliminar(tdaArbol *arbol, int subarbol){
	if(arbol == NULL){
		cout<<"No hay nada que eliminar";
	}
	else if(subarbol < arbol->info){
		eliminar(arbol->izq, subarbol);
	}
	else if(subarbol > arbol.info){
		eliminar(arbol, subarbol);
	}
	else if(subarbol == arbol.info){
		eliminarSubarbol(arbol);
	}
}

void eliminarSubarbol(tdaArbol *arbol){
	
}
