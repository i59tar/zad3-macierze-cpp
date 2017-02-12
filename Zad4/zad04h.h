#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Ciag
{
    char *content;
    int length;
    static int count;
    public:

    Ciag();
    Ciag(const char *);
    Ciag(Ciag const&);
    ~Ciag();

    int Dl();
    Ciag& operator=(Ciag);
    Ciag& operator=(const char*);
    
    static int Ile();

    Ciag operator+(Ciag);
    Ciag operator+(const char*);
    Ciag operator+=(Ciag);
    Ciag operator+=(const char*);
    
    operator char* const();

    friend std::istream& operator>>(istream&, Ciag&);
    friend std::ostream& operator<<(ostream&, const Ciag&);
};