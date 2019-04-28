#include "mapa.h"

mapa::mapa(int d)
{
    if(d<25)
        d=25;
    dimensiune=d;
    harta=new int*[d];
    for(int i=0;i<d;i++)
        harta[i]=new int[d];
    for(int i=0;i<d;i++)
        for(int j=0;j<d;j++)
            harta[i][j]=0;//se initializeaza harta
    int nrAg,n;
    cout<<"Introduceti numarul de agenti:\n";
    cin>>nrAg;
    ag=nrAg;


    this->agenti=new agent*[d];
    srand((unsigned)time(0));
    armor *a=NULL;
    weapon *w=NULL;
    cout<<"1=sniper\n2=shotgun\n3=gun\ndefault=sniper\n";
    for(int i=0;i<nrAg;i++)
        {
            cout<<"Introduceti tipul agentului "<<i<<':';
            cin>>n;
            switch(n)
                {
                case 1:
                    a=new light;
                    w=new sniper;
                break;
                case 2:
                    a=new medium;
                    w=new shotgun;
                break;
                case 3:
                    a=new heavy;
                    w=new gun;
                break;
                default:
                    a=new light;
                    w=new sniper;
                }
            int x=rand()%d,y=rand()%d;
            while(this->getPoz(x,y)==1)
                {
                    x=rand()%d;
                    y=rand()%d;
                }

            switch(i%3)
                {
                    case 0:
                    agenti[i]=new agent1(x,y,a,w);
                    break;
                    case 1:
                    agenti[i]=new agent2(x,y,a,w);
                    break;
                    case 2:
                    agenti[i]=new agent3(x,y,a,w);
                    break;
                }
            this->setPoz(x,y,1);

            w=NULL;
            a=NULL;

        }//se initializeaza vectorul de agenti
        this->show();
        this->view();//se afiseaza configuratia obtinuta


        while(this->endGame()==0)//se simuleaza jocul pe runde
        {

        cout<<"Intro nr runde:\n";
        int m;
        cin>>m;
        if(m==0)//daca se aleg 0 runde se afiseaza configuratia actuala a hartii
        {
            this->show();
            this->view();
        }
        else
        {
        for(int i=0;i<m;i++)
            {

                this->runda();
                if(this->endGame()==1)
                break;
            }
        this->show();//la finalul rundelor se afiseaza agentul ramas
        }

        }
        cout<<"Simulare terminata!";



}
void mapa::runda()
{
    int nrAg=this->getNrAg();
    if(nrAg<2)
        return;//se verifica daca nu s a terminat simularea

    agent *a;
    int d=this->getDim();
    for(int i=0;i<nrAg;i++)//la fiecare runda se parcurge vectorul de agenti si se decide ce actiuni vor lua
    {
        a=agenti[i];
        position p=a->getPoz();
        int r=a->getRng();
        int x=p.x;
        int y=p.y;
        if(srcEnemy(p,r)==0)//se verifica daca agentul i nu are oponenti in raza vizuala
        {
            this->setPoz(x,y,0);
            p=a->mov(1);
            x=p.x;
            y=p.y;
            if((x>=d)||(y>=d)||(x<0)||(y<0))
                p=a->mov(-1);

            this->setPoz(p.x,p.y,1);
            a->setPoz(p.x,p.y);//se muta agentul i conform regulii din functia mov()
        }
        else
        {
            int j;
            for(j=0;j<nrAg;j++)
                if(agenti[j]->getPoz().x==p.x&&agenti[j]->getPoz().y==p.y)
                {
                    a=agenti[j];
                    break;//se cauta oponentul din raza vizuala
                }
            int dmg=agenti[i]->getDmg();
            int arm=a->getArmor();
            int hp=a->getHp();
            if(arm<=dmg)
            {
                dmg-=arm;
                arm=0;
                hp-=dmg;
            }
            else
            {
                arm-=dmg;
                dmg=0;
            }//i se aplica modificari asupra armurii si vietii conform daunelor suferite

            if(hp>0)
            {
                agenti[j]->setArmor(arm);
                agenti[j]->setHp(hp);//se salveaza modificarile
            }
            else
            {
                position l=agenti[j]->getPoz();
                this->setPoz(l.x,l.y,0);
                for(int k=j;k<nrAg-1;k++)
                    agenti[k]=agenti[k+1];
                if(i>j)
                    i--;

                nrAg--;//in cazul mortii oponentului acesta este sters din vectorul de agenti
            }

        }


    }
    this->setNrAg(nrAg);



}
int mapa::srcEnemy(position&p,int rg)//se cauta un alt agent in raza introdusa prin rg in jurul pozitiei p
{


    int x=p.x,y=p.y,dim=this->getDim();
    int a=x-rg,b=x+rg,c=y-rg,d=y+rg;
    if(a<0)
        a=0;
    if(c<0)
        c=0;
    if(b>=dim)
        b=d-1;
    if(d>=dim)
        d=dim-1;
    for(int i=a;i<=b;i++)
        for(int j=c;j<=d;j++)
            if(i!=x||j!=y)
                if(this->getPoz(i,j)==1)
            {
                p.x=i;
                p.y=j;
                return 1;//functia intoarce pozitia oponentului prin p
            }
    return 0;
}

void mapa::show()//afiseaza detalii despre configuratia actuala a agentilor
{
    int n=ag;
    cout<<"Agenti:\n";
    for(int i=0;i<n;i++)
        {
            cout<<"HP:"<<agenti[i]->getHp()<<' ';
            cout<<"Armor:"<<agenti[i]->getArmor()<<' ';
            cout<<"Range:"<<agenti[i]->getRng()<<' ';
            cout<<"Damage:"<<agenti[i]->getDmg()<<' ';
            cout<<"Position:"<<agenti[i]->getPoz()<<endl;
        }
}
mapa::~mapa()
{
    for(int i=0;i<this->dimensiune;i++)
        delete harta[i];
    delete harta;
}

void mapa::view()//afiseaza configuratia hartii
{
    int d=this->getDim();
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
            cout<<this->getPoz(i,j)<<' ';
        cout<<endl;
    }
}

int mapa::endGame()//verifica daca a ramas doar un agent pe harta
{
    int nrAg=this->getNrAg();
    if(nrAg<2)
        return 1;
    return 0;
}

