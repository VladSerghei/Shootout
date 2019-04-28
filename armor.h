#ifndef ARMOR_H
#define ARMOR_H


class armor
{

        int arm;
    public:
        armor(int x);
        ~armor(){}
        int Getarm() { return arm; }
        void Setarm(int val) { arm = val; }




};

class heavy:public armor
{
public:
    heavy():armor(20){}
};

class medium:public armor
{
public:
    medium():armor(10){}
};

class light:public armor
{
public:
    light():armor(5){}
};
#endif // ARMOR_H
