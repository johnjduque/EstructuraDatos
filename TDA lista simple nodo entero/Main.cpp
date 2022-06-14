#include "TDAListaSimplesEnteros.h"


int main(){
TDAnodo *listaUno, *nodo;
Informacion bor;
listaUno=NULL;
listaUno=insertarNodoInicio(listaUno);
listaUno=insertarNodoInicio(listaUno);
listaUno=insertarNodoInicio(listaUno);
listaUno=insertarNodoInicio(listaUno);
listaUno=insertarNodoInicio(listaUno);
mostrarLista(listaUno);
bor.numero =1;
nodo = buscarElemento(listaUno,bor);
listaUno = borrarNodo(listaUno,nodo);
mostrarLista(listaUno);
return 0;
}
