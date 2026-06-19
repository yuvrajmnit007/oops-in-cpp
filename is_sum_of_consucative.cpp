#include <iostream>
using namespace std;
int main(){
    int a;
    cin>>a;
    int ans=0;
    for(int i=2;i<=a;i++){
        if((a-i*(i+1)/2)%i==0){
            ans=i;
            break;
        }
    }
    if(ans==0&&a!=0){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        cout<<ans<<endl;
    }
    return 0;
}