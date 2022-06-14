#include <iostream> 
using namespace std; 
/*Nodo Incio de la Lista*/

struct TDANodoCircularJ {
	int info;
	TDANodoCircularJ *sig;
};


//crear TDANodoCircular(leer la informacion y crear el espacio en memoria)//
TDANodoCircularJ *crearNodoJ(){
    TDANodoCircularJ *numero;
    numero = new (TDANodoCircularJ);
    cout<<"Ingrese Valor";
    cin>>numero->info;
    numero->sig=NULL;
       
    return numero;
}


TDANodoCircularJ *crearNodoDatoJ(int info){
    TDANodoCircularJ *numero;
    numero = new (TDANodoCircularJ);
  	numero->info = info;
    numero->sig=NULL;
       
    return numero;
}

//Borrar Nodo
void borrarNodoJ(TDANodoCircularJ *nodoBorrar)
{
	delete(nodoBorrar);
}


void modificarNodoJ(TDANodoCircularJ *Nuevo)
{   
    cout << endl;
    cout << "Ingrese el dato o informacion nueva: ";
    cin >> Nuevo->info;
}

// metodo para saber si existe un nodo 
bool existeNodoJ(TDANodoCircularJ *nodoAverificar){
    
    if (nodoAverificar != NULL ){
        return true;
        
    }else {
        return false;
    }    
}

 

//funcion modificar apuntador de nodo 
void modificarApuntadoNodoJ(TDANodoCircularJ *nodoACambiar, TDANodoCircularJ *apuntadorNuevo  ){
     
     //comprobamos si existe el nodo
    if (existeNodoJ(nodoACambiar) == true ){
        
        nodoACambiar->sig =  apuntadorNuevo ;
        
    }else {
        cout << " !!!El nodo no existe¡¡¡";
    }
     
    
}

void imprimirNodoJ(TDANodoCircularJ *imp)
{   
    cout << endl;
    cout << "El dato es: "<<imp->info;
}
struct TDAListaCircularJ{
	TDANodoCircularJ *inicio;
	TDANodoCircularJ *fin;
} ;

void consultarEstadoJ(TDAListaCircularJ *listaCircularEstado)
{
	TDANodoCircularJ *recorrer, *recorrer1;
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

//Santiago Cardenas Franco

TDANodoCircularJ *buscarElementoJ(TDAListaCircularJ *l, int info) {

	TDANodoCircularJ *aux=l->inicio;
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

int recorrerListaJ(TDAListaCircularJ *listaCircular)
{
	if(listaCircular == NULL){
		return 0;
	}
	else{
		TDANodoCircularJ *recorrer;
		recorrer->sig = listaCircular->inicio->sig;
		int i = 2;
		while(recorrer->sig != listaCircular->inicio)
		{
			recorrer->sig = recorrer->sig->sig;
			i = i+1;
		}
		return i;
	}
}

void borrarElementoJ(TDAListaCircularJ *listC, int elemBorrar)
{
	TDANodoCircularJ *nodoBorrar, *anterior;
	nodoBorrar = buscarElementoJ(listC, elemBorrar);
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
			if(nodoBorrar==listC->inicio){
				listC->inicio=nodoBorrar->sig;
			}
			if(nodoBorrar==listC->fin){
				listC->fin=anterior;
			}
		}
		delete nodoBorrar;
	}

}
		

void ImprimirListaJ(TDAListaCircularJ *c){
	if (c->inicio==NULL){
		cout<<"\n"<<"La lista no está creada";
	}
	else {
	    TDANodoCircularJ *aux;
		aux=c->inicio;
		do{
			cout<<"\n"<<aux->info;
			aux=aux->sig;
		}while (aux!=c->inicio);
	}
    cout<<"\n";
}

TDAListaCircularJ *insertarNodoJ(TDAListaCircularJ *lista, TDANodoCircularJ *nodo){
    if(lista == NULL){
        lista = new TDAListaCircularJ;
        lista->inicio = lista->fin = nodo->sig = nodo;
    }
	else{
        lista->fin->sig = nodo;
        nodo->sig = lista->inicio;
        lista->fin = nodo;
    }
    return lista;
}

TDAListaCircularJ *eliminarJ(TDAListaCircularJ *lista){
	
	TDANodoCircularJ *aux, *recorrer;
	aux = lista->inicio;
	lista->inicio = aux->sig;
	lista->fin = aux->sig;
	recorrer = aux->sig;
	delete aux;
    while(recorrer != lista->inicio){
        recorrer = recorrer->sig;
    }
    lista->fin = recorrer;
	return lista;
}

TDAListaCircularJ *sentidoHorarioJ(TDAListaCircularJ *listaCircular, int dado){
   
    TDANodoCircularJ *aux, *recorrer;
    aux = listaCircular->inicio;
    for(int i=0; i<dado; i++){
        aux = aux->sig;
    }
    listaCircular->inicio = aux;
    recorrer = aux->sig;
    while(recorrer != listaCircular->inicio){
        recorrer = recorrer->sig;
    }
    listaCircular->fin = recorrer;
   
    return listaCircular;   
}

TDAListaCircularJ *sentidoAntiHorarioJ(TDAListaCircularJ *listaC, int dado, int cuantosQuedan){
	
	TDANodoCircularJ *aux, *recorrer;
	aux = listaC->inicio;
	if(cuantosQuedan > dado){
		int movimientos = cuantosQuedan - dado;
		for(int i=0; i<movimientos; i++){
			aux = aux->sig;
		}
		listaC->inicio = aux;
	    recorrer = aux->sig;
	    while(recorrer != listaCircular->inicio){
	        recorrer = recorrer->sig;
	    }
	    listaC->fin = recorrer;   
	}
	else if(cuantosQuedan < dado){		
		if(cuantosQuedan%dado == 0){
			return listaC;
		}
		else if(dado == (cuantosQuedan + 1)){			
			int movimientos = cuantosQuedan - 1;
			for(int i=0; i<movimientos; i++){
				aux = aux->sig;
			}
			listaC->inicio = aux;
		    recorrer = aux->sig;
		    while(recorrer != listaCircular->inicio){
		        recorrer = recorrer->sig;
		    }
		    listaC->fin = recorrer;
		}
	}
	return listaC;
}
