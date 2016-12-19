#include "stdafx6.h"

using namespace std;


//***************** KONSTRUKTORY I DESTRUKTORY************************************** //
//konstruktory: domyslny i jednoargumentowy
Vector::Vector(){vect = new double[1];}
Vector::Vector(int _len=1):len(_len){vect = new double[len];}

//konstruktor dwuargumentowy
Vector::Vector(double *tab, int _len=2):len(_len){
vect = new double[len];
int i=0;
while(i<len && tab[i])vect[i]=tab[i++];

while(i<len) vect[i++]=0;
}

//konstruktor kopiujacy
Vector::Vector(const Vector& A){
len = A.len;
vect = new double[len];
for(int i=0;i<len;i++) vect[i]=A.vect[i];
}

//destruktor
Vector::~Vector(){delete []vect;}

//**************************OPERATORY*********************************//
//operator przypisania
Vector& Vector::operator=(const Vector& B){
if (this!=&B){
	len=B.len;
	double* local_vect = new double[len];
	delete[] vect;	
	vect = local_vect;
	for(int i=0;i<len;i++) vect[i]=B.vect[i];
	}
return *this;
}
//operator [] (write/read)
double& Vector::operator[](size_t index){return vect[index];}
const double& Vector::operator[](size_t index) const{return vect[index];}
//***************METODY KLASY******************************//

int Vector::get_size(){return len;}

//set_size - ustawia dlugosc tablicy
Vector& Vector::set_size(int a){
		double* n_vec=new double[a];
		for(int i=0;i<a;i++)n_vec[i]=i<len?vect[i]:0;
		len=a;
		delete[] vect;
		vect = n_vec;
		return *this;
}	
//dodaj - dodaje liczbe na ostatniej pozycji wektora
Vector& Vector::dodaj(double a){
	len++;
	double* n_vec = new double[len];
	for (int i=0;i<len;i++) n_vec[i]=(i<len-1?vect[i]:a);
	delete[] vect;
	vect = n_vec;
	return *this;
}


//*************FUNKCJE ZAPRZYJAZNIONE - DEFINICJE***********************//
std::istream& operator>>(std::istream& is, Vector& A){
	int _len;	
	is>>_len;
	if(_len>A.len) A.set_size(A.len);
	for(int i=0;i<_len;i++) if(_len<A.len)is>>A[i];
	return is;
}
std::ostream& operator<<(std::ostream& os, Vector& A){
	os<<'['<<A.len<<':';
	for(int i=0;i<A.len;i++){
		os<<' ';
		cout.width(4);
		os<<A[i];
	}
	os<<']';
	return os;
}
bool operator==(Vector A, Vector B){
if(A.len!=B.len) return false;
else for(int i=0;i<A.len;i++) if(A[i]!=B[i])return false;
return true;
}
bool operator!=(Vector A, Vector B){
return !(A==B);
}
//*********************************************************************//

