#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll 
#define pb push_back
#define vec vector<int>
#define pii pair<int, int>
#define all(v) v.begin(), v.end() 
#define lb lower_bound
#define fi first 
#define se second 
#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

int sd, td, ls, lt, n, sp, tp;
pii p[100069];

int binser(int x, int y){
    int l = 0, r = 1e5+10, need = -1;
    while(l <= r){
        int m = (l+r)/2; 
        int dengklek = x / (td+(m*lt)); if(x%(td+(m*lt)) != 0) dengklek++; 
        int monster = (sd+(m*ls)) / y; if((sd+(m*ls))%y != 0) monster++; 
        if(dengklek > monster) l = m+1; 
        else{ 
            need = m; r = m-1; 
        }
    } 
    return need;
}
signed main(){
    io
    string s; cin >> s; 
    cin >> sd >> td >> ls >> lt >> n; 
    cin >> sp >> tp;
    int kill = binser(sp, tp); 
    if(kill == -1){ 
        cout << -1;
        return 0; 
    }
    vector<pii>v;
    for(int i = 2; i <= n; i++){
        int si, ti; cin >> si >> ti; 
        int perlu = binser(si, ti);
        if(perlu != -1) v.pb({perlu, i});
    }
    sort(all(v)); 
    int done = 0;
    for(auto i : v){
        if(i.fi <= done) done++;
        else break;
    }
    if(done >= kill){
        cout << kill << endl;
        for(int i = 0; i < kill; i++) cout << v[i].se << endl;
    }else cout << -1;
}