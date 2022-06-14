#include "TDACola.cpp"

int main(){
  TDACola  *cola1;


  cola1=NULL;
  
  cola1=insertarCola(cola1);
  cola1=insertarCola(cola1);
  cola1=insertarCola(cola1);
  cola1=insertarCola(cola1);
  cout<<"El siguiente en atender en la cola es"<<endl;
  mostrarCola(cola1);
  cola1 = eliminarCola(cola1);
  
  if (esColaVacia(cola1)){
  	cout<<"Cola Sin datos"<<endl;
  }
  else {
  	cout<<"El siguiente en atender en la cola es:  "<<endl;
  	mostrarCola(cola1);
  }
  
  cola1 = destruirCola(cola1);
  return 0;
  
}

