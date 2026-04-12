#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define FOR(i,a,n) for(int i=(a); i <= (n); i++)
#define ROF(i,a,n) for(int i=(a); i >= (n); i--)
#define all(x) x.begin(),x.end()
#define lb lower_bound
#define IO ios_base::sync_with_stdio(0);
#define CIO cin.tie(0);
#define COI cout.tie(0);
#define IOS IO CIO COI

string z, a="", cantik="OSNP";
int o,s,n,p,cntp;
void solve(){
    cin >> z;
    for(auto i:z){
        for(auto j:cantik){
            if(i==j){
                a+=i;
                if(i=='P') cntp++;
            }
        }
    }
    int ans=-1;
    for(auto i:a){
        if(i=='O')o++;
        else if(i=='S')s++;
        else if(i=='N') n++;
        else{
            p++;
            if(o>0 && s>0 && n>0){
                int x = o+s+n+cntp-p+1;
                ans = max(ans, x);
            }
        }
    }
    cout << ans;
}
 
signed main(){
    IOS
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}