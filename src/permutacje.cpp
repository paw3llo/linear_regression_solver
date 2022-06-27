#include "permutacje.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;
//----------
vector< vector<double> > wartosci_z_pliku(){

    vector< vector<double> > tablica;
    string nazwa_pliku;//="dane4.txt";
    cout<<"Podaj nazwe pliku z danymi."<<endl;
    cin>>nazwa_pliku;
    ifstream dane;
    dane.open(nazwa_pliku.c_str());
    string temp;
    string temp2;
    double temp_d3;
    int x_size=0;
    //
        while(getline(dane,temp)){
        x_size=x_size+1;
        tablica.resize(x_size);
        int y_size=0;
        do{
            temp=temp.substr(temp.find("	")+1,temp.length()-temp.find("	"));
            y_size=y_size+1;
        }while(temp.find("	")!=std::string::npos);
        y_size=y_size+1;
        tablica[tablica.size()-1].resize(y_size,0);

    }

    dane.close();
    dane.open(nazwa_pliku.c_str());
    //
    temp="";
    temp2="";
    temp_d3=0;
    int a=0;
    while(getline(dane,temp)){
        int b=0;
        do{

            temp2=temp.substr( 0,temp.find("	"));
            //cout<<temp2<<" ; ";
            tablica[a][b]=(string_to_double(temp2));
            temp=temp.substr(temp.find("	")+1,temp.length()-temp.find("	"));
            b++;
        }while(temp.find("	")!=std::string::npos);
        temp2= temp.substr( 0,temp.find("	"));
        //cout<<temp2<<endl;
        tablica[a][b]=(string_to_double(temp2));
    a++;
    }
    dane.close();
    //cout<<"koniec wczytywania"<<endl;
    return tablica;
}

double string_to_double(string input){
    int y=0;
    double output=0;
    bool byl_przecinek=false;
    char delimiter='.';
    int pozycja_przecinka=0;
    for(int i=0;i<=input.size()-1;i++){
        if(input[i]==delimiter){
            pozycja_przecinka=i;
        }
    }
    if(pozycja_przecinka==0){
        for(int i=0;i<=input.size()-1;i++){
            y=input[i]-48;
            output=output+y*pow(10,input.size()-i-1);
        }
    }else{
        for(int i=0;i<=input.size()-1;i++){
            if(i==pozycja_przecinka){
                byl_przecinek=true;
            }else{
                y=input[i]-48;
                if(byl_przecinek==false){
                    output=output+y*pow(10,pozycja_przecinka-i-1);
                }else{
                    output=output+y*pow(10,pozycja_przecinka-i);
                }
            }
        }
    }
    return output;
}
//----------
//----------

int potega(int podstawa, int wykladnik){
int wynik =1;
for(int i=1;i<=wykladnik;i++){
    wynik=wynik*podstawa;
}
return wynik;
}
//-----------
void wyznacz_permutacje(int glebokosc, int &y,vector <int> branches_in_node,int &ile,int ilosc_galezi,vector <vector <int> > &wyniki){
    //vector <vector <int> > wyniki;
    int ilosc_wynikow=potega(ilosc_galezi,glebokosc);
    //wyniki.resize(ilosc_wynikow);
    //for(int i=0;i<ilosc_wynikow;i++){
    //    wyniki[i].resize(glebokosc,0);
    //}
    if(ile!=ilosc_wynikow){
    y++;
    branches_in_node[y]++;
    if(y==glebokosc){
        ile++;
        //cout<<"nr "<<ile<<" := ";
        for(int i=1;i<=glebokosc;i++){
            //cout<<branches_in_node[i]<<" ; ";
            wyniki[ile-1][i-1]=branches_in_node[i];
            //cout<<wyniki[ile-1][i-1]<<" ; ";
        }
        //cout<<endl;
        y--;
        if(branches_in_node[y+1]!=ilosc_galezi){
            wyznacz_permutacje(glebokosc,y,branches_in_node,ile,ilosc_galezi,wyniki);
        }
        else{
            do{
                branches_in_node[y+1]=0;
                y--;
            }while(branches_in_node[y+1]==ilosc_galezi);
            wyznacz_permutacje(glebokosc,y,branches_in_node,ile,ilosc_galezi,wyniki);
        }
    }
    else {
        wyznacz_permutacje(glebokosc,y,branches_in_node,ile,ilosc_galezi,wyniki);
    }
    }
    else{
    //cout<<"koniec"<<endl;
    return;
    }
}
