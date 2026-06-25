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
class burgerfactory{
    public:
    burger * createburger(string type){
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
int main(){
    burgerfactory * bf=new burgerfactory();
    burger *b=bf->createburger("standard");
    b->prepare();
}