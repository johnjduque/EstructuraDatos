#include "TDAListaSimplesEnteros.h"


int main(){
  TDAnodo *listaUno, *nodo, *johnJLista2;
  Informacion bor;
  
  listaUno=NULL;
  listaUno=insertarNodoInicio(listaUno);
  listaUno=insertarNodoInicio(listaUno);
  listaUno=insertarNodoInicio(listaUno);
  listaUno=insertarNodoInicio(listaUno);
  listaUno=insertarNodoInicio(listaUno);
  mostrarLista(listaUno);

  cout<<endl<<"Lista 2"<<endl;  
  johnJLista2=johnJairoInsertarNodoParaOtraLista(listaUno);
  mostrarLista(johnJLista2);
  
  return 0;
  
}
