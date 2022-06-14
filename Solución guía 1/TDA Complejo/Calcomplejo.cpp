#include "TDAComplejo.h"
# include <iostream> 
using namespace std;

int main()
{
	TDAComplejo Numero1, Numero2, resultado, resultadoMult, resultadoRest,resultadoDivNumerador, resultadoDivDenominador;
	cout<<"Ingrese el complejo 1"<<endl;
	Numero1 = crearComplejo();
	cout<<"Ingrese el complejo 2"<<endl;
	Numero2 = crearComplejo();
	resultado = sumarComplejo(Numero1,Numero2);
	resultadoRest = restarComplejo(Numero1,Numero2);
	resultadoMult = multiplicarComplejo(Numero1,Numero2);
	resultadoDivNumerador = dividirComplejoNumerador(Numero1,Numero2);
	resultadoDivDenominador = dividirComplejoDenominador(Numero1,Numero2);
	cout<<"El resultado de la suma es: "<<endl;
	imprimirComplejo(resultado);
	cout<<"\nEl resultado de la resta es: "<<endl;
	imprimirComplejo(resultadoRest);
	cout<<"\nEl resultado de la multiplicacion es: "<<endl;
	imprimirComplejo(resultadoMult);
	cout<<"\nEl resultado de la division es: "<<endl;
	imprimirDivisionComplejo(resultadoDivNumerador,resultadoDivDenominador);
	return 0;
}
