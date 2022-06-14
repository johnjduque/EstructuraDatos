#include<iostream>
using namespace std;

int main() {
	
 	int index,*pt1,*pt2;
 	index = 39;
	pt1 = &index;
	pt2 = pt1;
 	printf("El valor es  %d %d %d\n",index,*pt1,*pt2);
 	*pt1 = 13;
	printf("El valor es %d %d %d\n",index,*pt1,*pt2);
	return 0;
}

