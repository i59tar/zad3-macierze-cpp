#include "zad04h.h"
int main()
{
    Ciag A("_ciag_A_");
    Ciag B;
    B="_ciag_B_";
    cout<<B<<endl;
    B+=A;
    cout<<"Istnieja: "<<Ciag::Ile()<<" ciagi"<<endl;
    Ciag C;
    cout<<"Podaj ciag C: ";
    cin>>C;
    Ciag D;
    D=A+B+"_cos_";
    cout<<D<<endl;
    cout<<"Istnieja :"<<Ciag::Ile()<<" ciagi."<<endl;
    A+="_dodaje_zwykly_ciag_";
    C+=A;
    cout<<A<<endl<<B<<endl<<C<<endl<<D<<endl;
    cout<<"Dlugosc A: "<<A.Dl()<<endl;
    cout<<"Dlugosc B: "<<B.Dl()<<endl;
    cout<<"Dlugosc C: "<<C.Dl()<<endl;
    cout<<"Dlugosc D: "<<D.Dl()<<endl;
    {
        Ciag ZZ;
        cout<<"Powstal ciag lokalny i istnieja: "<<Ciag::Ile()<<" ciagi."<<endl;
    }
    cout<<"A teraz znowu sa: "<<A.Ile()<<" ciagi."<<endl;
    cout<<" Dziala operator konwersji i funkcja C strlen(A):"<<strlen(A)<<endl;
    cout<<" Dziala operator konwersji i funkcja C strlen(B):"<<strlen(B)<<endl;
    cout<<" Dziala operator konwersji i funkcja C strlen(C):"<<strlen(C)<<endl;
    cout<<" Dziala operator konwersji i funkcja C strlen(D):"<<strlen(D)<<endl;

    return 0;
}