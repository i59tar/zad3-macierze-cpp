#include <iostream>
#include <stdlib.h>

using namespace std;

class Vector{
public:


//***************** KONSTRUKTORY I DESTRUKTORY************************************** //
//konstruktory: domyslny i jednoargumentowy
Vector(int _len=1):len(_len){vect = new double[len];}

//konstruktor dwuargumentowy
Vector(double *tab, int _len=2):len(_len){
vect = new double[len];
int i=0;
while(i<len && tab[i]){
	vect[i]=tab[i++];
	i++;
}
while(i<len) vect[i++]=0;
}

//konstruktor kopiujacy
Vector(Vector& A){
len = A.len;
vect = new double[len];
for(int i=0;i<len;i++) vect[i]=A.vect[i];
}

//destruktor
~Vector(){delete []vect;}

//**************************OPERATORY*********************************//
//operator przypisania
Vector& operator=(const Vector& B){
if (this!=&B){
	delete[] vect;
	len=B.len;
	vect = new double[len];
	for(int i=0;i<len;i++) vect[i]=B.vect[i];
	}
return *this;
}
//operator [] (write/read)
double& operator[](size_t index){return vect[index];}
const double& operator[](size_t index) const{return vect[index];}
//***************METODY KLASY******************************//

int get_size(){return len;}

//set_size - ustawia dlugosc tablicy
Vector& set_size(int a){
		double* n_vec=new double[a];
		for(int i=0;i<a;i++)n_vec[i]=i<len?vect[i]:0;
		len=a;
		delete[] vect;
		vect = n_vec;
		return *this;
}	
//dodaj - dodaje liczbe na ostatniej pozycji wektora
Vector& dodaj(double a){
	double* n_vec = new double(len+1);
	for (int i=0;i<len+1;i++) n_vec[i]=i<len?vect[i]:a;
	delete[] vect;
	vect = n_vec;
	return *this;
}
//**********************FUNKCJE ZAPRZYJAZNIONE*******************//
friend std::istream& operator>>(std::istream& is, Vector& A);
friend std::ostream& operator<<(std::ostream& os, Vector& A);
//****************************************************//
private:
double *vect;
int len;
};




int main(){
double tab[4]={2,3.3};
Vector A(tab,8);

A[4]=9.9;
Vector B=A;

cout<<B[0]<<' '<<A[1]<<' '<<B[1]<<' '<<B[2]<<' '<<B[3]<<' '<<B[4]<<' '<<B[5]<<' '<<B[6]<<' '<<B[7]<<' '<<endl;
return 0;
}

std::istream& operator>>(std::istream& is, Vector& A){

};
std::ostream& operator<<(std::ostream& os, Vector& A){

};
