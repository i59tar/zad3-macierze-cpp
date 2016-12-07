#include <iostream>
#include <stdlib.h>

#define CELL_WIDTH 5
//szerokosc komorki. na potrzeby cout
using namespace std;

class Matrix{
public:
int width;
int height;

double **mat;

//konstruktor domyślny i wymiarowy
Matrix(int _width=2, int _height=2):width(_width), height(_height){
mat = new double*[height];
for(int i=0;i<height;i++) mat[i]=new double[width];
}

//konstruktor kopiujący
Matrix(const Matrix& A){
this->width=A.width;
this->height=A.height;
mat = new double*[width];
for(int i=0;i<height;i++){
	mat[i]=new double[height];
	for(int j=0;j<width;j++){
	mat[i][j]=A.mat[i][j];	
		}
	}
}

//destrkutor
~Matrix(){
for(int i=0;i<height;i++) delete []mat[i];
delete []mat;
}

//przeładowany operator *= dla macierzy i liczby
Matrix operator*=(double a){
for(int i=0;i<this->height;i++){
	for(int j=0;j<this->width;j++) this->mat[i][j]*=a;
	}
return *this;
}

//przeladowany operator *= dla dwoch macierzy
Matrix operator*=( Matrix B){
if(this->width==B.height){
	Matrix W(this->height, B.width);
	for(int i=0;i<W.height;i++){
		for(int j=0;j<W.width;j++){
			for(int k=0;k<this->height;k++) W.mat[i][j]+=this->mat[i][k]*B.mat[k][j];
			}
		}
		return W;
	}
	else cout<<"Operacja zakończona niepowodzeniem"<<endl;
}

};

//przeladowany operator * dla macierzy i liczby
Matrix operator*(Matrix A, double a){
for(int i=0;i<A.height;i++){
	for(int j=0;j<A.width;j++) A.mat[i][j]*=a;
	}
return A;
};

//przeładowany operator * dla dwoch macierzy
Matrix operator*(Matrix A, Matrix B){
if(A.width==B.height){
	Matrix W(A.height, B.width);
	for(int i=0;i<W.height;i++){
		for(int j=0;j<W.width;j++){
			for(int k=0;k<A.height;k++) W.mat[i][j]+=A.mat[i][k]*B.mat[k][j];
			}
		}
return W;
}
else cout<<"Operacja zakończona niepowodzeniem"<<endl;
return A;
};


//przeładowany operator <<
std::ostream & operator<<(std::ostream &s, Matrix& A){
for(int i=0;i<A.height;i++){
	s<<"|";
	for(int j=0;j<A.width;j++){
		s<<"_";
		cout.width(CELL_WIDTH);
		cout.fill('_');
		s<<A.mat[i][j]<<"_|";
		}
	s<<endl;
	}
return s;
}

//przeładowany operator ==
bool operator==(Matrix A, Matrix B){
	if((A.width==B.width)&&(A.height==B.height)){
		for (int i=0;i<A.height;i++){
			for(int j=0;j<A.width;j++) if (A.mat[i][j]!=B.mat[i][j]) return false;
		}
	return true;
	}
	return false;
	 
}

//przeladowany operator !=
bool operator!=(Matrix A, Matrix B){
	return !(A==B);
}

//przeladowany operator + (Matrix, Matrix)
Matrix operator+(Matrix A, Matrix B){
if((A.width==B.width)&&(A.height==B.height)){
		for (int i=0;i<A.height;i++){
			for(int j=0;j<A.width;j++) A.mat[i][j]+=B.mat[i][j];
		}
	}
else cout<<"Operacja niemozliwa. Powod - niezgodnosc wymiarow"<<endl;
return A;
}

int main(int argc, char *argv[]){
Matrix A(6,6);

A.mat[2][3]=7;
cout<<A<<endl;
Matrix B(A);
cout<<(A!=B)<<endl;
Matrix C = B*3.14;
C*=2;
cout<<C<<endl;
Matrix D=C+B;
cout<<D<<endl;
return 0;
}
