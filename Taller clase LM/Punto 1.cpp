#include<iostream>
using namespace std;

struct ejemplo{
int info;

ejemplo *sig;
};



int main()
{
	//parte a
	ejemplo *p=new ejemplo;
	ejemplo *q=new ejemplo;
	cout<<"\nPunto A"<<endl;
	p -> info = 5 ;
	q -> info = 6;
	p=q ;
	p -> info = 1;
	cout<< p -> info <<endl;
	cout<< q -> info <<endl;
	
	//parte b
	cout<<"\nPunto B"<<endl;
	p -> info = 3 ;
	q -> info = 2 ;
	p -> info = q -> info;
	q -> info = 0;
	cout<< p -> info<<endl;
	cout<< q -> info<<endl;
	
	//parte c
	cout<<"\nPunto C"<<endl;
	p -> info = 0 ;
	p -> sig = q ;
	q -> info = 5 ;
	q -> sig = NULL;
	p -> sig -> sig = q ;
	q -> info = q -> sig -> info;
	p=q ;
	p -> sig -> info = 2;
	cout<< p -> info<<endl;
	cout<< q -> info;
	return 0;
}
