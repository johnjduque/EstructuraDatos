#include<iostream>
using namespace std;

struct JohnBloque{
	int formaduq;
	int colorduq;
	int grosorduq;
};

struct TDADuquePila{
	JohnBloque infoduq;
	TDADuquePila *sigduq;
};

JohnBloque crearBloqueJairo(){

	JohnBloque auxduq;
	cout<<"Ingrese la forma: 1 cuadrado, 2 triangulo, 3 rectangulo, 4 pentagono, 5 circulo"<<"\n";
	cin>> auxduq.formaduq;
	cout<<"Ingrese el color: 1 azul, 2 rojo, 3 amarillo"<<"\n";
	cin>> auxduq.colorduq;
	cout<<"Ingrese el grosor: 1 delgado, 2 grueso"<<"\n";
	cin>> auxduq.grosorduq;

	return auxduq;
}

TDADuquePila *insertarPilaInfoZuluaga(TDADuquePila *listaduq, JohnBloque informacionduq){
	TDADuquePila *topeduq;
	
	topeduq=new(TDADuquePila);
	topeduq->infoduq = informacionduq;
	topeduq->sigduq=listaduq;
	listaduq=topeduq;
	return listaduq;	
}

TDADuquePila *insertarListaInfoZuluaga(TDADuquePila *listaduq, JohnBloque informacionduq){
	TDADuquePila *topeduq;
	
	topeduq=new(TDADuquePila);
	topeduq->infoduq = informacionduq;
	topeduq->sigduq=listaduq;
	listaduq=topeduq;
	return listaduq;	
}




