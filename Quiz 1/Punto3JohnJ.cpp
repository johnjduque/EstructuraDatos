//John Jairo Duque Zuluaga - hora inicio: 20:07

#include "Punto3JohnJairo.h"
# include <iostream> 
using namespace std;

int main()
{
	TDADuqPolinomio duqNumero1, duqNumero2, duqResultado;
	cout<<"Ingrese el Polinomio 1"<<endl;
	duqNumero1 = duqCrearPolinomio();
	cout<<"Ingrese el Polinomio 2"<<endl;
	duqNumero2 = duqCrearPolinomio();
	duqResultado = duqSumarPolinomio(duqNumero1 , duqNumero2);
	cout<<"El resultado de la suma es: "<<endl;
	duqImprimirPolinomio(duqResultado);
	return 0;
}
