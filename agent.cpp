#include "agent.h"

agent::agent(){}

agent::agent(int hp,armor *a,weapon *w):poz(position(-1,-1)),health(hp),arm(a),wp(w){speed=(wp->getRange())/4;}

agent::agent(int x,int y,int hp,armor *a,weapon *w):poz(position(x,y)),health(hp),arm(a),wp(w){speed=(wp->getRange())/4;}

position agent::getPoz(){return this->poz;}

void agent::setHp(int x){this->health=x;}

void agent::setArmor(int x){this->arm->Setarm(x);}

void agent::setPoz(int a,int b){this->poz.x=a;this->poz.y=b;}

int agent::getHp(){return this->health;}

int agent::getArmor(){return this->arm->Getarm();}

int agent::getRng(){return this->wp->getRange();}

int agent::getDmg(){return this->wp->getDmg();}

int agent::getSpd(){return this->speed;}

int agent::checkDead(){if(getHp()<=0) return 1; return 0;}

agent::~agent()
{
    delete wp;
    delete arm;
}

position agent1::mov(int a)
{
    static int i=1;
    i=i*a;
    int s=this->getSpd();
    s=s*i;
    position p=this->getPoz();
    p.x+=s;
    p.y+=s;
    return p;

}

position agent2::mov(int a)
{
    static int i=1;
    i=i*a;
    int s=this->getSpd();
    s=s*i;
    position p=this->getPoz();
    p.x-=s;
    p.y+=s;
    return p;

}

position agent3::mov(int a)
{
    static int i=1;
    i=i*a;
    int s=this->getSpd();
    s=s*i;
    position p=this->getPoz();
    p.x-=s;
    p.y-=s;
    return p;

}

