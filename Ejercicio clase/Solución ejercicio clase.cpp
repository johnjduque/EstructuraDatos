#include<iostream>

using namespace std;



int main(){

    char *p;

char *q;

p=new (char);

q=new (char);

*p='a';

*q='b';

    cout<<"P: "<<*p<<" Direccion: "<<p<<endl;

    cout<<"Q: "<<*q<<" Direccion: "<<q<<endl;

    delete(p);

    delete(q);

    return 0;

}
