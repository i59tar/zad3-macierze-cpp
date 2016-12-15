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
while(i<len && tab[i])vect[i]=tab[i++];

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
friend bool operator==(Vector A, Vector B);
friend bool operator!=(Vector A, Vector B);
//****************************************************//
protected:
double *vect;
int len;
};

//*************FUNKCJE ZAPRZYJAZNIONE - DEFINICJE***********************//
std::istream& operator>>(std::istream& is, Vector& A){
	int _len;	
	is>>_len;
	if(_len>A.len) A.set_size(A.len);
	for(int i=0;i<_len;i++)is>>A[i];
	return is;
}
std::ostream& operator<<(std::ostream& os, Vector& A){
	os<<A.len<<':';
	for(int i=0;i<A.len;i++){
		os<<' ';
		cout.width(4);
		os<<A[i];
	}
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


//*********************FUNKCJA 'compare' - NA POTRZEBY QSORT**********//
int compare(const void * a, const void * b){
if( *(double*)a - *(double*)b>0) return 1;
else if ( *(double*)a - *(double*)b<0) return -1;
else return 0;
}

//*********************************************************************//
class SVector:public Vector{
public:
//***************************KONSTRUKTORY ****************************//
void Sort(){
	qsort((void*)vect,len,sizeof(double),compare);
}
SVector(int _len=1):Vector(_len){
Sort();
}
SVector(double *tab, int _len=2):Vector(tab,_len){
Sort();
}
SVector(Vector& A):Vector(A){
Sort();
}
SVector(SVector& A){
len = A.len;
vect = new double[len];
for(int i=0;i<len;i++) vect[i]=A.vect[i];
Sort();
}
//
};

int main(){
double tab[4]={2,3.3};
Vector A(tab,8);

A[4]=9.9;
Vector B=A;
cin>>B;
SVector C(B);
cout<<A<<endl<<B<<endl<<C<<endl;
return 0;
}

