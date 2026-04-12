#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define int ll
#define ull unsigned long long
#define db double
#define ld long double
#define str string
#define fpb __gcd
#define pii pair<int,int>    
#define pll pair<ll, ll>
#define ipii pair<int, pii>
#define piii pair<int, pii>
#define ppii pair<pii, pii>
#define veci vector<int>
#define vecii vector<pii>
#define vecsi vector<pair<string, int>>
#define mkp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define ins insert 
#define F first
#define S second
#define sz size
#define len length
#define ub upper_bound
#define lb lower_bound
#define bg begin
#define all(x) x.begin(),x.end()
#define pq priority_queue<int>
#define pqr priority_queue<int,vector<int>,greater<int>>
#define endl '\n'

#define debug cerr << "-> "
#define debl cerr << "===================================\n"
#define debc(i,j) cerr << i << ": " << j << endl
#define debpii(i,j,k) cerr << i << ": " << j << ' ' << k << endl
#define deblr(i,j,k) cerr << i << ',' << j << ": " << k << endl
#define debvec(v) for(int i = 0; i < v.sz(); i++) cout << i << ": " << v[i] << endl
#define debarr(a,n) for(int i = 1; i <= n; i++) cout << i << ": " << a[i] << endl

const ll MOD = 998244353;
const ll MAX = 1e9+7;
const ll INF = 1e18;
const ld PI = acos(-1.0);

int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int n, m, k, id, milk, ans;
vector<int>p;
void solve(){
    cin >> n >> m >> k; 
    for(int i = 1; i <= n; i++){
        int a; cin >> a; p.pb(a); 
        sort(all(p));
        id = 1; milk = 0;
        for(auto j : p){
            if(id > i-k) break;
            milk += j;
            id++;
        }
        if(milk <= m) ans = i;
    }
    cout << ans;
}

int32_t main(){
    fastio
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
7 100 2 
70 30 20 40 50 40 10


*/
