//parameterized constructor
#include<bits/stdc++.h>
using namespace std;
class circle{
    private:
        double radius;
    public:
        circle(double r):radius(r){}//advance version of syntax of constuctor here we have given some parameter hance it is paramterized constructor
        double area();
};
//we can also define function outside the class in this way
double circle::area(){
    return M_PI*radius*radius;
}
int main(){
    circle mycrl(10);
    cout<<mycrl.area()<<endl;
    return 0;
}