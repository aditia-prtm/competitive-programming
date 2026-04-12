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

int n;
vector<int>a;
map<int, int>mp;
void solve(){ 
    cin >> n;
    int mx=0, idxmx=0;
    int mn=LLONG_MAX, idxmn=0;

    for(int i=1; i<=n; i++){
        int x; cin >> x;
        mp[x]++;
        if(mp[x]==1) a.pb(x);
        if(x>mx){
            mx=x; idxmx=i;
        }
        if(x<mn){
            mn=x; idxmn=i;
        }
    }
    sort(all(a));    
    if(mp.size()==1) cout << "SESUAI";
    else if((mp.size()==2 && (mx-mn)%2==0 && n==2)||(mp.size()==3 && (mx-mn)%2==0 && (mx+mn)/2 == a[1])) cout << (mx-mn)/2 << ' ' << idxmx << ' ' << idxmn;
    else cout << "TIDAK SESUAI";
}
 
signed main(){
    IOS
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
/*

1 3 4 6
*/