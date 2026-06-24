#include<iostream>
using namespace std;
//abstract class
class talkable{
    public:
    virtual void talk()=0;
    virtual ~talkable(){}
};
//inherited class of talk
class normaltalk:public talkable{
    public:
    void talk() override{
        cout<<"normal talk....."<<endl;
    }
};
class notalk:public talkable{
    public:
    void talk() override{
        cout<<"no talking....."<<endl;
    }
};
class walkable{
    public:
    virtual void walk()=0;
    virtual ~walkable(){}
};
class normalwalk:public walkable{
    public:
    void walk() override{
        cout<<"normal walk....."<<endl;
    }
};
class nowalk:public walkable{
    public:
    void walk() override{
        cout<<"no walking....."<<endl;
    }
};
class flyable{
    public:
    virtual void fly()=0;
    virtual ~flyable(){}
};
class normalfly:public flyable{
    public:
    void fly() override{
        cout<<"normal fly....."<<endl;
    }
};
class nofly:public flyable{
    public:
    void fly() override{
        cout<<"no flying....."<<endl;
    }
};
class flywithjet:public flyable{
    public:
    void fly() override{
        cout<<"flying with jet....."<<endl;
    }
};
class robot{
    protected:
    flyable* f;
    walkable* w;
    talkable* t;
    public:
    robot(walkable* w,talkable* t,flyable* f){
        this->f=f;
        this->t=t;
        this->w=w;
    }
    void walk(){
        w->walk();
    }
    void talk(){
        t->talk();
    }
    void fly(){
        f->fly();
    }
    virtual void projection()=0;
};
class companionrobot:public robot{
    public:
    companionrobot(walkable* w,talkable* t,flyable* f): robot(w,t,f){};
    void projection()override{
        cout<<"campanion robot:"<<endl;
    }
};
class workerrobot:public robot{
    public:
    workerrobot(walkable* w,talkable* t,flyable* f): robot(w,t,f){};
    void projection()override{
        cout<<"worker robot:"<<endl;
    }
};
int main(){
    robot *r=new companionrobot(new normalwalk(),new notalk(),new flywithjet());
    r->projection();
    r->fly();
    r->talk();
    r->walk();
    cout<<"------------------------"<<endl;
    robot *r1=new workerrobot(new nowalk(),new normaltalk(),new nofly());
    r1->projection();
    r1->fly();
    r1->talk();
    r1->walk();
    return 0;
}