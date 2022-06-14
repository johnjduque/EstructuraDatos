#include "FinalEDD2.h"
using namespace std;

int main(){
	
	Programajz *sistemasjz = NULL;
	Programajz *industrialjz = NULL;
	Programajz *ambientaljz = NULL;
	
	cout<<"Programas registrados: 1 sistemas, 2 industrial, 3 ambiental"<<endl;
	int seguir = 0;
	while(seguir == 0){
		int caso;
		cout<<"Cuando no desee ingresar mas estudiantes digite cero cuando vaya a ingresar el codigo del programa"<<endl;
		cout<<"A cual programa desea ingresar un estudiante, por favor presione 1, 2 ó 3 segun sea el caso:   "<<endl;
		cin>>caso;
		
		if(caso == 1){
			sistemasjz = insertarNodojz(sistemasjz);
		}
		else if(caso == 2){
			industrialjz = insertarNodojz(industrialjz);			
		}
		else if(caso == 3){
			ambientaljz = insertarNodojz(ambientaljz);			
		}
		else{
			seguir = 1;
		}
	}
	
	int prog;
	cout<<"Cual programa desea ver la lista de estudiantes"<<endl;
	cout<<"Por favor indique el codigo del programa en caso de querer ver todas las listas ingrese otro numero diferente a los codigos"<<endl;
	cin>>prog;
	
	if(prog == 1){
		mostrarListajz(sistemasjz);
	}
	else if(prog == 2){
		mostrarListajz(industrialjz);			
	}
	else if(prog == 3){
		mostrarListajz(ambientaljz);			
	}
	else{
		mostrarListajz(sistemasjz);	
		mostrarListajz(industrialjz);
		mostrarListajz(ambientaljz);					
	}	
	
	return 0;
}
