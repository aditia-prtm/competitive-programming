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

void solve(){
    vector<int>v;
    int a,b,c; cin >> a >> b >> c;
    v.pb(a); v.pb(b); v.pb(c);
    sort(all(v));

    int ans = 0;
    while(!((v[0]==0 and v[1]==0)or(v[1]==0 and v[2]==0)or(v[2]==0 and v[0]==0))){
        v[2]--; v[1]--;
        sort(all(v));
        ans++;
    }
    cout << ans << endl;
}

signed main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
/*
5
1 1 1
1 2 1
4 1 1
8 5 8
9 4 5

8 8 5

7 7 5
6 6 5
5 5 5
4 4 5 -> 5 4 4
4 3 4 -> 4 4 3 
3 3 3 
2 2 3 -> 3 2 2
2 1 2 -> 2 2 1
1 1 1 
0 0 1 -> 1 0 0
*/