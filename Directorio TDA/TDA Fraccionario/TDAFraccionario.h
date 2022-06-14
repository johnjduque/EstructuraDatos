#ifndef _TDAFraccionario
#define _TDAFraccionario

//Información
struct TDAFraccionario;
typedef struct TDAFraccionario Fraccionario;

//*Operaciones
Fraccionario crearFraccionario();

Fraccionario sumarFraccionario(Fraccionario Frac1, Fraccionario Frac2);

void imprimirFraccionario(Fraccionario fraccionario);

Fraccionario restarFraccionario(Fraccionario Frac1, Fraccionario Frac2);

Fraccionario multiplicarFraccionario(Fraccionario Frac1, Fraccionario Frac2);

Fraccionario dividirFraccionario(Fraccionario Frac1, Fraccionario Frac2);

Fraccionario simplificarFraccionario(TDAFraccionario Frac);

#include  "TDAFraccionario.cpp"
#endif
