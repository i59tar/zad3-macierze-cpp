#include "zad2-lib.h"
//szerokosc komorki. na potrzeby cout
using namespace std;

int main(int argc, char *argv[]){
Matrix A=Rand(6,6);

A.mat[2][3]=7;
cout<<A<<endl;
Matrix B(A);
cout<<(A!=B)<<endl;

Matrix D=B*B;
cout<<D<<endl;
Matrix E=D+B;
cout<<E<<endl;
cout<<"Macierz B - "<<endl<<B<<endl;
cout<<"Wyznacznik macierzy B = "<<Det(B)<<endl;
cout<<"Wartosc D[4][5] = "<<D[4][5]<<endl;
cout<<"Wymiary macierzy E: "<<getSize(E)<<endl;
cout<<"Macierz odwrotna do E:"<<endl<<Inv(E)<<endl;
cout<<"Najwyzsza wartosc absolutna z macierzy E wynosi:"<<MaxAbs(E)<<endl;
return 0;
}
