#include "zad06main.h"

using namespace std;

//*********************FUNKCJA 'compare' - NA POTRZEBY QSORT**********/
int compare(const void * a, const void * b){
if( *(double*)a - *(double*)b>0) return 1;
else if ( *(double*)a - *(double*)b<0) return -1;
else return 0;
}
/***************************KONSTRUKTORY ****************************/
void SVector::Sort(){
	qsort((void*)vect,len,sizeof(double),compare);
}
SVector::SVector(int _len=1):Vector(_len){
Sort();
}
SVector::SVector(double *tab, int _len=2):Vector(tab,_len){
Sort();
}
SVector::SVector(const Vector& A):Vector(A){
Sort();
}
//Jeszcze sortuj przy: >>, setsize(), dodaj(),=


