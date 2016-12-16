#include "zad06main.h"

using namespace std;

//*********************FUNKCJA 'compare' - NA POTRZEBY QSORT**********/
/*int compare(const void * a, const void * b){
if( *(double*)a - *(double*)b>0) return 1;
else if ( *(double*)a - *(double*)b<0) return -1;
else return 0;
}

//*********************************************************************/
/*class SVector:public Vector{
public:
//***************************KONSTRUKTORY ****************************/
/*void Sort(){
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
SVector& operator=(SVector& A){} 
//Jeszcze sortuj przy: >>, setsize(), dodaj(),=
};

//**************KONIEC KLASY SVECTOR*********************************/
int main(){
      int i; 
      Vector v1(10); 
      for (i=0; i<v1.get_size(); i++) v1[i] = i; 
      Vector v2(v1), v3; 
      v3 = v2; 
      v3[2] = 5.5; 
      cout << "v1 = " << v1 << endl << "v2 = " << v2 
     << endl << "v3 = " << v3 << endl; 
      if (v1 == v2) cout << "v1 == v2" << endl; 
      if (v1 != v3) cout << "v1 != v3" << endl; 
      v1.set_size(15); 
      v1.dodaj(34.56);
      cout << "podaj v2 = "; 
      cin >> v2; 
      cout << "v1 = " << v1 << endl << "v2 = " << v2 <<endl; 
return 0;
}

