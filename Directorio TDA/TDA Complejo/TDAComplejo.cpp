# include <iostream> 

using namespace std;

struct TDAComplejo {
	int parteReal;
	int parteImaginaria;
};

//Crear un número complejo -> Función que devuelve un número complejo
TDAComplejo crearComplejo()
{
	TDAComplejo numero;
	
	cout<<"Ingresa la parte real:  ";
	cin>>numero.parteReal;
	cout<<"Ingresa la parte imaginaria:  ";
	cin>>numero.parteImaginaria;
	
	return numero;
}

TDAComplejo sumarComplejo(TDAComplejo numero1, TDAComplejo numero2)
{
	TDAComplejo total;
	total.parteReal  = numero1.parteReal + numero2.parteReal;
	total.parteImaginaria = numero1.parteImaginaria + numero2.parteImaginaria;
	
	return total;
}

void imprimirComplejo(TDAComplejo numero)
{
	if (numero.parteImaginaria>0){
		cout<<numero.parteReal<<"+"<<(numero.parteImaginaria)<<"i";
	}
	else {
		cout<<numero.parteReal<<""<<(numero.parteImaginaria)<<"i";
	}	
}

TDAComplejo restarComplejo(TDAComplejo numero1, TDAComplejo numero2)
{
	TDAComplejo total;
	total.parteReal  = numero1.parteReal - numero2.parteReal;
	total.parteImaginaria = numero1.parteImaginaria - numero2.parteImaginaria;
	
	return total;
}

TDAComplejo multiplicarComplejo(TDAComplejo numero1, TDAComplejo numero2)
{
	TDAComplejo total;
	total.parteReal  = ((numero1.parteReal * numero2.parteReal) - (numero1.parteImaginaria * numero2.parteImaginaria));
	total.parteImaginaria = ((numero1.parteReal * numero2.parteImaginaria) + (numero2.parteReal * numero1.parteImaginaria));
	
	return total;
}

TDAComplejo dividirComplejoNumerador(TDAComplejo numero1, TDAComplejo numero2)
{
	TDAComplejo numerador, denominador, complejoAuxiliar, num1, num2;
	complejoAuxiliar.parteReal = numero2.parteReal;
	complejoAuxiliar.parteImaginaria = numero2.parteImaginaria * -1;
	numerador.parteReal  = ((numero1.parteReal*complejoAuxiliar.parteReal) + (numero1.parteImaginaria*complejoAuxiliar.parteImaginaria*-1));
	numerador.parteImaginaria = (numero1.parteReal*complejoAuxiliar.parteImaginaria) + (numero1.parteImaginaria*complejoAuxiliar.parteReal);
	
	return numerador;
}

TDAComplejo dividirComplejoDenominador(TDAComplejo numero1, TDAComplejo numero2)
{
	TDAComplejo numerador, denominador, complejoAuxiliar, num1, num2;
	complejoAuxiliar.parteReal = numero2.parteReal;
	complejoAuxiliar.parteImaginaria = numero2.parteImaginaria * -1;
	denominador.parteReal = (numero2.parteReal*complejoAuxiliar.parteReal) + (numero2.parteImaginaria*complejoAuxiliar.parteImaginaria*-1);
	denominador.parteImaginaria = (numero2.parteReal*complejoAuxiliar.parteImaginaria) + (numero2.parteImaginaria*complejoAuxiliar.parteReal);
	
	return denominador;
}

void imprimirDivisionComplejo(TDAComplejo numero1, TDAComplejo numero2)
{
	if (numero1.parteImaginaria>0 && numero2.parteImaginaria>0){
		cout<<numero1.parteReal<<"+"<<(numero1.parteImaginaria)<<"i"<<" / "<<numero2.parteReal<<"+"<<numero2.parteImaginaria;
	}
	else if (numero1.parteImaginaria<0 && numero2.parteImaginaria>0){
		cout<<numero1.parteReal<<""<<(numero1.parteImaginaria)<<"i"<<" / "<<numero2.parteReal<<"+"<<numero2.parteImaginaria;
	}
	else if (numero1.parteImaginaria>0 && numero2.parteImaginaria<0){
		cout<<numero1.parteReal<<"+"<<(numero1.parteImaginaria)<<"i"<<" / "<<numero2.parteReal<<""<<numero2.parteImaginaria;
	}
	else if (numero1.parteImaginaria<0 && numero2.parteImaginaria<0){
		cout<<numero1.parteReal<<""<<(numero1.parteImaginaria)<<"i"<<" / "<<numero2.parteReal<<""<<numero2.parteImaginaria;
	}
	else{
		cout<<numero1.parteReal<<"+("<<(numero1.parteImaginaria)<<")i"<<" / "<<numero2.parteReal<<"+("<<numero2.parteImaginaria<<")";
	}
}

