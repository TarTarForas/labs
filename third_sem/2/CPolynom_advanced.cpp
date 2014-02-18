#include "CPolynom.h"

//degree-init constructor
Polynom :: Polynom(unsigned int deg) {
    if (deg >= MAX_DEGREE)
        deg = MAX_DEGREE;
    coef = new double[deg+1];
    degree = deg;
    for (unsigned int i = 0; i <= degree; i++)
        coef[i] = 0;
}

//zero-constructor
Polynom :: Polynom(){
    coef = new double[1];
    degree = 0;
    coef[0] = 0;
}

Polynom :: ~Polynom() {
    delete [] coef;
}

//do we need this ugly method?
void Polynom :: setDegree(unsigned int deg) {
    if (deg < MAX_DEGREE) {
        double *tmp = new double[deg+1];
        for (unsigned int i = 0; i <= degree; i++) {
            tmp[i] = coef[i];
        }
        delete [] coef;
        coef = tmp;
        for (unsigned int i = degree+1; i <= deg; i++)
            coef[i] = 0;
        degree = deg;
        //this->correctDegree();
    } else
        cout << "Degree  of polynom >= " << MAX_DEGREE << endl;
}

unsigned int Polynom :: getDegree() {
    return degree;
}


void Polynom :: correctDegree() {
    bool zero = false;
    int deg = degree;
    //until we find first non-zero elem
    while (deg > 0 && !zero) {
        if (coef[deg] != 0)
            zero = true;
        else
            deg--;
    }
    degree = deg;
}

void Polynom :: input() {
    cout << "Degree of polynom = " << degree << endl;
    for (unsigned int i = 0; i <= degree; i++) {
        cout << "Input coef of " << i << "'th degree: ";
        cin >> coef[i];
    }
    //we should check that there no zero-coef with highest degree
    if (coef[degree] == 0)
        this->correctDegree();
}

void Polynom :: print() {
//    if (coef[0] != 0 || degree == 0)
        cout << '(' << coef[0] << ')';
    for (unsigned int i = 1; i <= degree; i++) {
        if (coef[i] != 0)
            cout << " + (" << coef[i] << ")*x^" << i;
    }
}

double Polynom :: calcAtPoint(double x) {
    double result = coef[0];
    for (unsigned int i = 1; i <= degree; i++) {
        result += coef[i] * x;
        x *= x;
    }
    return result;
}

//if this > pol, return 1; else if they equal, return 0; else -1
int Polynom :: compare(Polynom &pol) {
    if (degree > pol.degree)
        return 1;
    else
        if (pol.degree > degree)
            return -1;
        else {
            for (unsigned int i = degree; i >= 0; i--)
                if (coef[i] > pol.coef[i])
                    return 1;
                else
                    if (pol.coef[i] > coef[i])
                        return -1;
            return 0;
        }
}

Polynom Polynom :: operator + (Polynom &pol) {
    unsigned int i;
    Polynom *result;

    //if first's degree > second's
    if(degree >= pol.degree) {
        result = new Polynom(degree);
        for(i = 0; i <= pol.degree; i++)
            result->coef[i] = coef[i] + pol.coef[i];
        for (i = pol.degree+1; i <= degree; i++)
            result->coef[i] = coef[i];
    } else {
        result = new Polynom(pol.degree);
        for(i = 0; i <= degree; i++)
            result->coef[i] = coef[i] + pol.coef[i];
        for (i = degree+1; i <= pol.degree; i++)
            result->coef[i] = pol.coef[i];
    }
    result->correctDegree();
    return *result;
}


Polynom Polynom :: operator - (Polynom &pol) {
    unsigned int i;
    Polynom *result;

    if(degree >= pol.degree) {
        result = new Polynom(degree);
        for(i = 0; i <= pol.degree; i++)
            result->coef[i] = coef[i] - pol.coef[i];
        for (i = pol.degree+1; i <= degree; i++)
            result->coef[i] = coef[i];
    } else {
        result = new Polynom(pol.degree);
        for(i = 0; i <= degree; i++)
            result->coef[i] = coef[i] - pol.coef[i];
        for (i = degree+1; i <= pol.degree; i++)
            result->coef[i] = -(pol.coef[i]);
    }
    result->correctDegree();
    return *result;
}

//mult by double ^ int
Polynom Polynom :: operator * (pair<double, int> elem) {
    unsigned int i;
    Polynom *result;

    if (elem.first == 0) {
        result = new Polynom;
    } else {
        result = new Polynom(degree + elem.second);
        for (i = 0; i <= degree; i++) {
            result->coef[i+elem.second] = coef[i]*elem.first;
        }
    }
    return *result;
}


Polynom Polynom :: operator * (Polynom &pol) {
    unsigned int i, j;
    Polynom temp(degree + pol.degree);
    Polynom *result = new Polynom(degree + pol.degree);
    for (i = 0; i <= degree; i++) {
        for (j = 0; j <= pol.degree; j++)
            result->coef[i+j] = result->coef[i+j] + coef[i] * pol.coef[j];
    }
    result->correctDegree();
    return *result;
}


