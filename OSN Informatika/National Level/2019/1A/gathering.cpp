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

int n, m, p;
void solve(){
    cin >> n >> m;
    // read(n); read(m);
    char c[n+5][m+5]; 
    int pref[n+5][m+5];
    memset(pref, 0, sizeof(pref));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            pref[i][j] = 0;
            cin >> c[i][j];
            if(c[i][j] == '1'){
                p++; pref[i][j]++;
            }
            if(j > 1) pref[i][j] += pref[i][j-1];
        }
    }
    for(int j = 1; j <= m; j++){
        for(int i = 2; i <= n; i++){
            pref[i][j] += pref[i-1][j];
        }
    }
    
    int ans = 1e18;
    for(int f = 1; f <= sqrt(p); f++){
        if(p%f == 0){
            if(f <= n && p/f <= m){
                for(int k = 1; k <= n-f+1; k++){
                    for(int kk = 1; kk <= m-(p/f)+1; kk++){
                        int tmp = pref[k+f-1][kk+(p/f)-1];
                        tmp -= pref[k-1][kk+(p/f)-1]; 
                        tmp -= (pref[k+f-1][kk-1] - pref[k-1][kk-1]);
                        ans = min(ans, p-tmp);
                    }
                }
            }
            
            if(p/f <= n && f <= m){
                for(int k = 1; k <= n-(p/f)+1; k++){
                    for(int kk = 1; kk <= m-f+1; kk++){
                        int tmp = pref[k+(p/f)-1][kk+f-1];
                        tmp -= pref[k-1][kk+f-1];
                        tmp -= (pref[k+(p/f)-1][kk-1] - pref[k-1][kk-1]);
                        ans = min(ans, p-tmp);
                    }
                }
            }
        }
    }
    if(ans == 1e18) printf("-1");
    else print(ans);
}
int32_t main(){
    IO
    int t = 1; 
//    t = read();
    while(t--) solve();
}