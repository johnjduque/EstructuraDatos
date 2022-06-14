#include "TDAExpresion.cpp"

	bool esUnOperador(char operador){
		
		if(operador == '^' or operador == '*' or operador == '/' or operador == '(' or operador == ')' or operador == '+' or operador == '-'){
			return true;
		}
		else{
			return false;	
		}		
	}
	
	int prioridadExpresion(char operador){
		
		int prioridad;
		
		if(operador == '^'){
			prioridad = 4;	
		}		
		else if(operador == '*' or operador == '/'){
			prioridad = 2;	
		}		
		else if(operador == '+' or operador == '-'){
			prioridad = 1;	
		}		
		else if(operador == '('){
			prioridad = 5;	
		}
					
		return prioridad;		
	}
	
	int prioridadPila(char operador){
		
		int prioridad;
		
		if(operador == '^'){
			prioridad = 3;	
		}		
		else if(operador == '*' or operador == '/'){
			prioridad = 2;	
		}		
		else if(operador == '+' or operador == '-'){
			prioridad = 1;	
		}		
		else if(operador == '('){
			prioridad = 0;	
		}		
			
		return prioridad;		
	}

int main(){
	
	TDAPila *pila1;
	string expresionInfija;		
	string expresionPostfija;
	
	pila1 = NULL;
	cout<<"ingrese una expresion "<<endl;
	cin>>expresionInfija;
	
	int posicionPostfija = 0;
	
//	cout<<expresionInfija<<" "<<expresionPostfija<<endl;
	
	for(int i=0; i < expresionInfija.length(); i++){
		cout<<"hola";
		
		if(!(esUnOperador(expresionInfija[i]))){
			expresionPostfija.append(expresionInfija,i,1);
			posicionPostfija = posicionPostfija + 1;
			cout<<"1  -  ex "<<expresionPostfija;
		}
		else{
			if(esPilaVacia(pila1) and !(expresionInfija[i] == ')')){
				pila1= insertarPilaInformacion(pila1, expresionInfija[i]);
				cout<<"2";
			}
			else{
				if(expresionInfija[i] == ')'){
					while(!devolverInfo(pila1) == '('){
						expresionPostfija[posicionPostfija] = devolverInfo(pila1);
						pila1= eliminarTope(pila1);
						posicionPostfija = posicionPostfija + 1;
					}
					eliminarTope(pila1);
					cout<<"3";
				}
				if(prioridadExpresion(expresionInfija[i] > prioridadPila(devolverInfo(pila1)))){
					while (!esPilaVacia(pila1) and (prioridadPila(expresionInfija[i]) < prioridadExpresion(devolverInfo(pila1))) and (!expresionInfija[i] == '(')){
						expresionPostfija[posicionPostfija] = devolverInfo(pila1);
						eliminarTope(pila1);
						posicionPostfija = posicionPostfija + 1;
					}
					pila1 = insertarPilaInformacion(pila1, expresionInfija[i]);
					cout<<"4";
				}
				else if(prioridadExpresion(expresionInfija[i] < prioridadPila(devolverInfo(pila1)))){
					expresionPostfija[posicionPostfija] = devolverInfo(pila1);
					pila1 = insertarPilaInformacion(pila1, expresionInfija[i]);
					posicionPostfija = posicionPostfija + 1;
					cout<<"5";
				}
			}					
		}		
	}
	cout<<"sale for";
	cout<<expresionPostfija;
	if(esPilaVacia(pila1)){
		cout<<endl<<"La expresion postfija es: "<<expresionPostfija;
		cout<<"if pila vacia";
	}
	else{
		while(!(esPilaVacia(pila1))){
		expresionPostfija.append(1u,devolverInfo(pila1));
		pila1 = eliminarTope(pila1);
		posicionPostfija = posicionPostfija + 1;
		}
		
		cout<<endl<<"La espresión postfija es: "<<expresionPostfija;
		cout<<"else pila no vacia";
	}

  return 0;
  
}
