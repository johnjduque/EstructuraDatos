#include<iostream>
using namespace std;

struct Estudiantejz{
	char inicialNombrejz;
	string nombrejz;
};

struct Programajz{
	Estudiantejz estjz;
	Programajz *sigjz;
};

Programajz *crearNodojz()
{
	Estudiantejz estudiantejz;
	Programajz *auxjz;
	cout<<"Ingrese la inicial del primer nombre del estudiante en minuscula:   "<<endl;
	cin>>estudiantejz.inicialNombrejz;
	cout<<"Ingrese el nombre del estudiante:  "<<endl;
	cin>>estudiantejz.nombrejz;
	auxjz = new (Programajz);
	auxjz->estjz = estudiantejz;
	auxjz->sigjz = NULL;
	return auxjz;
}

void mostrarInfojz(Programajz *nodojz){
	cout<<nodojz->estjz.nombrejz<<endl;
}

Programajz *buscarElementojz(Programajz *programajz, char inicial){
	Programajz *buscarjz = NULL;
	int encontradojz = 0;
	
	if(programajz == NULL){
		return buscarjz;
	}
	else{
		buscarjz=programajz;
		while(buscarjz!=NULL && !encontradojz){
			if (buscarjz->estjz.inicialNombrejz == inicial) {
				encontradojz =1;
			}
			else {
				buscarjz = buscarjz->sigjz;
			}
		}
	}
	return buscarjz;
}

Programajz *insertarNodojz(Programajz *listajz){
	
	Programajz *nuevojz, *auxjz;
	Estudiantejz estjz;
	
	if (listajz == NULL){
		listajz = crearNodojz();
	}
	else
	{
		cout<<"Ingrese la inicial del nombre del estudiante en minuscula:  ";
		cin>>estjz.inicialNombrejz;
		auxjz = buscarElementojz(listajz, estjz.inicialNombrejz);
		if (auxjz!=NULL){
			nuevojz = crearNodojz();
			nuevojz->sigjz = auxjz->sigjz;
			auxjz->sigjz = nuevojz;
		}
		else {
			cout<<"No fue posible el ingreso !!!\n";
		}

	}
	return listajz;	
}

void mostrarListajz(Programajz *iniciojz){
	if(iniciojz == NULL){
		cout<<"La lista está vacia";
	}
	else{
		Programajz *auxjz=iniciojz;
		while(auxjz!=NULL){
			mostrarInfojz(auxjz);
			auxjz=auxjz->sigjz;
		}
	}
}
