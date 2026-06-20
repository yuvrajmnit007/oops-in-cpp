#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<=k;i++){
            vector<int>temp;
            for(int j=i;j<n;j+=(k+1)){
                temp.push_back(arr[j]);
            }
            for(int j=1;j<temp.size();j++){
                temp[j]+=temp[j-1];
            }
            mp[i]=temp;
        }
        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
        }
        for(int i=0;i<n;i++){
            int ans=arr[i];
            if(i>=k){
                int rem=(i-k)%(k+1);
                int pos=(i-k)/(k+1);
                ans-=mp[rem][pos];
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}