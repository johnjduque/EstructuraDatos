# include <iostream> 
using namespace std;

struct TDAFraccionario {
	int numerador;
	int denominador;
};

//Crear un fracccionario -> Función que devuelve un numero fraccionario
TDAFraccionario crearFraccionario()
{
	TDAFraccionario fraccionario;
	
	cout<<"Ingresa el numerador:  ";
	cin>>fraccionario.numerador;
	do {
		cout<<"Ingresa el denominador (recuerde que no puede ser cero):  ";
		cin>>fraccionario.denominador;
	}while (fraccionario.denominador == 0);
	
	return fraccionario;
}

TDAFraccionario sumarFraccionario(TDAFraccionario Frac1, TDAFraccionario Frac2)
{
	TDAFraccionario total;
	total.numerador  = Frac1.numerador * Frac2.denominador +  Frac1.denominador * Frac2.numerador;
	total.denominador = Frac1.denominador * Frac2.denominador;
	
	return total;
}

void imprimirFraccionario(TDAFraccionario fraccionario)
{
	cout<<fraccionario.numerador<<"/"<<fraccionario.denominador;
}

TDAFraccionario restarFraccionario(TDAFraccionario Frac1, TDAFraccionario Frac2)
{
	TDAFraccionario total;
	total.numerador  = Frac1.numerador * Frac2.denominador +  Frac1.denominador * Frac2.numerador;
	total.denominador = Frac1.denominador * Frac2.denominador;
	
	return total;
}

TDAFraccionario multiplicarFraccionario(TDAFraccionario Frac1, TDAFraccionario Frac2)
{
	TDAFraccionario total;
	total.numerador  = Frac1.numerador * Frac2.numerador;
	total.denominador = Frac1.denominador * Frac2.denominador;
	
	return total;
}

TDAFraccionario dividirFraccionario(TDAFraccionario Frac1, TDAFraccionario Frac2)
{
	TDAFraccionario total;
	total.numerador  = Frac1.numerador * Frac2.denominador ;
	total.denominador = Frac1.denominador * Frac2.numerador;
	
	return total;
}

TDAFraccionario simplificarFraccionario(TDAFraccionario Frac)
{	
	TDAFraccionario total;
	for (int i = 2; i <= 11; i++){
		while(Frac.numerador % i == 0 && Frac.denominador % i == 0){
			total.numerador = Frac.numerador / i;
			total.denominador = Frac.denominador / i;
			Frac.numerador = total.numerador;
			Frac.denominador = total.denominador;
		}
	}
	return total;
}

