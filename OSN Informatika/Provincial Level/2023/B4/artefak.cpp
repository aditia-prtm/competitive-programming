#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define int ll
#define ull unsigned long long
#define db double
#define ld long double
#define pii pair<int,int>    
#define pll pair<ll, ll>
#define ppii pair<pii, int>
#define pipi pair<int, pii>
#define ppipi pair<pii, pii>
#define vec vector<int>
#define vecpii vector<pii>
#define vecpsi vector<pair<string, int>>
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

const ll MODD = 998244353;
const ll MOD = 1e9+7;
const ll INF = 1e18;
const ld PI = acos(-1.0);

int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};

void read(int &num){
    bool neg = 0; register int c; num = 0; c = getchar();
    if(c=='-'){ neg = 1; c = getchar();}
    for(;(c>47 && c<58); c = getchar()) num = num*10+c-48;
    if(neg) num *= -1;
}
void print(int x) {
    if (x < 0) putchar('-'),x-=x;
    if(x<10) putchar(x + 48);
    else print(x/10),putchar(x%10+48);
}
void print(int x, char t) {
    print(x); putchar(t);
}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
ll n, k, x, a[100005], b[100005], mid = 0;
vector<ll>aleft, aright, bleft, bright;
void solve(){
    read(n); read(k); read(x);
    for(int i = 1; i <= n; i++){
        read(a[i]);
        if(a[i] < x) mid++;
        a[i] = abs(a[i] - x);
    }
    ll kn = 0, kr = 0, ans = 0;
    for(int i = 1; i <= n; i++){
        read(b[i]);
        if(i > mid){
            kn += b[i]; 
            aright.pb(a[i]); bright.pb(kn);
        }
    }
    if(n == 1 and a[1] == 0){
        print(b[1]);
        exit(0);
    }
    for(int i = mid; i >= 1; i--){
        kr += b[i];
        aleft.pb(a[i]); bleft.pb(kr);
        if(k >= a[i]){
            ans = max(ans, kr);
            ll tmp = k - 2 * a[i], res = 0;
            if(tmp > 0){
                res = lower_bound(aright.begin(), aright.end(), tmp + 1) - aright.begin();
                ans = max(ans, kr + bright[res - 1]);
            }
        }
    }
    for(int i = 0; i < aright.size(); i++){
        if(k >= aright[i]){
            ans = max(ans, bright[i]);
            ll tmp = k - 2 * aright[i], res = 0;
            if(tmp > 0){
                res = lower_bound(aleft.begin(), aleft.end(), tmp + 1) - aleft.begin();
                ans = max(ans, bright[i] + bleft[res - 1]);
            }
        }else break;
    }
    print(ans);
}

int32_t main(){
    IO
    int t = 1; 
//    t = read();
    while(t--) solve();
}

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* 




*/
