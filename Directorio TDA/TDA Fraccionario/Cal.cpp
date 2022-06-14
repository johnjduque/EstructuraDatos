#include "TDAFraccionario.h"
# include <iostream> 
using namespace std;

int main()
{
	TDAFraccionario Numero1, Numero2, resultado, resultadoSimplificado;
	cout<<"Ingrese el Fraccionario 1"<<endl;
	Numero1 = crearFraccionario();
	cout<<"Ingrese el Fraccionario 2"<<endl;
	Numero2 = crearFraccionario();
	resultado = sumarFraccionario(Numero1,Numero2);
	cout<<"El resultado de la suma es: "<<endl;
	imprimirFraccionario(resultado);
	resultadoSimplificado = simplificarFraccionario(resultado);
	cout<<"\nEl resultado de la suma simplificada es: ";
	imprimirFraccionario(resultadoSimplificado);
	return 0;
}
