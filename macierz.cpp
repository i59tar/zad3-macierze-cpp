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
mat = new double*[width];
for(int i=0;i<height;i++) mat[i]=new double[height];
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
for(int i=0;i<width;i++) delete []mat[i];
delete []mat;
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


int main(int argc, char *argv[]){
Matrix A(6,6);
A.mat[2][3]=7;
Matrix B(A);
Matrix C = B*3.14;
cout<<C;

return 0;
}
