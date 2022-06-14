#include <string>
#include <iostream>
using namespace std;

struct cuentas {
	string numCuenta;
	string nombre;
	float saldo;
	string ciudad;
};

struct movimientos{
	string johnTipoMovimiento;
	string jairoNumCuentaTrans;
	float duqueValor;
	string zuluagaEstado;
};

struct TDAJJMov{
	movimientos info;
	TDAJJMov *sig;
};

struct TDANodo{
	cuentas informacion;
	TDANodo *sig;
	TDANodo *johnMov;
};

TDANodo *crearNodo (){
	TDANodo *aux;
	aux= new (TDANodo);
	cout<<"ingrese el nombre del cliente";
	cin>> aux->informacion.nombre;
	cout<<"ingrese el numero de cuenta";
	cin>> aux->informacion.numCuenta;
	cout<<"ingrese el saldo";
	cin>> aux->informacion.saldo;
	cout<<"ingrese la ciudad";
	cin>> aux->informacion.ciudad;
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
        cout<<"La lista no tiene informacion";

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
		cout<<"Lista sin informacion ";
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

TDAJJMov *johnCrearMovimiento (){
	TDAJJMov *aux;
	aux= new (TDAJJMov);
	cout<<"ingrese tipo de movimiento, 1 para deposito, 2 para retiro, 3 para tranferencia";
	cin>> aux->info.johnTipoMovimiento;
	cout<<"ingrese el numero de cuenta a transferir";
	cin>> aux->info.jairoNumCuentaTrans;
	cout<<"ingrese el valor";
	cin>> aux->info.duqueValor;
	cout<<"ingrese el estado, 1 aplicado, 2 no aplicado";
	cin>> aux->info.zuluagaEstado;
	aux->sig = NULL;
	return aux;
}

TDANodo *johnInsertarMovimientoCliente(cuentas jairoNumCuenta, TDANodo *inicio){
	
	TDANodo *johnBuscar=NULL;
	TDANodo *nuevo;
	int jairoEncontrado = 0;
	
	johnBuscar=inicio;
	while(johnBuscar!=NULL && !jairoEncontrado){
		if (johnBuscar->informacion.numCuenta==jairoNumCuenta.numCuenta) {
				if(inicio==NULL){
					inicio=johnCrearMovimiento();
				}
				else{
					TDAJJMov *Nuevo=johnCrearMovimiento();
					Nuevo->sig=johnBuscar;
					johnBuscar=Nuevo;
				}
			encontrado =1;
		}
		else {
			johnBuscar = johnBuscar->sig;
		}

	return johnBuscar;
}
