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
	cout<<endl<<"Ingreso a dividir en lista circular!!! "<<endl;
	while  (longitud >=3){
		
  		numeroAd.append(num,longitud - 3,3);

  		numeroInt =atoi(numeroAd.c_str()) ;
  		if (num.length()==longitud){
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

TDAListaDoble *restar(TDAListaDoble *lista1, TDAListaDoble *lista2){
	
	TDAListaDoble  *lista3;
	lista3 = Inicilizar();
	
    nodoLDE *aux1, *aux2;
    aux1=lista1->fin;
    aux2=lista2->fin;
    int i=0;
    int presta = 0;
    int numeroNuevo;
    int var1 = Dimension(lista1);
    int var2 = Dimension(lista2);
    if (var1 == var2)
    {
    	nodoLDE *nodoNuevo;
		nodoNuevo = new(nodoLDE);
		
		while (aux1!=NULL && aux2!=NULL){
			
			if(aux1->info < aux2->info){
				aux1->info = aux1->info + 1000;
				numeroNuevo = aux1->info - aux2->info;
				presta = 1;
			}
			else{
				numeroNuevo = aux1->info - aux2->info - presta;
				presta = 0; 
			}	              
	        			
			nodoNuevo = crearNodo(numeroNuevo);
	        
	        if(i==0){
	        	lista3 = crearLista(lista3, nodoNuevo->info);
	        	i++;
			}
			else{
	        	InsertarPorCabeza(lista3, nodoNuevo);				
			}
	        
	        aux1=aux1->ant;
	        aux2=aux2->ant;
    	}
	}	
	else if (var1 > var2)
	{
		nodoLDE *nodoNuevo;
		
		for(int j = 0; j < var2; j++)
		{
			nodoNuevo = new(nodoLDE);
			if(aux1->info < aux2->info){
				aux1->info = aux1->info + 1000;
				numeroNuevo = aux1->info - aux2->info;
				presta = 1;
			}
			else{
				numeroNuevo = aux1->info - aux2->info - presta;
				presta = 0; 
			}	              
	        			
			nodoNuevo = crearNodo(numeroNuevo);
	        
	        if(i==0){
	        	lista3 = crearLista(lista3, nodoNuevo->info);
	        	i++;
			}
			else{
	        	InsertarPorCabeza(lista3, nodoNuevo);				
			}
	        
	        aux1=aux1->ant;
	        aux2=aux2->ant;
    	}   
		while(aux1 != NULL){
			nodoNuevo = new(nodoLDE);
			nodoNuevo = crearNodo(aux1->info);
	    	InsertarPorCabeza(lista3, nodoNuevo);
			aux1=aux1->ant;	
		}	
	}
    return lista3;
}

int main(){
	
	TDAListaDoble  *ListaNumero1 = NULL;
	TDAListaDoble  *ListaNumero2 = NULL;
	string numero1, numero2;
	bool restarPorMenosUno = false;
	bool numerosIguales = false;
	bool numeroNegativo = false;
	
	cout<<"Ingrese el primer numero positivo a restar :  --->  ";
	cin >>numero1;
	
	cout<<"Ingrese el segundo numero positivo a restar :  --->  ";
	cin >>numero2;
	
	int num1 = atoi(numero1.c_str());
	int num2 = atoi(numero2.c_str());
	
	if(num1 < 0 or num2 < 0){
		numeroNegativo = true;
	}
	else if(num1 == num2){
		numerosIguales = true;
	}
	else{
		
		if(num1 < num2){
		string aux;
		aux = numero1;
		numero1 = numero2;
		numero2 = aux;
		restarPorMenosUno = true;
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
	if(numerosIguales){
		cout<<endl<<"El resultado es neutro: "<<endl;	
		ImprimirLista(restar(ListaNumero1, ListaNumero2));
	}
	else if(numeroNegativo){
		cout<<endl<<"Error: Numeros con signo negativo no estan permitidos para realizar la operacion"<<endl;
	}
	else{
		if(restarPorMenosUno){
		cout<<endl<<"El resultado es negativo: -"<<endl;	
		ImprimirLista(restar(ListaNumero1, ListaNumero2));
		}
		else{
			cout<<endl<<"El resultado es positivo: +"<<endl;	
			ImprimirLista(restar(ListaNumero1, ListaNumero2));
		}
	}

	return 0;
}
