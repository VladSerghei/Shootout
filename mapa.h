#ifndef MAPA_H
#define MAPA_H
#include "agent.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;


class mapa
{
    int dimensiune;
    int **harta;
    agent** agenti;
    int ag;


    public:
        mapa(int d=25);
        ~mapa();
        int getPoz(int a,int b){return harta[a][b];}
        void setPoz(int a,int b,int n){harta[a][b]=n;}
        int getDim(){return dimensiune;}
        void runda();
        int srcEnemy(position&,int);
        void show();
        void view();
        int endGame();
        int getNrAg(){return ag;}
        void setNrAg(int x){this->ag=x;}

};

#endif // MAPA_H
