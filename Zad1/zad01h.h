#ifndef LIBRARIES
#define LIBRARIES
#include <cstdlib>
#include <iostream>

using namespace std;

class Klasa
{
    int stalo_prz;
    float zmienno_prz;
    char znakowy;
    static const float My_PI;

    public:
    Klasa();
    Klasa(int, float, char);
    Klasa(Klasa const&);
    ~Klasa();

    int getInt();
    float getFloat();
    char getChar();
    float getPi() const;

    void setInt(int);
    void setFloat(float);
    void setChar(char);

    void WriteAll();

};


void WriteOut(Klasa);
Klasa KeyboardInput();
#endif