#include<iostream>
using namespace std;

struct expresion{
	char info;
	expresion *apunt1, *apunt2; 
};

int main (){	
	expresion *estructura;
	estructura = new (expresion);
	estructura->info= '*';
	estructura->apunt1=new (expresion);
	estructura->apunt2=new (expresion);
	
	estructura->apunt1->info='+';
	estructura->apunt1->apunt1=new (expresion);
	estructura->apunt1->apunt1->info= 'j';
	estructura->apunt1->apunt1->apunt1= NULL;
	estructura->apunt1->apunt1->apunt2= NULL;
	estructura->apunt1->apunt2=new (expresion);
	estructura->apunt1->apunt2->info= 'j';
	estructura->apunt1->apunt2->apunt1= NULL;
	estructura->apunt1->apunt2->apunt2= NULL;
	
	estructura->apunt2->info='-';
	estructura->apunt1->apunt1=new (expresion);
	estructura->apunt1->apunt1->info= 'd';
	estructura->apunt1->apunt1->apunt1= NULL;
	estructura->apunt1->apunt1->apunt2= NULL;
	estructura->apunt1->apunt2=new (expresion);
	estructura->apunt1->apunt2->info= 'z';
	estructura->apunt1->apunt2->apunt1= NULL;
	estructura->apunt1->apunt2->apunt2= NULL;	
	
	return 0;
}
