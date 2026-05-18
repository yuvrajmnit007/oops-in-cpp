#include <bits/stdc++.h>
using namespace std;
class geometry{
    public:
    double rectarea(double length,double breadth){
        return length*breadth;
    }
    double rectperi(double length,double breadth){
        return 2*(length+breadth);
    }
    double sqrarea(double side){
        return side*side;
    }
    double sqrperi(double side){
        return 4*side;
    }
    double circlearea(double radius){
        return M_PI*radius*radius;
    }
    double circlecircum(double radius){
        return 2*M_PI*radius;
    }
    double trianglearea(double a,double b,double c){
        double s=(a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
};
int main(){
    double a,b,c,l,r,s;
    geometry g1;
    a=3,b=4,c=5,l=6,r=7,s=8;
    cout<<g1.rectarea(l,b)<<endl;
    cout<<g1.rectperi(l,b)<<endl;
    return 0;
}