#ifndef WEAPON_H
#define WEAPON_H
#include <vector>
#include <iostream>
using namespace std;

class weapon
{
    const int range;
    const int damage;
    public:
        weapon();
        weapon(int dmg,int rg);
        ~weapon(){}
        int getRange();
        int getDmg();


};

class sniper:public weapon
{
  public:
      sniper():weapon(5,8){}
};
class shotgun:public weapon
{
public:
    shotgun():weapon(10,5){}
};
class gun:public weapon
{
public:
    gun():weapon(7,7){}
};
#endif // WEAPON_H
