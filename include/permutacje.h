#ifndef PERMUTACJE_H
#define PERMUTACJE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;
        vector< vector<double> > wartosci_z_pliku();
        double string_to_double(string input);
        int potega(int podstawa, int wykladnik);
        void wyznacz_permutacje(int glebokosc, int &y,std::vector <int> branches_in_node,int &ile,int ilosc_galezi,vector <vector <int> > &wyniki);



#endif // PERMUTACJE_H
