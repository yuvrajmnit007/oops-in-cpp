#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Isubscriber{
    public: 
    virtual void update()=0;
    virtual ~Isubscriber(){}
};
class Ichannel{
    public:
    virtual void subscribe(Isubscriber* sub)=0;
    virtual void unsubscribe(Isubscriber* sub)=0;
    virtual void notify()=0;
    virtual ~Ichannel(){}
};
//here srp is breaks but we have to do this tread off sometimes to make code easy 
class Channel:public Ichannel{
    private:
    string name,latestvideo;
    vector<Isubscriber*>vec;
    public:
    Channel(const string& name){
        this->name=name;
    }
    void subscribe(Isubscriber * sub)override{
        bool ans=false;
        for(auto it:vec){
            if(it==sub){
                ans=true;
            }
        }
        if(!ans)vec.push_back(sub);
    }
    void unsubscribe(Isubscriber * sub)override{
        vec.erase(remove(vec.begin(), vec.end(), sub), vec.end());
    }
    void notify()override{
        for(auto it:vec){
            it->update();
        }
    }
    void uplaod_video(const string &title){
        latestvideo=title;
        cout << "\n[" << name << " uploaded \"" << title << "\"]\n";
        notify();
    }
    string getvideodata() {
        return "\nCheckout our new Video : " + latestvideo + "\n";
    }
};
class subscriber:public Isubscriber{
    private:
    string name;
    Channel* channel;
    public:
    subscriber(string name,Channel* channel){
        this->name=name;
        this->channel=channel;
    }
    void update() override {
        cout << "Hey " << name << "," << this->channel->getvideodata();
    }
};
int main(){
    Channel* channel = new Channel("CoderArmy");
    subscriber* subs1 = new subscriber("Varun", channel);
    subscriber* subs2 = new subscriber("Tarun", channel);
    channel->subscribe(subs1);
    channel->subscribe(subs2);
    channel->uplaod_video("Observer Pattern Tutorial");
    channel->unsubscribe(subs1);
    channel->uplaod_video("Decorator Pattern Tutorial");

}