#ifndef _FinalEDD
#define FinalEDD

struct Estudiantejz;

struct Programajz;

Estudiantejz *crearEstudiantejz();

Programajz *crearProgramajz();

Programajz *insertarProgramajz(Programajz *listajz);

Estudiantejz *buscarEstudiantejz(Estudiantejz *iniciojz, char inicialNombre);

Estudiantejz *insertarEstudianteOrdenadojz(Estudiantejz *listajz);

void mostrarInfoEstjz(Estudiantejz *Nodojz);

void mostrarInfoProgjz(Programajz *Nodojz);

void mostrarInformacionjz(Programajz *iniciojz);

#include  "FinalEDD.cpp"
#endif
