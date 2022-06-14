//John Jairo Duque Zuluaga - hora inicio: 19:45

# include <iostream> 

using namespace std;

struct TDADuqPolinomio {
	int duqParteXCuadrado;
	int duqPartex;
	int duqParteIndependiente;
};

TDADuqPolinomio duqCrearPolinomio()
{
	TDADuqPolinomio duqnumero;
	
	cout<<"Ingresa la constante de x^2:  ";
	cin>>duqnumero.duqParteXCuadrado;
	cout<<"Ingresa la constante de x:  ";
	cin>>duqnumero.duqPartex;
	cout<<"Ingresa la constante independiente:  ";
	cin>>duqnumero.duqParteIndependiente;
	
	return duqnumero;
}

TDADuqPolinomio duqSumarPolinomio(TDADuqPolinomio duqPol1, TDADuqPolinomio duqPol2)
{
	TDADuqPolinomio duqTotal;
	duqTotal.duqParteXCuadrado = duqPol1.duqParteXCuadrado + duqPol2.duqParteXCuadrado;
	duqTotal.duqPartex = duqPol1.duqPartex + duqPol2.duqPartex;
	duqTotal.duqParteIndependiente = duqPol1.duqParteIndependiente + duqPol2.duqParteIndependiente;
		
	return duqTotal;
}

void duqImprimirPolinomio(TDADuqPolinomio duqPolinomio)
{
	cout<<"("<<duqPolinomio.duqParteXCuadrado<<")"<<"(X^2)"<<"+"<<"("<<duqPolinomio.duqPartex<<")"<<"X"<<"+"<<"("<<duqPolinomio.duqParteIndependiente<<")"<<endl;
}


