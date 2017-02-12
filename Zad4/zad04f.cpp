#include "zad04h.h"
using namespace std;
int Ciag::count=0;

Ciag::Ciag()
{
    length=1;
    content=new char[length];
    content[0]='\0';
    count++;
}
Ciag::Ciag(const char *value)
{
    int i;
    for(i=0;value[i]!='\0';i++);
    length=i;
    content=new char[length];
    for(i=0;(content[i]=value[i]);i++);
    count++;
}
Ciag::Ciag(Ciag const &Other)
{
    length=Other.length;
    content=new char[length];
    for(int i=0;(content[i]=Other.content[i]);i++);
    count++;
}
Ciag::~Ciag()
{
    delete []content;
    count--;
}
int Ciag::Dl()
{
    return length;
}
Ciag& Ciag::operator=(Ciag Other)
{
    if(length!=Other.length)
    {
        delete[] content;
        length=Other.length;
        content= new char[length];
    }
    for(int i=0;(content[i]=Other.content[i]);i++);
    return (*this);
}
Ciag& Ciag::operator=(const char* Other)
{
    Ciag New(Other);
    (*this)=New;
    return *this;
}
Ciag Ciag::operator+(Ciag Other)
{
    Ciag Backup((*this));
    delete[] Backup.content;
    Backup.length+=Other.length;
    Backup.content=new char[Backup.length];
    int i;
    for(i=0;(Backup.content[i]=content[i]);i++);
    for(i=length;(Backup.content[i]=Other.content[i-length]);i++);
    return Backup;
}
Ciag Ciag::operator+(const char* Other)
{
    Ciag New(Other);
    return (*this)+New;
}
Ciag Ciag::operator+=(Ciag Other)
{
    Ciag New(*this);
    *this=New+Other;
    return (*this);
}
Ciag Ciag::operator+=(const char* Other)
{
    Ciag New(*this);
    Ciag Another(Other);
    *this=New+Another;
    return (*this);
}
int Ciag::Ile()
{
    return count;
}
std::istream& operator>>(istream& Source, Ciag& Target)
{
char buffer[512];
Source>>buffer;
int i;
for(i=0;buffer[i];i++);
delete []Target.content;
Target.length=i;
Target.content=new char[Target.length];
for(i=0;(Target.content[i]=buffer[i]);i++);
return Source;
}
std::ostream& operator<<(ostream &Target, const Ciag& Source)
{
Target<<Source.content;
return Target;
}
Ciag::operator char* const()
{
    return content;
}
