#include "TDAArbolBB.cpp"
using namespace std;

int main(){
	
	tdaArbol *arbol = NULL;
	int numerosAIngresar, raizSubarbol;
	cout<<endl<<"¿Cuantos numeros desea ingresar al arbol"<<endl;
	cin>> numerosAIngresar;
	for(int i=0; i<numerosAIngresar; i++){
		if(esvacia(arbol)){
			int numeroIngresado;
			cout<<endl<<"Ingrese el numero entero y positivo"<<endl;
			cin>>numeroIngresado;
			arbol = crearArbol(numeroIngresado);
		}
		else{
			int numeroIngresado;
			cout<<endl<<"Ingrese el número entero y positivo"<<endl;
			cin>> numeroIngresado;
			arbol = insertarNodo(arbol, numeroIngresado);	
		}		
	}
	cout<<endl<<"Arbol antes de ingresar el valor del apuntador t"<<endl;
	preorden(arbol);
	
	cout<<endl<<"Ingrese el valor de la que quiere definir como raiz del subarbol a eliminar"<<endl;
	cin>>raizSubarbol;
	arbol = eliminarSubarbol(arbol, raizSubarbol);
	postorden(arbol);
	
	return 0;
}
