#include<bits/stdc++.h>
using namespace std;
class myclass{
    int m,c;
    public:
        void setvalue(int meter,int centi){
            m=meter;
            c=centi;
        }
        myclass add(myclass &a,myclass &b){
            myclass ans;
            ans.m=a.m+b.m;
            ans.c=a.c+b.c;
            ans.m+=ans.c/100;
            ans.c%=100;
            return ans;
        }
        void display(myclass p){
            cout<<p.m<<" meter "<<p.c<<" centimeter"<<endl;
        }
};
int main(){
    myclass a,b,ans;
    a.setvalue(19,64);
    b.setvalue(19,16);
    ans=ans.add(a,b);
    ans.display(ans);
    return 0;
}