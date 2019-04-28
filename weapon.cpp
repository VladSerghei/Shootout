#include "weapon.h"

weapon::weapon():damage(0),range(0){}

weapon::weapon(int dmg,int rg):damage(dmg),range(rg){}

int weapon::getDmg(){return this->damage;}

int weapon::getRange(){return this->range;}






