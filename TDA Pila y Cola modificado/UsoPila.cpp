#include "TDAPila.cpp"

int main(){
  TDAPila  *pila1;


  pila1=NULL;
  pila1=insertarPila(pila1);
  pila1=insertarPilaInformacion(pila1,'b');
  pila1=insertarPilaInformacion(pila1,'c');
  pila1=insertarPilaInformacion(pila1,'d');

  mostrarPila(pila1);
  
  pila1 = eliminarTope(pila1);
  
  if (esPilaVacia(pila1)){
  	cout<<"Pila Sin datos"<<endl;
  }
  else {
  	cout<<"El tope es:  "<<pila1->info<<endl;
  }
  
  pila1 = destruirPila(pila1);
  return 0;
  
}

