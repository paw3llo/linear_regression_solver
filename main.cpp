#include <iostream>
//#include <vector>
//#include<math.h>
//#include "permutacje.h"
#include "klasa.h"
using namespace std;


int main()
{
    klasa model;
    string czy_powtorzyc="N";
    do{
        model.dopasuj_model();
        cout<<endl<<"Czy powtorzyc Y/N"<<endl;
        cin>>czy_powtorzyc;
    }while(czy_powtorzyc=="Y");
    return 0;
}
