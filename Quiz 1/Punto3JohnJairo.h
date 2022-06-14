//John Jairo Duque Zuluaga - hora inicio: 20:00

#ifndef _TDADuqPolinomio
#define _TDADuqPolinomio

//Información
struct TDADuqPolinomio;
typedef struct TDADuqPolinomio duqPolinomio;

//*Operaciones
duqPolinomio duqCrearPolinomio();

duqPolinomio duqSumarPolinomio(TDADuqPolinomio duqPol1, TDADuqPolinomio duqPol2);

void duqImprimirPolinomio(TDADuqPolinomio duqPolinomio);

#include  "Punto3JohnJairo.cpp"
#endif
