#include<iostream>
using namespace std;

struct ejemplo{
int numero;
ejemplo *sig;
};
int main()
{
ejemplo *p=new ejemplo;
ejemplo *q=new ejemplo;
ejemplo *r=new ejemplo;
p->sig=NULL;
p->numero=3;
q->numero=8;
r->numero=3;
p->sig=q;
q->sig=r;



cout<<"P numero: "<<p->numero<<" P sig "<<p->sig->numero<<endl;
cout<<"Q numero: "<<q->numero<<" Q sig "<<q->sig->numero<<endl;
cout<<"R numero: "<<r->numero<<endl;

cout<<&p<<endl<<&q<<endl<<&r;

delete(p);
delete(q);
delete(r);



return 0;
}
