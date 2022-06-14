#include <string>
#include <iostream>
using namespace std;

struct cuentas {
	string numCuenta;
	string nombre;
	float saldo;
	string ciudad;
	string johnFechaCreacion;
};
struct TDANodo{
	cuentas informacion;
	TDANodo *sig;
};
cuentas JairoInformacion;
TDANodo *crearNodo (){
	
	TDANodo *aux;
	aux= new (TDANodo);
	cout<<endl<<"ingrese el nombre del cliente: ";
	cin>> JairoInformacion.nombre;
	cout<<endl<<"ingrese el numero de cuenta: ";
	cin>> JairoInformacion.numCuenta;
	cout<<endl<<"ingrese el saldo: ";
	cin>> JairoInformacion.saldo;
	cout<<endl<<"ingrese la ciudad: ";
	cin>> JairoInformacion.ciudad;
	cout<<endl<<"ingrese fecha de creacion, d/m/a: ";
	cin>> JairoInformacion.johnFechaCreacion;
	aux->informacion = JairoInformacion;
	aux->sig = NULL;
	return aux;
}

void mostrarInfo (TDANodo *aux){
	cout<<"nombre" <<aux->informacion.nombre<<endl;
	cout<<"numero de cuenta:"<<aux->informacion.numCuenta<<endl;
	cout<<"saldo"<<aux->informacion.saldo<<endl;
}

TDANodo *insertarNodos(TDANodo *inicio){
	
	if(inicio==NULL){
		inicio=crearNodo();
	}
	else{
		TDANodo *Nuevo=crearNodo();
		Nuevo->sig=inicio;
		inicio=Nuevo;
	}
	return inicio;
}

void mostrarLista(TDANodo *nodo){
    if(nodo == NULL){
        cout<<endl<<"La lista no tiene informacion"<<endl;

    }else{
        TDANodo *aux;
        aux = nodo;
        //int x =aux->informacion.ciudad.compare(aux->informacion.ciudad);
        while (aux != NULL){
            mostrarInfo(aux);
            aux=aux->sig;
        }
    }
}


void mostrarCiudad(string ciudad, TDANodo *Lista){
	int prueba;
	if (Lista == NULL){
		cout<<endl<<"Lista sin informacion "<<endl;
	} 
	else{
		TDANodo *aux;
		aux = Lista;
		while(aux!=NULL){
			prueba = ciudad.compare(aux->informacion.ciudad);
			cout<<"Valor de prueba:  "<<prueba<<endl;
			if (prueba == 0){
				mostrarInfo(aux);
			}
			aux = aux->sig;
		}
	}
}

TDANodo *borrarNodo(TDANodo *Lista, TDANodo *nodoBorrar){
	
	TDANodo *aux;
	if (Lista == NULL){
		cout<<"Lista Vacia"<<endl;
	}
	else
	{
		if (Lista == nodoBorrar) {
			Lista = Lista->sig;
		}
		else {
			aux = Lista;
			while (aux->sig != nodoBorrar){
				aux = aux->sig;
			}
			aux ->sig = nodoBorrar->sig;
		}
		delete nodoBorrar;
	}
	return Lista;
}

int main(){
	
	TDANodo *jairoDuq = NULL;
	string zuluagaCiudad = "Rionegro";
	jairoDuq=insertarNodos(jairoDuq);
	jairoDuq=insertarNodos(jairoDuq);
	jairoDuq=insertarNodos(jairoDuq);

	
	return 0;
}

