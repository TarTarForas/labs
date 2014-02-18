#ifndef CPOLYNOM_INCLUDED
#define CPOLYNOM_INCLUDED

#include <iostream>
#include <algorithm>

using namespace std;

const unsigned int MAX_DEGREE = 100;

double getElem(const string txt);

class Polynom {
private:
    double *coef;
    unsigned int degree;
    void correctDegree();
    //integrate const
    bool hasConstant;
public:
    Polynom(unsigned int deg);
    Polynom();
    ~Polynom();

    void setDegree(unsigned int deg);
    unsigned int getDegree();

    void input();
    void print();

    double calcAtPoint(double x);
    //TODO
    Polynom integrate();
    Polynom differentiate();

    int compare(Polynom &pol);
    Polynom operator + (Polynom &pol);
    Polynom operator - (Polynom &pol);
    Polynom operator * (Polynom &pol);
    Polynom operator = (const Polynom &pol);
};

#endif // CPOLYNOM_INCLUDED
