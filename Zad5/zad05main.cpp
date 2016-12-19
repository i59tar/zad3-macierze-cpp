#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <time.h>

using namespace std; 

class Complex{
public:
double real, imag;

Complex( double _real=0, double _imag=0):real(_real), imag(_imag){} 
double fun1(){return this->real;}
double fun2(){return this->imag;}
double fun3(){return this->real*this->real + this->imag*this->imag;}
double fun4(){return sqrt(this->fun3());}
};

class TabComplex{
public:
Complex tab_c[10];
TabComplex(){
srand(time(NULL));
for (int i=0;i<10;i++){
	this->tab_c[i].real=(rand()%1000)/10.;
	this->tab_c[i].imag=(rand()%1000)/10.;
	}
}
friend std::ostream & operator<<(std::ostream &s, TabComplex&);
};

//nie uzywam tablicy wskaznikow do funkcji, za duzo problemow z tym. Tak poza tym, dziala. generuje randomowe liczby urojone z przedzialu <0.0:100.0><0.0:100.0>
typedef double (Complex::*funtab)();
funtab tab_wsk_fun[4]={&Complex::fun1,&Complex::fun2,&Complex::fun3,&Complex::fun4};


std::ostream & operator<<(std::ostream &s, TabComplex& T){
for(int i=0;i<10;i++){
s<<T.tab_c[i].fun1()<<endl<<T.tab_c[i].fun2()<<endl<<T.tab_c[i].fun3()<<endl<<T.tab_c[i].fun4()<<endl;
}
return s;
};


int main(){
TabComplex T;
cout<<T;
return 0;
}

