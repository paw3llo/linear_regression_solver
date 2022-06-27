#ifndef KLASA_H
#define KLASA_H
#include <iostream>
#include <vector>
#include <math.h>
#include "permutacje.h"

using namespace std;

class klasa
{
    public:
        vector< vector<double> > tablica;
        vector <double> bestparameter;

        void dopasuj_model();
    protected:

    private:
};

#endif // KLASA_H
