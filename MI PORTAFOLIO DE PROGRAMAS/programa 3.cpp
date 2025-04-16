#include <iostream>
using namespace std;
int area (int radio){
	int pi= 3.14;
	int area=pi*(radio*radio);
	return area;
}
int main (){ 
int p;
cout<<"ingrese el radio";
cin>>p;
int respuesta = area (p);
cout<<respuesta ;
return 0;
}