#include "TDAListaDoble.cpp"
#include <cstdlib>
#include <string.h>
# include <iostream>
using namespace std;

bool validarNumero( string num){
	
	int i=0, longitud;
	bool  validar=true;
	longitud =num.length() ;
    while  (i <longitud and validar){
    	if (!isdigit(num[i])){
    		validar = false;    		
		}
		i = i+1;
	}
   
	return validar;
}

TDAListaDoble *dividirNumero(string num){
	
	int longitud = num.length();
	string numeroAd;
	int numeroInt;
	TDAListaDoble *Lista = Inicilizar();
	nodoLDE *aux;

	longitud =num.length();
	cout<<"Ingreso a dividir!!! "<<endl;
	while  (longitud >=3){
		
  		numeroAd.append(num,longitud - 3,3);

  		numeroInt =atoi(numeroAd.c_str()) ;
  		if (num.length()==longitud) {
  			crearLista(Lista,numeroInt);
		 }
		else {
			aux = crearNodo(numeroInt);
			InsertarPorCabeza( Lista, aux);
  		}
   		numeroAd="";
   		longitud= longitud -3;
	}
	if (longitud > 0){
		numeroAd.append(num,0,longitud);
		numeroInt =atoi(numeroAd.c_str()) ;
		aux = crearNodo(numeroInt);
		InsertarPorCabeza( Lista, aux);
	}
	return Lista;
}

int Dimension(TDAListaDoble *lista){
		
	nodoLDE *aux;
	aux=lista->inicio;
	int dimension = 1;
	
	while(aux->sig != NULL){
		dimension ++;
		aux=aux->sig;
	}
	return dimension;
}

int cuantosDigitos(int numero){
	int cuantosDigitos = 0;
	int aux = numero;
	while(aux > 0){
		aux = aux/10;
		cuantosDigitos ++;
	}
	return cuantosDigitos;
}

void numeraATexto(int numero, char arreglo[]){
	
	int digitos = cuantosDigitos(numero);
	arreglo[digitos] = '\0';
	int aux = numero;
	int posicion = digitos - 1, digito;
	while(posicion >= 0){
		digito = aux%10;
		aux = aux/10;
		arreglo[posicion] = digito + '0';
		posicion --;
	}
}

TDAListaDoble *multiplicar(TDAListaDoble *lista1, TDAListaDoble *lista2)
{
	TDAListaDoble  *lista3, *listaAux;
	lista3 = Inicilizar();
	listaAux = Inicilizar();
	
    nodoLDE *aux1, *aux2, *aux3, *aux4, *auxLista, *nodoNuevo;
    nodoNuevo = new(nodoLDE);
    aux1=lista1->fin;
    aux2=lista2->fin;
    aux3=lista1->inicio;
    aux4=lista2->inicio;
    int listaVacia=0;
    int acarreo = 0;
    int numeroNuevo, restaANumNuevo;
    int var1 = Dimension(lista1);
    int var2 = Dimension(lista2);
    int filas = var1 * var2;
	int columnas, columnasNuevoNum;
	int filaInicial = 0;
	int result;
	string num; 
	
	if(aux3->info * aux4->info >= 1000){
		columnas = var1 + var2;
		columnasNuevoNum = var1 + var2;
	}
	else{
		columnas= var1 + var2 - 1;
		columnasNuevoNum = var1 + var2 - 1;
	}	
	int multiplicacion[filas][columnas];
	int controlColumna = columnas - 1;
				
	while (aux2!=NULL){
			
		while(aux1!=NULL){
			
  			result = aux2->info * aux1->info; 
			char numero[cuantosDigitos(result)];
			numeraATexto(result, numero);
			listaAux = dividirNumero(numero);
			auxLista = listaAux->fin;
			while (auxLista!=NULL){
				multiplicacion[filaInicial][columnas-1] = auxLista->info;
				cout<<"matriz:  "<<multiplicacion[filaInicial][columnas-1]<<endl;
				auxLista = auxLista->ant;
				columnas = columnas - 1;
			}
			filaInicial = filaInicial + 1;
			columnas = columnas + 1;
			aux1 = aux1->ant;
		}	
	    aux1 = lista1->fin; 
		aux2 = aux2->ant;   
	}
	filaInicial = 0;
	for(int i=(columnasNuevoNum - 1); i>=0 && i<columnasNuevoNum; i--){
		for(int j=0; j<filas; j++){
			numeroNuevo += multiplicacion[j][i] + acarreo;
		}
		acarreo = 0;		
		if(numeroNuevo >= 1000){
			acarreo = numeroNuevo/1000;
			cout<<endl<<"acarreo"<<acarreo<<endl;
			restaANumNuevo = acarreo * 1000;
			numeroNuevo = numeroNuevo - restaANumNuevo;	
			cout<<endl<<"numero nuevo  "<< numeroNuevo<<endl;			
		}
		else{
			numeroNuevo = numeroNuevo;
			cout<<endl<<"numero nuevo  "<< numeroNuevo<<endl;
		}
		
		nodoNuevo = crearNodo(numeroNuevo);
		
		if(listaVacia==0){
	        lista3 = crearLista(lista3, nodoNuevo->info);
	        listaVacia++;
		}
		else{
	        InsertarPorCabeza(lista3, nodoNuevo);				
		}
	}
	return lista3;
}

int main(){
	
	TDAListaDoble  *ListaNumero1 = NULL;
	TDAListaDoble  *ListaNumero2 = NULL;
	string numero1, numero2;
	bool numeroNegativo = false;
	
	cout<<"Ingrese el primer numero positivo a multiplicar :  --->  ";
	cin >>numero1;
	
	cout<<"Ingrese el segundo numero positivo a multiplicar :  --->  ";
	cin >>numero2;
	
	int num1 = atoi(numero1.c_str());
	int num2 = atoi(numero2.c_str());
	
	if(num1 < 0 or num2 < 0){
		numeroNegativo = true;
	}
	else{		
		if(num1 < num2){
		string aux;
		aux = numero1;
		numero1 = numero2;
		numero2 = aux;
		}
	}
	if (validarNumero(numero1)){
		ListaNumero1 = dividirNumero(numero1);
		ImprimirLista(ListaNumero1);
	}
	else {
		cout<<"\nEl valor digitado para el primer numero no es un numero o es un numero negativo\n";
	}
	
	if (validarNumero(numero2)){
		ListaNumero2 = dividirNumero(numero2);
		ImprimirLista(ListaNumero2);
	}
	else {
		cout<<"\nEl valor digitado para el segundo numero no es un numero o es un numero negativo\n";
	}
	
	if(numeroNegativo){
		cout<<endl<<"Error: Numeros con signo negativo no estan permitidos para realizar la operacion"<<endl;
	}
	else{
		cout<<endl<<"Resultado"<<endl;
		ImprimirLista(multiplicar(ListaNumero1, ListaNumero2));
	}

	return 0;
}
