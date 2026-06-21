#include<bits/stdc++.h>
using namespace std;
class book{
    public:
    string author,title;
    double price;
    //book(): title("unknown"),author("unknown"),price(0.00){} it is a syntax shortcut for the constructor
    book(){//no parameter is given here bcoz it is a default constructor
        author="unknown";
        title="unknown";
        price=0.0;
    }
    void display(){
        cout<<"author : "<<author<<endl;
        cout<<"title : "<<title<<endl;
        cout<<"price : "<<price<<endl;
    }
};
int main(){
    book mybook;
    mybook.display();
    return 0;
}