class Vector{
public:
Vector();
Vector(int);
Vector(double*,int);
Vector(const Vector&);
~Vector();
Vector& operator=(const Vector&);
double& operator[](size_t);
const double& operator[](size_t) const;
int get_size();
Vector& set_size(int);
Vector& dodaj(double);

friend std::istream& operator>>(std::istream&, Vector&);
friend std::ostream& operator<<(std::ostream&, Vector&);
friend bool operator==(Vector, Vector);
friend bool operator!=(Vector, Vector);

protected:
double *vect;
int len;
};
