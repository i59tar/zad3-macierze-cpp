#ifndef LIBRARIES
#define LIBRARIES
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#define CELL_WIDTH 8

class Matrix
{
	public:
	int width;
	int height;
	double **mat;
	
	Matrix();
	Matrix(int,int);
	Matrix(const Matrix&);
	~Matrix();

	class Proxy
	{
		public:
		Proxy(double *);
		double operator[](int);
		private:
		double *_rows;
	};
	Proxy operator[](int);
	
	Matrix& operator=(const Matrix &);
	Matrix operator+(Matrix);	
	Matrix operator-(Matrix);
	Matrix operator+=(Matrix);	
	Matrix operator-=(Matrix);	
	Matrix operator*(double);
	Matrix operator*(Matrix);
	Matrix operator*=(double);
	Matrix operator*=(Matrix);
	

	friend std::istream& operator>>(std::istream&, Matrix&);
	friend std::ostream& operator<<(std::ostream&, Matrix);
	friend bool operator==(Matrix, Matrix);
	friend bool operator!=(Matrix, Matrix);

};
double Det(Matrix);
Matrix Zeros(int,int);
Matrix Zeros(Matrix);
Matrix Ones(int,int);
Matrix Ones(Matrix);
Matrix Iden(int,int);
Matrix Iden(Matrix);
Matrix Rand(int,int);
Matrix Rand(Matrix);

Matrix Inv(Matrix);
Matrix T(Matrix);
double MaxAbs(Matrix);
std::string getSize(Matrix);

//funkcja pomocnicza na potrzeby cout
int getMaxSpace(Matrix);
#endif
