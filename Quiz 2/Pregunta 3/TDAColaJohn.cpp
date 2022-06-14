#include<iostream>
using namespace std;


struct PacienteDuque{
	string nombreJohn;
	int edadJairo;
};
 
struct TDANodoZuluaga{
	PacienteDuque infoduq;
	TDANodoZuluaga *sigduq;
};

struct TDAColaJohn{
	TDANodoZuluaga *inicioduq;
	TDANodoZuluaga  *finduq;
};

TDANodoZuluaga *crearNodoJairo(){
	
	TDANodoZuluaga *auxduq;
	auxduq = new (TDANodoZuluaga);
	cout<<endl<<"Ingrese el nombre "<<" \n";
	cin>> auxduq->infoduq.nombreJohn;
	cout<<"Ingrese la edad "<<" \n";
	cin>> auxduq->infoduq.edadJairo;
	auxduq->sigduq =NULL;
	return auxduq;
}

bool esColaVaciaDuque(TDAColaJohn *coladuq){
	if (coladuq==NULL) 
		return true;		
	else
		return false;
}

TDAColaJohn *insertarColaZuluaga(TDAColaJohn *coladuq){
	if (esColaVaciaDuque(coladuq)){
		coladuq = new(TDAColaJohn);
		coladuq->inicioduq = coladuq->finduq = crearNodoJairo();
	}
	else{
		TDANodoZuluaga *Nuevo = crearNodoJairo();
		coladuq->finduq->sigduq = Nuevo;
		coladuq->finduq = Nuevo;
	}
	return coladuq;
}

void mostrarNodoZuluaga(TDAColaJohn *cola){

	cout<<endl<<"Nombre: "<<cola->inicioduq->infoduq.nombreJohn<<endl;
	cout<<"Edad: "<<cola->inicioduq->infoduq.edadJairo<<endl;
}

void mostrarColaZuluaga(TDAColaJohn *cola){
	if(esColaVaciaDuque(cola)){
		cout<<"La Cola está vacia";
	}
	else{
		mostrarNodoZuluaga(cola);
	}
}

TDAColaJohn *eliminarColaZuluaga(TDAColaJohn *cola){
  if(!esColaVaciaDuque(cola)){
    TDANodoZuluaga *aux=cola->inicioduq;
    if (cola->inicioduq == cola->finduq) {
    	cola=NULL;
	}
    else {
    	cola->inicioduq=cola->inicioduq->sigduq;
	}
    delete(aux);
  }
  return cola;
}

TDAColaJohn *destruirColaZuluaga(TDAColaJohn *cola){

	while (not(esColaVaciaDuque(cola))){
		cout<<"Eliminado ";
		mostrarColaZuluaga(cola);
		cola=eliminarColaZuluaga(cola);
	}	
	return cola;
}
