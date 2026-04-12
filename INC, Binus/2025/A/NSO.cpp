#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first 
#define S second 
const int MOD = 1e9+7, N = 3e5+5, MAXN = 1e6;

int n;
vector<pair<int, pair<int, string> > > v;
signed main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        string s; int a, b, c, d;
        cin >> s >> a >> b >> c >> d;
        v.pb({-1*(a+c), {b+d, s}});
    }
    sort(all(v));
    for(auto i : v){
        cout << i.S.S << endl;
    }
}