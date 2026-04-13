#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FPB __gcd 

int t,n;

int kpk(int a,int b){
        return a*b/(FPB(a,b));
}
int main(){
        cin>>t;
        int ans=1;
        while(t--){
                cin>>n;
                ans=kpk(n,ans);
        }
        cout<<ans;
}