#include "zad01h.h"
const float Klasa::My_PI=3.14;

Klasa::Klasa()
{
    cout<<"Dziala konstruktor domyslny."<<endl;
}
Klasa::Klasa(int stalo, float zmienno, char znak):stalo_prz(stalo),zmienno_prz(zmienno),znakowy(znak)
{
    cout<<"Dziala konstruktor argumentowy."<<endl;
}
Klasa::Klasa(Klasa const& Inna)
{
    cout<<"Dziala konstruktor kopiujacy."<<endl;
    stalo_prz=Inna.stalo_prz;
    zmienno_prz=Inna.zmienno_prz;
    znakowy=Inna.znakowy;
}
Klasa::~Klasa()
{
    cout<<"Dziala destruktor."<<endl;
}
int Klasa::getInt()
{
    return stalo_prz;
}
float Klasa::getFloat()
{
    return zmienno_prz;
}
char Klasa::getChar()
{
    return znakowy;
}
float Klasa::getPi() const
{
    return My_PI;
}
void Klasa::setInt(int value)
{
    stalo_prz=value;
}
void Klasa::setFloat(float value)
{
    zmienno_prz=value;
}
void Klasa::setChar(char value)
{
    znakowy=value;
}
void Klasa::WriteAll()
{
    cout<<"Liczba staloprzecinkowa = "<<stalo_prz<<endl;
    cout<<"Liczba zmiennoprzecinkowa = "<<zmienno_prz<<endl;
    cout<<"Zmienna znakowa = "<<znakowy<<endl;
    cout<<"Liczba PI = "<<My_PI<<endl;
}

void WriteOut(Klasa This)
{
    cout<<"Poczatek funkcji WriteOut(Klasa):"<<endl;
    cout<<This.getInt()<<" "<<This.getFloat()<<" "<<This.getChar()<<" "<<This.getPi()<<endl;
    cout<<"Koniec funkcji WriteOut(Klasa)"<<endl;
}
Klasa KeyboardInput()
{
    cout<<"Poczatek funkcji KeyboardInput()"<<endl;
    cout<<"Podaj zmienne: Int, Float, Char"<<endl;
    int val1;
    cin>>val1;
    float val2;
    cin>>val2;
    char val3;
    cin>>val3;
    Klasa New(val1,val2,val3);
    cout<<"Koniec funkcji KeyboardInput()"<<endl;
    return New;
}