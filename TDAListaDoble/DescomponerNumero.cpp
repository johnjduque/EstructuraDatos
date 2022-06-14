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

TDAListaDoble *sumar(TDAListaDoble *lista1, TDAListaDoble *lista2)
{
	TDAListaDoble  *lista3;
	lista3 = Inicilizar();
	
    nodoLDE *aux1, *aux2;
    aux1=lista1->fin;
    aux2=lista2->fin;
    int i=0;
    int acarreo = 0;
    int numeroNuevo;
    int var1 = Dimension(lista1);
    int var2 = Dimension(lista2);
    if (var1 == var2)
    {
    	nodoLDE *nodoNuevo;
		nodoNuevo = new(nodoLDE);
		
		while (aux1!=NULL && aux2!=NULL){
	        numeroNuevo = aux1->info + aux2->info + acarreo;
			acarreo=0;       
	        
	        if(numeroNuevo>=1000){
	        	while(numeroNuevo>=1000){
	        		numeroNuevo=numeroNuevo-1000;
	        		acarreo=acarreo+1;
				}
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
    	if(acarreo>0){
    		nodoNuevo = crearNodo(acarreo);
    		InsertarPorCabeza(lista3, nodoNuevo);
		}
	}
	else if (var1 < var2)
	{
		int auxiliar = var2 - var1;
		nodoLDE *nodoNuevo;
		
		for(int j = 0; j < auxiliar; j++)
		{
			nodoNuevo = new(nodoLDE);
			numeroNuevo = aux1->info + aux2->info + acarreo;
			acarreo = 0;   
			
	        if(numeroNuevo>=1000){
	        	while(numeroNuevo>=1000){
	        		numeroNuevo=numeroNuevo-1000;
	        		acarreo=acarreo+1;
				}
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
    	while(aux2->ant != NULL && acarreo>0){
			nodoNuevo = new(nodoLDE);
			numeroNuevo = aux2->info + acarreo;
			acarreo = 0; 
			nodoNuevo = crearNodo(numeroNuevo);
    		InsertarPorCabeza(lista3, nodoNuevo);
    		aux2=aux2->ant;
		}
		while(aux2 != NULL){
			nodoNuevo = new(nodoLDE);
			nodoNuevo = crearNodo(aux2->info);
	    	InsertarPorCabeza(lista3, nodoNuevo);
			aux2=aux2->ant;	
		}	
	}	
	else if (var1 > var2)
	{
		int auxiliar = var1 - var2;
		nodoLDE *nodoNuevo;
		
		for(int j = 0; j < auxiliar; j++)
		{
			nodoNuevo = new(nodoLDE);
			numeroNuevo = aux1->info + aux2->info + acarreo;
			acarreo = 0;   
			
	        if(numeroNuevo>=1000){
	        	while(numeroNuevo>=1000){
	        		numeroNuevo=numeroNuevo-1000;
	        		acarreo=acarreo+1;
				}
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
    	while(aux1->ant != NULL && acarreo>0){
			nodoNuevo = new(nodoLDE);
			numeroNuevo = aux1->info + acarreo;
			acarreo = 0; 
			nodoNuevo = crearNodo(numeroNuevo);
    		InsertarPorCabeza(lista3, nodoNuevo);
    		aux1=aux1->ant;
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
	
	cout<<"Ingrese el numero 1 :  --->  ";
	cin >>numero1;
	
	cout<<"Ingrese el numero 2 :  --->  ";
	cin >>numero2;

	if (validarNumero(numero1)){
		ListaNumero1 = dividirNumero(numero1);
		ImprimirLista(ListaNumero1);
	}
	else {
		cout<<"\nEl valor digitado para numero 1 no es un numero\n";
	}
	
	if (validarNumero(numero2)){
		ListaNumero2 = dividirNumero(numero2);
		ImprimirLista(ListaNumero2);
	}
	else {
		cout<<"\nEl valor digitado para numero 2 no es un numero\n";
	}
	
	cout<<endl<<"Resultado"<<endl;
	ImprimirLista(sumar(ListaNumero1, ListaNumero2));

	return 0;
}
