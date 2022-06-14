#include "TDAColaJohn.cpp"

int devolverTiempoAtencion(TDAColaJohn *paciente){
	
	int tiempoduq;
	
	if (paciente->inicioduq->infoduq.edadJairo < 15){
		tiempoduq = 20;
	}
	else if (paciente->inicioduq->infoduq.edadJairo < 45){
		tiempoduq = 25;
	}
	else{
		tiempoduq = 30;
	}
	return tiempoduq;
}

bool esMujer(int paciente){
	if(paciente == 1)
		return true;
	else
		return false;
}

int main(){
	
	TDAColaJohn *doctorMujeresJJD, *doctorHombresJJD;
	doctorHombresJJD = NULL;
	doctorMujeresJJD = NULL;
	
	int tiempoDadoduq = 0;
	cout<<"Ingrese el tiempo que quiere simular las colas"<<endl;
	cin>>tiempoDadoduq;
	
	int contadorTiempoduq = 1;
	int colaHombres = 0;
	int colaMujeres = 0;		
	int controlAtencionH = 1;
	int controlAtencionM = 1;
	int pacienteMAtendido = 0;
	int pacienteHAtendido = 0;
	int pacienteIng = 2;
	int generoIng = 0;
	
	while(contadorTiempoduq <= tiempoDadoduq){
		
		cout<<endl<<"Desea ingresar un paciente: 1 si, 2 no"<<endl;
		cin>>pacienteIng;
		if(pacienteIng == 1){
			cout<<"Es: 1 mujer, 2 hombre"<<endl;
			cin>>generoIng;		
		}

		if(esMujer(generoIng) && pacienteIng == 1){
			doctorMujeresJJD = insertarColaZuluaga(doctorMujeresJJD);
			cout<<"Pacientes en su cola: "<<colaMujeres<<endl;
			cout<<"Se le asigno la doctora Martha"<<endl;
			colaMujeres ++;
		}
		else{
			if(!esMujer(generoIng) && pacienteIng == 1){
				doctorHombresJJD = insertarColaZuluaga(doctorHombresJJD);
				cout<<"Pacientes en su cola: "<<colaHombres<<endl;
				cout<<"Se le asigno el doctor Ivan"<<endl;
				colaHombres ++;
			}
		}
		
		cout<<endl<<"Reporte minuto: "<<contadorTiempoduq;
		cout<<endl<<"Por parte de la doctora Martha se atiende a: ";
		if(!esColaVaciaDuque(doctorMujeresJJD)){
			mostrarNodoZuluaga(doctorMujeresJJD);
			cout<<"Faltan: "<<devolverTiempoAtencion(doctorMujeresJJD) - controlAtencionM<<" minutos para terminar"<<endl;			
		}
		else if(esColaVaciaDuque(doctorMujeresJJD)){
			cout<<"No hay pacientes en cola";			
		}
		
		cout<<endl<<"Por parte del doctor Ivan se atiende a: ";
		if(!esColaVaciaDuque(doctorHombresJJD)){
			mostrarNodoZuluaga(doctorHombresJJD);
			cout<<"Faltan: "<<devolverTiempoAtencion(doctorHombresJJD) - controlAtencionH<<" minutos para terminar"<<endl;				
		}
		else if(esColaVaciaDuque(doctorHombresJJD)){
			cout<<"No hay pacientes en cola"<<endl;			
		}

		
		if(!esColaVaciaDuque(doctorMujeresJJD) && devolverTiempoAtencion(doctorMujeresJJD) > controlAtencionM){
			controlAtencionM = controlAtencionM + 1;
		}
		else if(!esColaVaciaDuque(doctorMujeresJJD)){
			doctorMujeresJJD = eliminarColaZuluaga(doctorMujeresJJD);
			controlAtencionM = 1;
			pacienteMAtendido = pacienteMAtendido + 1;
			colaMujeres = colaMujeres - 1;				
		}
		else{
			cout<<"No hay pacientes mujeres en el momento"<<endl;
		}
		
		if(!esColaVaciaDuque(doctorHombresJJD) && devolverTiempoAtencion(doctorHombresJJD) > controlAtencionH){
			controlAtencionH = controlAtencionH + 1;
		}
		else if(!esColaVaciaDuque(doctorHombresJJD)){
			doctorHombresJJD = eliminarColaZuluaga(doctorHombresJJD);
			controlAtencionH = 1;
			pacienteHAtendido = pacienteHAtendido + 1;
			colaHombres = colaHombres - 1;				
		}
		else{
			cout<<"No hay pacientes hombres en el momento"<<endl;
		}
		contadorTiempoduq = contadorTiempoduq + 1;			
	}
	
	cout<<endl<<"Por parte de la doctora Martha se terminaron de atender: "<<pacienteMAtendido<<" pacientes"<<endl;
	cout<<"Por parte del doctor Ivan se terminaron de atender: "<<pacienteHAtendido<<" pacientes"<<endl;
	cout<<"Hay pendientes por terminar de atender: "<<colaHombres + colaMujeres<<" pacientes:"<<colaMujeres<<" mujeres y "<<colaHombres<<" hombres"<<endl;		
	
	return 0;
}
