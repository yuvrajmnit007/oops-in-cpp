#include<bits/stdc++.h>
using namespace std;
class cplx{
    float real;
    float img;
    public:
        cplx(float r,float i) : real(r),img(i){}
        static cplx multiply(cplx &c1, cplx &c2){
            cplx ans(0,0);//we need to define it for defalt so that it does not give error 
            ans.real=c1.real*c2.real-c1.img*c2.img;
            ans.img=c1.real*c2.img+c1.img*c2.real;
            return ans;
        }
        void display(){
            cout<<real<<" ";
            if(img<0){
                cout<<img<<"i"<<endl;
            }else{
                cout<<"+"<<img<<"i"<<endl;
            }
        }

};
int main(){
    cplx c1(2,3), c2(4,5);
    cplx ans = cplx::multiply(c1,c2);
    ans.display();
    return 0;
}