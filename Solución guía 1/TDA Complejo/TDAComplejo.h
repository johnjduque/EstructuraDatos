#ifndef _TDAComplejo
#define _TDAComplejo

//Información
struct TDAComplejo;
typedef struct TDAComplejo Complejo;

//*Operaciones
Complejo crearComplejo();

Complejo sumarComplejo(TDAComplejo numero1, TDAComplejo numero2);

void imprimirComplejo(TDAComplejo numero);

Complejo restarComplejo(TDAComplejo numero1, TDAComplejo numero2);

Complejo multiplicarComplejo(TDAComplejo numero1, TDAComplejo numero2);

Complejo dividirComplejoNumerador(TDAComplejo numero1, TDAComplejo numero2);

Complejo dividirComplejoDenominador(TDAComplejo numero1, TDAComplejo numero2);

void imprimirDivisionComplejo(TDAComplejo numero1, TDAComplejo numero2);

#include  "TDAComplejo.cpp"
#endif
