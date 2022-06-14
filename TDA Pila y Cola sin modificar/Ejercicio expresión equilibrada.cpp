#include "TDAPila.cpp"

int main(){
	
	TDAPila *pila1;
	string expresion;
	
	pila1 = NULL;
	cout<<"ingrese una expresion "<<endl;
	cin>>expresion;
	
	for(int i=0; i <= expresion.length(); i++){
		
		if (expresion[i] == '(' or expresion[i] == '{'or expresion[i] =='['){
			pila1 = insertarPilaInformacion (pila1, expresion[i]);
		}
		else {
			if (expresion[i] == ')' and devolverInfo(pila1) == '('){
			pila1 = eliminarTope(pila1);
			}
			else if (expresion[i] == '}' and devolverInfo(pila1) == '{'){
				pila1 = eliminarTope(pila1);
			}
			else if (expresion[i] == ']' and devolverInfo(pila1) == '['){
				pila1 = eliminarTope(pila1);
			}
		}	
	}
	
	if (esPilaVacia(pila1)){
		cout<<endl<<"La expresion se encuentra equilibrada";
	}
	else if (devolverInfo(pila1) == '(' or devolverInfo(pila1) == '{' or devolverInfo(pila1) == '['){
		cout<<endl<<"La expresion no esta equilibrada"<<endl;
		destruirPila(pila1);
	}
	
	return 0;
	
}
