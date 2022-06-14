#include "TDAListaSimples.h"


int main(){
	TDAnodo *Lista = NULL;
	Informacion fec;
	mostrarLista(Lista);
	Lista = insertarNodoInicio(Lista);
	Lista = insertarNodoInicio(Lista);
	Lista = insertarNodoFinal(Lista);
	Lista = insertarNodoDespuesOtro(Lista);
	mostrarLista(Lista);
	fec.dia = 1;
	fec.mes = "1";
	fec.year=1;
	if (buscarElemento(Lista, fec) == NULL)
		cout <<"No encontrado";
	else
		cout<<"encontrado   ";
	return 0;
}
