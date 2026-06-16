#include<iostream>
using namespace std;
class customer{
    string name;
    int age;
    public:
    //default 
    customer(){
        cout<<"this is a default constructor"<<endl;
        name="rohit";
        age=25;
    }
    //parametrized
    customer(string name,int age){
        this->name=name;
        this->age=age;
    }
    //copy
    customer(customer &b){
        name=b.name;
        age=b.age;
    }
    void display(){
        cout<<name<<" "<<age<<endl;
    }
};
int main(){
    customer c;
    customer a("yuvraj",23);
    customer b(a);
    a.display();
    b.display();
    c.display();
    return 0;
}