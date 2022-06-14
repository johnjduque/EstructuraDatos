#include "TDAListaSimples.h"


int main(){
	TDAnodo *Lista = NULL;
	mostrarLista(Lista);
	Lista = insertarNodoInicio(Lista);
	Lista = insertarNodoInicio(Lista);
	Lista = insertarNodoFinal(Lista);
	Lista = insertarNodoFinal(Lista);
	Lista = insertarNodoFinal(Lista);
	mostrarLista(Lista);
	
	return 0;
}
