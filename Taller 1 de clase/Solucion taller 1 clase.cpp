#include<iostream>

using namespace std;

struct ejemplo {
	int numero;
	ejemplo *sig;
};

int main(){
	
	ejemplo *p, *q, *r;
	
	p = new (ejemplo);
	q = new (ejemplo);
	r = new (ejemplo);
	
	p->numero=3;
	q->numero=8;
	r->numero=3;
	
	p->sig=q->numero;
	q->sig=r->numero;
	r->sig=NULL;
	
	cout<<"Pnum: "<<*p.numero<<"Psig: "<<*p.sig<<" Direccion: "<<p<<endl;

    cout<<"Qnum: "<<*q.numero<<"Qsig: "<<*q.sig<<" Direccion: "<<p<<endl;
    
    cout<<"Rnum: "<<*r.numero<<"Psig: "<<*r.sig<<" Direccion: "<<p<<endl;

    delete(p);

    delete(q);
	
	delete(r);
	
	return 0;
}
