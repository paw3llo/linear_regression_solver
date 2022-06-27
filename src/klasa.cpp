#include "klasa.h"
#include <iostream>
#include <vector>
#include<math.h>
#include "permutacje.h"

using namespace std;



void klasa::dopasuj_model(){
    string z;
    //cin>>z;
    //vector< vector<double> > tablica;
    tablica= wartosci_z_pliku();
    vector <int> branches_in_node;
    int glebokosc=tablica[1].size();
    int ilosc_galezi=5;
    branches_in_node.resize(glebokosc+1,0);
    int y=0;
    int ile=0;
    vector <vector <int> > wyniki;
    int ilosc_wynikow=potega(ilosc_galezi,glebokosc);
    wyniki.resize(ilosc_wynikow);
    for(int i=0;i<ilosc_wynikow;i++){
        wyniki[i].resize(glebokosc,0);
    }
    wyznacz_permutacje(glebokosc,y,branches_in_node,ile,ilosc_galezi,wyniki);
    cout<<endl<<"Wczytane dane:"<<endl;

    cout<<"Y; ";
    for(int b=1; b<tablica[0].size();b++){
        cout<<"X"<<b<<"; ";
    }
    cout<<endl;
    for(int a=0;a<tablica.size();a++){
        for(int b=0; b<tablica[a].size();b++){
            cout<<tablica[a][b]<<"; ";
        }
        cout<<endl;
    }
    //
    double SE=0;
    vector <double> parametr;
    parametr.resize(glebokosc,0);

    //
    //vector <double> bestparameter;
    bestparameter.resize(glebokosc,0);
    vector <double> offset;
    offset.resize(glebokosc,0);
    double bestSE=0;
    for(int dzielnikprecision=0;dzielnikprecision<=5;dzielnikprecision++){
        vector <bool> zmiana;
        zmiana.resize(glebokosc,1);
        double precyzja=pow(10,(-1)*dzielnikprecision);
        bool czy_wszystkie_zmienne_converged;
        int x=0;
        do{
            x++;
            for(int j=0;j<wyniki.size();j++){
                SE=0;
                for(int z=0;z<parametr.size();z++){
                offset[z] =(wyniki[j][z]-((ilosc_galezi+1)/2))*precyzja;
                }
                    for(int i=0;i<tablica.size();i++){
                        //cout<<" > "<<endl;
                        double parametry_razy_zmienne=0;
                        for(int z=0;z<parametr.size()-1;z++){
                            parametry_razy_zmienne=parametry_razy_zmienne+(parametr[z]+offset[z])*tablica[i][z+1];
                        }
                        parametry_razy_zmienne=parametry_razy_zmienne+parametr[parametr.size()-1]+offset[parametr.size()-1];
                        SE=SE+pow(tablica[i][0]-parametry_razy_zmienne,2);
                        parametry_razy_zmienne=0;
                    }
                    /*
                        cout<<"inbetween: ";
                        for(int a=0;a<parametr.size();a++){
                            cout<<parametr[a]+offset[a]<<" ; ";
                        }
                        cout<<SE<<endl;
                    */
                if(j!=0){
                    if(SE<bestSE){
                        for(int z=0;z<parametr.size();z++){
                        bestparameter[z]=parametr[z]+offset[z];
                            }
                        bestSE=SE;
                    }
                }else{
                        for(int z=0;z<parametr.size();z++){
                        bestparameter[z]=parametr[z]+offset[z];
                            }
                        bestSE=SE;
                }
                }
                for(int z=0;z<parametr.size();z++){
                    if(bestparameter[z]==parametr[z]){
                        zmiana[z]=false;
                    }
                }
                czy_wszystkie_zmienne_converged=true;
                for(int z=0;z<=zmiana.size();z++){
                    if(zmiana[z]==true){
                        czy_wszystkie_zmienne_converged=false;
                    }
                }
            for(int z=0;z<parametr.size();z++){
                parametr[z]=bestparameter[z];
            }
            //cout<<" !!! "<<endl;
        }while(czy_wszystkie_zmienne_converged==false);
    /*
    cout<<"fin: ";
    for(int a=0;a<bestparameter.size();a++){
        cout<<bestparameter[a]<<" ; ";
    }
    cout<<bestSE<<endl;
    string next;
    //cin>>next;
    */
    }
    cout<<endl<<"Parametry: "<<endl;
    for(int a=0;a<bestparameter.size()-1;a++){
        cout<<"B"<<a+1<<" ; ";
    }
    cout<<"wyraz wolny";
    cout<<endl;
    for(int a=0;a<bestparameter.size();a++){
        cout<<bestparameter[a]<<" ; ";
    }
    cout<<endl;
    cout<<"Sredni Blad Kwadratowy (MSE)= ";
    cout<<bestSE/tablica.size()<<endl;
    string next;
};


//return 0;


