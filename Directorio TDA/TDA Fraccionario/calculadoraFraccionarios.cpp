#include "TDAFraccionario.h"
#include <conio.h>
# include <iostream>
using namespace std;


int main (){
	TDAFraccionario fraccionario1, fraccionario2;
	short opcion;
	do {
		system("cls");
		cout<<"\n\nCALCULADORA DE FRACCIONARIOS\n\n1. Sumar Fraccionario.\n2. Restar Fraccionario.\n";
		cout<<"3. Multiplica Fraccionario.\n4. Dividir Fraccionario.\n\n5.Salir de la calculadora\n\n";
		cin>>opcion;
		switch (opcion) {
			case 1: 
					cout <<"Ingrese el Fraccionario 1\n";
					fraccionario1 = crearFraccionario();
					cout <<"Ingrese el Fraccionario 2"<<endl;
					fraccionario2 = crearFraccionario();
					cout <<"El Resultado es:  "<<endl;
					imprimirFraccionario(sumarFraccionario(fraccionario1,fraccionario2));
					cout <<"\nPulsa cualquier tecla para volver al menú\n";
					getch();
					break;
		}
	}while (opcion != 5);
	return 0;
}
