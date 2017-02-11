#include "zad2-lib.h"

using namespace std;
/**
* Operator dostepu [][] I klasa pomocnicza Proxy
**/
Matrix::Proxy::Proxy(double* _rows) : _rows(_rows) { }
double Matrix::Proxy::operator[](int index)
{
            return _rows[index];
}
Matrix::Proxy Matrix::operator[](int index)
{
        return Proxy(mat[index]);
}
/**
*		KONSTRUKTORY: domyslny, dwuargumentowy (int,int)
**/
Matrix::Matrix()
{
    width=2;
    height=2;
	int i,j;
    mat = new double*[height];
    for(int i=0;i<height;i++)
	{
		mat[i]=new double[width];
		for(j=0;j<width;j++)
		{
			mat[i][j]=0;
		}
	} 
}
Matrix::Matrix(int _width, int _height): width(_width), height(_height)
{
    mat = new double*[height];
	int i,j;
    for(i=0;i<height;i++)
	{
		mat[i]=new double[width];
		for(j=0;j<width;j++)
		{
			mat[i][j]=0;
		}
	} 
}
/**
*Konstruktor kopiujący
**/
Matrix::Matrix(const Matrix& Other)
{
    this->width=Other.width;
    this->height=Other.height;
    mat = new double*[width];
    for(int i=0;i<height;i++)
    {
	    mat[i]=new double[height];
	    for(int j=0;j<width;j++)
        {
	        mat[i][j]=Other.mat[i][j];	
		}
	}
}
/**
* Destruktor
**/
Matrix::~Matrix()
{
    for(int i=0;i<height;i++) delete []mat[i];
    delete []mat;
}
/**
*Operator przypisania
**/
Matrix& Matrix::operator=(const Matrix &Other)
{
	Matrix New(Other);
	(*this)=New;
	return (*this);
}
/**
* Operatory: +,-,+=,-= (dla macierzy), *,*=(Macierz, Skalar),<<,>>,==,!=
**/
Matrix Matrix::operator+(Matrix Other)
{
	Matrix Backup((*this));
	if((Backup.width==Other.width)&&(Backup.height==Other.height))
	{
		for (int i=0;i<this->height;i++)
		{
			for(int j=0;j<this->width;j++) Backup.mat[i][j]+=Other[i][j];
		}
	}
else cout<<"Operacja niemozliwa. Powod - niezgodnosc wymiarow"<<endl;
return Backup;
}
Matrix Matrix::operator+=(Matrix Other)
{
	return (*this)+Other;
}
Matrix Matrix::operator-(Matrix Other)
{
	Matrix Backup((*this));
	if((Backup.width==Other.width)&&(Backup.height==Other.height))
	{
		for (int i=0;i<Backup.height;i++)
		{
			for(int j=0;j<Backup.width;j++) Backup.mat[i][j]-=Other[i][j];
		}
	}
	else cout<<"Operacja niemozliwa. Powod - niezgodnosc wymiarow"<<endl;
	return Backup;
}
Matrix Matrix::operator-=(Matrix Other)
{
	return (*this)-Other;
}
Matrix Matrix::operator*(double Scalar)
{
	Matrix Backup(*this);
    for(int i=0;i<Backup.height;i++)
    {
	    for(int j=0;j<Backup.width;j++) Backup.mat[i][j]*=Scalar;
	}
    return Backup;
}
Matrix Matrix::operator*(Matrix Other)
{
    if(this->width==Other.height)
    {
	    Matrix W(this->height, Other.width);
	    for(int i=0;i<W.height;i++)
        {
		    for(int j=0;j<W.width;j++)
            {
			    for(int k=0;k<this->height;k++) W.mat[i][j]+=this->mat[i][k]*Other[k][j];
			}
		}
		return W;
	}
	else cout<<"Operacja zakończona niepowodzeniem"<<endl;
	return *this;
}
Matrix Matrix::operator*=(double Scalar)
{
	return (*this)*Scalar;
}
Matrix Matrix::operator*=(Matrix Other)
{
	return (*this)*Other;
}
std::istream & operator>>(std::istream &Source, Matrix& Target)
{
	int _width, _height;
	do
	{
	Source>>_width;
	Source>>_height;
	if(_width<=0&&_height<=0) cout<<"Nieprawidlowe wartosci. Musza byc dodatnie."<<endl;
	}while(_width>0&&_height>0);
	Matrix New(_width,_height);
	Target=New;
	
	int i,j;
	for(i=0;i<New.height;i++)
	{
		for(j=0;j<New.width;j++)
		{
			Source>>New.mat[i][j];
		}
	}
	return Source;
}
std::ostream & operator<<(std::ostream &Target, Matrix Source)
{
	int i,j;
	int length=getMaxSpace(Source);
	for(i=0;i<Source.height;i++)
	{
		Target<<"|";
		for(j=0;j<Source.width;j++)
		{
			Target<<"_";
			cout.width(length);
			cout.fill(' ');
			Target<<Source[i][j]<<"_|";
		}
		Target<<endl;
	}
	return Target;
}
bool operator==(Matrix This, Matrix Other)
{
	if((This.width==Other.width)&&(This.height==Other.height))
	{
		for (int i=0;i<This.height;i++)
		{
			for(int j=0;j<This.width;j++) if (This[i][j]!=Other[i][j]) return false;
		}
		return true;
	}
	return false;	 
}
bool operator!=(Matrix This, Matrix Other)
{
	return !(This==Other);
}
/**
* Funkcje macierzowe: Det(); Zeros(),Ones(),Iden(),Rand() (wymiary i macierz)
**/
double Det(Matrix Source)
{
	if(Source.width!=Source.height)
	{
		cout<<"Operacja zakonczona niepowodzeniem - Macierz musi byc kwadratowa."<<endl;
		return 0;
	}
	if(Source.width==1) return Source[0][0];
	else if(Source.width==2) return Source[0][0]*Source[1][1]-(Source[0][1]*Source[1][0]);
		
	Matrix Backup(Source);
	double det=1;
	for(int i=0;i<Backup.width;i++)
	{
		if(Backup.mat[i][i]==0)
		{
			for(int j=i+1;j<Backup.width;j++)
			{
				if(Backup[j][i]!=0)
				{
					double *temp=Backup.mat[i];
					//no viable conversion from Matrix::Proxy to double*
					Backup.mat[i]=Backup.mat[j];
					Backup.mat[j]=temp;
					det=-det;
					break;
				}
				if(j==Backup.width) return 0;
			}
		}
		for(int j=i+1;j<Backup.width;j++)
		{
			if(Backup[j][i]==0) continue;
			double factor=Backup[j][i]/Backup[i][i];
			for(int k=i+1;k<Backup.width;k++)
			{
				Backup.mat[j][k]-=factor*Backup[i][k];
				//[mat] - expression is not assignable
			}
		}
	}
	for(int i=0;i<Backup.width;i++)
	{
		det*=Backup[i][i];
	}
	return det;
}
Matrix Zeros(int _width, int _height)
{
	Matrix New(_width,_height);
	return New;
}
Matrix Zeros(Matrix Other)
{
	Matrix New(Other.width, Other.height);
	return New;
}
Matrix Ones(int _width, int _height)
{
	Matrix New(_width,_height);
	for(int i=0;i<_width;i++)
	{
		for(int j=0;j<_height;j++) New.mat[i][j]=1; 
	}
	return New;
}
Matrix Ones(Matrix Other)
{
	Matrix New(Other);
	for(int i=0;i<Other.width;i++)
	{
		for(int j=0;j<Other.height;j++) New.mat[i][j]=1; 
	}
	return New;
}
Matrix Iden(int _size)
{
	Matrix New(_size,_size);
	for(int i=0;i<_size;i++)
	{
		for(int j=0;j<_size;j++) New.mat[i][j]=i==j?1:0; 
	}
	return New;
}
Matrix Iden(Matrix Other)
{
	Matrix New(Other);
	for(int i=0;i<Other.width;i++)
	{
		for(int j=0;j<Other.width;j++) New.mat[i][j]=i==j?1:0; 
	}
	return New;
}
Matrix Rand(int _width, int _height)
{
	srand (time(NULL));
	Matrix New(_width,_height);
	for(int i=0;i<_width;i++)
	{
		for(int j=0;j<_height;j++) New.mat[i][j]=(double)(rand()%50)/10; 
	}
	return New;
}
Matrix Rand(Matrix Other)
{
	srand(time(NULL));
	Matrix New(Other);
	for(int i=0;i<Other.width;i++)
	{
		for(int j=0;j<Other.height;j++) New.mat[i][j]=(double)(rand()%200+1)/10; 
	}
	return New;
}
/**
* Funkcje macierzowe: Inv(), T(),MaxAbs(),getSize() (Matrix)
**/
string getSize(Matrix This)
{
	stringstream Info;
	Info<<"["<<This.width<<","<<This.height<<"]";
	return Info.str();
}
Matrix Inv(Matrix This)
{
	Matrix Backup(This);
	if(This.width!=This.height)
	{
		cout<<"Nieprawidlowe wymiary."<<endl;
		return This;
	}
	Matrix New(This.width,This.height);
	int i,j,k;
	double temp;
	for(i=0;i<New.width;i++) New.mat[i][i]=1;
	for(k=0;k<New.width;k++)
	{
		temp=This[k][k];
		for(j=0;j<New.width;j++)
		{
			Backup.mat[k][j]/=temp;
			New.mat[k][j]/=temp;
		}
		for(i=0;i<New.width;i++)
		{
			temp=Backup.mat[i][k];
			for(j=0;j<New.width;j++)
			{
				if(i==k) break;
				Backup.mat[i][j]-=Backup.mat[k][j]*temp;
				New.mat[i][j]-=New.mat[k][j]*temp;
			}
		}
	}
	return New;
}
double MaxAbs(Matrix This)
{
	double value=0, val2;
	int i,j;
	for(i=0;i<This.width;i++)
	{
		for(j=0;j<This.height;j++)
		{
			val2=This[i][j]>0?This[i][j]:This[i][j]*(-1);
			if(value<val2) value=val2;
		}
	}
	return value;
}
Matrix T(Matrix This)
{
	Matrix New(This.height,This.width);
	for(int i=0;i<New.width;i++)
	{
		for(int j=0;j<New.height;j++) New.mat[i][j]=This[j][i];
	}
	return New;
}
int getMaxSpace(Matrix This)
{
	stringstream buffer;
	int i,j,length=0,length2;
	for(i=0;i<This.width;i++)
	{
		for(j=0;j<This.height;j++)
		{
			buffer<<This.mat[i][j];
			length2=(buffer.str()).length();
			if(length<length2) length=length2;
			buffer.str(std::string());
		}
	}
	return length;
}