#include<iostream>
using namespace std;

struct Estudiantejz{
	char inicialNombrejz;
	string nombrejz;
	int edadjz;
	Estudiantejz *sigjz;
};

struct Programajz{
	string nombrejz;
	Estudiantejz *estjz;
	Programajz *progjz;
};

Estudiantejz *crearEstudiantejz()
{
	Estudiantejz *estjz;
	cout<<"Ingrese la letra inicial del primer nombre del alumno"<<endl;
	cin>>estjz->inicialNombrejz;
	cout<<"Ingrese el primer nombre del alumno"<<endl;
	cin>>estjz->inicialNombrejz;
	cout<<"Ingrese la edad del alumno"<<endl;
	cin>>estjz->edadjz;
	estjz = new (Estudiantejz);
	estjz->sigjz = NULL;
	return estjz;
}

Programajz *crearProgramajz()
{
	Programajz *auxjz;
	cout<<"Ingrese el nombre del programa"<<endl;
	cin>>auxjz->nombrejz;
	auxjz = new (Programajz);
	auxjz->estjz = NULL;
	auxjz->progjz = NULL;
	return auxjz;
}

Programajz *insertarProgramajz(Programajz *listajz){
	
	Programajz *nuevojz, *auxjz;
	
	if (listajz == NULL){
		listajz = crearProgramajz();
	}
	else
	{
		auxjz = listajz;
		while (auxjz->progjz!=NULL){
			auxjz = auxjz->progjz;
		}
		nuevojz=crearProgramajz();
		auxjz->progjz=nuevojz;
	}
	return listajz;	
}

Estudiantejz *buscarEstudiantejz(Estudiantejz *iniciojz, char inicialNombre){
	Estudiantejz *buscarjz = NULL;
	int encontradojz = 0;
	
	if(iniciojz == NULL){
		return buscarjz;
	}
	else{
		buscarjz=iniciojz;
		while(buscarjz!=NULL && !encontradojz){
			if (buscarjz->inicialNombrejz == inicialNombre) {
				encontradojz =1;
			}
			else {
				buscarjz = buscarjz->sigjz;
			}
		}
	}
	return buscarjz;
}

Estudiantejz *insertarEstudianteOrdenadojz(Estudiantejz *listajz){
	
	Estudiantejz *nuevojz, *auxjz;
	char nombrejz;
	
	if (listajz == NULL){
		listajz = crearEstudiantejz();
	}
	else
	{
		cout<<"Ingrese la inicial del primer nombre del estudiante"<<endl;
		cin>>nombrejz;
		auxjz = buscarEstudiantejz(listajz, nombrejz);
		if (auxjz!=NULL){
			nuevojz = crearEstudiantejz();
			nuevojz->sigjz = auxjz->sigjz;
			auxjz->sigjz = nuevojz;
		}
		else {
			cout<<"No fue posible el ingreso !!!\n"<<endl;
		}

	}
	return listajz;
}

void mostrarInfoEstjz(Estudiantejz *Nodojz){
	cout<<"Nombre: "<<Nodojz->nombrejz<<" y edad: "<<Nodojz->edadjz<<endl;
}

void mostrarInfoProgjz(Programajz *Nodojz){
	cout<<"Programa: "<<Nodojz->nombrejz<<endl;
	if(Nodojz->estjz == NULL){
		cout<<"El programa no tiene estudiantes inscritos"<<endl;
	}
	else{
		
		Estudiantejz *auxjz = NULL;
		auxjz = Nodojz->estjz;		
		while(auxjz!=NULL){
			mostrarInfoEstjz(auxjz);
			auxjz=auxjz->sigjz;
		}
	}
}

void mostrarInformacionjz(Programajz *iniciojz){
	if(iniciojz->progjz == NULL){
		cout<<"No hay programas ingresados"<<endl;
	}
	else{
		Programajz *auxjz=iniciojz;
		while(auxjz!=NULL){
			mostrarInfoProgjz(auxjz);
			auxjz=auxjz->progjz;
		}
	}
}
	
