#ifndef AGENT_H
#define AGENT_H
#include "weapon.h"
#include "armor.h"
using namespace std;

struct position{
    int x;
    int y;
    position(){x=0;y=0;}
    position(int a,int b){x=a;y=b;}
    friend ostream& operator<<(ostream& out,const position& p){out<<p.x<<' '<<p.y;return out;}
    };
class agent
{
    position poz;
    int health;
    armor *arm;

    int speed;
    weapon *wp;

    public:
        agent();
        agent(int hp,armor *a,weapon *w);
        agent(int x,int y,int hp,armor *a,weapon *w);
        virtual ~agent();

        virtual position mov(int a)=0;//functia de miscare a agentilor

        void setPoz(int,int);
        void setHp(int);
        void setArmor(int);

        int getArmor();
        int getHp();
        int getDmg();
        int getRng();
        int getSpd();
        position getPoz();
        int checkDead();

        friend ostream& operator<<(ostream& out,agent* p){out<<p->getHp()<<' '<<p->getArmor()<<' '<<p->getSpd()<<' '<<p->getRng()<<' '<<p->getDmg()<<' '<<p->getPoz();return out;}




};

class agent1:public agent
{
public:
    agent1(int x,int y,armor *a,weapon *w):agent(x,y,30,a,w){}
    agent1(){}
    agent1(armor *a,weapon *w):agent(30,a,w){}
    position mov(int a);

};

class agent2:public agent
{
public:
    agent2(int x,int y,armor *a,weapon *w):agent(x,y,30,a,w){}
    agent2(){}
    agent2(armor *a,weapon *w):agent(30,a,w){}
    position mov(int a);

};

class agent3:public agent
{
public:
    agent3(int x,int y,armor *a,weapon *w):agent(x,y,30,a,w){}
    agent3(){}
    agent3(armor *a,weapon *w):agent(30,a,w){}
    position mov(int a);

};

#endif // AGENT_H
