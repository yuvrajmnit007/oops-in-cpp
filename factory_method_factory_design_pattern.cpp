#include<iostream>
using namespace std;
class burger{
    public:
    virtual void prepare()=0;
    ~burger(){}
};
class basicburger : public burger{
    public:
    void prepare() override{
        cout<<"basic burger"<<endl;
    }
};
class standardburger : public burger{
    public:
    void prepare() override{
        cout<<"standard burger"<<endl;
    }
};
class premiumburger : public burger{
    public:
    void prepare() override{
        cout<<"premium burger"<<endl;
    }
};
class basicwheatburger : public burger{
    public:
    void prepare() override{
        cout<<"basic wheat burger"<<endl;
    }
};
class standardwheatburger : public burger{
    public:
    void prepare() override{
        cout<<"standard wheat burger"<<endl;
    }
};
class premiumwheatburger : public burger{
    public:
    void prepare() override{
        cout<<"premium wheat burger"<<endl;
    }
};
class burgerfactory{
    public:
    virtual burger * createburger(string &type)=0;
};
class singhburger:public burgerfactory{
    public:
    burger * createburger(string &type) override{
        if(type=="basic"){
            return new basicburger();
        }else if(type=="standard"){
            return new standardburger();
        }else if(type=="premium"){
            return new premiumburger();
        }else{
            return nullptr;
        }
    }
};
class kingburger:public burgerfactory{
    public:
    burger * createburger(string &type) override{
        if(type=="basic"){
            return new basicwheatburger();
        }else if(type=="standard"){
            return new standardwheatburger();
        }else if(type=="premium"){
            return new premiumwheatburger();
        }else{
            return nullptr;
        }
    }
};
int main(){
    string s="basic";
    burgerfactory * bf=new kingburger();
    burger *b=bf->createburger(s);
    b->prepare();
}