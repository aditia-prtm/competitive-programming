#include<bits/stdc++.h>
using namespace std;
/*
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
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

const int maxn = 1e5+5;
int n, k, a[maxn], b[maxn], h[maxn];
vector<int>le[maxn], ri[maxn];
int facto[maxn];

void solve(){ 
    string s; cin >> s;
    cin >> n >> k;
    for(int i = 1; i <= k; i++) cin >> h[i];
    facto[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        le[h[a[i]]].pb(i);
        facto[i] = (facto[i-1]*i)%MOD;
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        ri[h[b[i]]].pb(i); 
    }
    int ans = 1;
    for(int i = 1; i <= k; i++){
        int leB = lb(all(le[h[i]]), h[i])-le[h[i]].begin(); 
        int leA = le[h[i]].size()-(lb(all(le[h[i]]), h[i]+1)-le[h[i]].begin());
        int leM = le[h[i]].size()-leA-leB;       
        int riB = lb(all(ri[h[i]]), h[i])-ri[h[i]].begin();
        int riA = ri[h[i]].size()-(lb(all(ri[h[i]]), h[i]+1)-ri[h[i]].begin());
        int riM = ri[h[i]].size()-riA-riB;
        
        if(leA == riB && leB == riA && leM + riM == 0){
            ans = (ans*facto[leA])%MOD; 
            ans = (ans*facto[leB])%MOD;
        }else if(leM == 1 && riM == 1){
            if(leA == riB && leB == riA){
                int tmp = (facto[leA]*facto[leB])%MOD; 
                tmp = (tmp*(leA+leB+1))%MOD;
                ans = (ans*tmp)%MOD;
            }else if(abs(leA-riB) == 1 && abs(leB-riA) == 1){
                int tmp = (facto[max(leA,riB)]*facto[max(leB,riA)])%MOD;
                ans = (ans*tmp)%MOD;
            }else{
                print(0);
                exit(0);
            }
        }else if((leM == 1 || riM == 1) && (abs(leA-riB) + abs(riA-leB) == 1)){
            int tmp = (facto[max(leA,riB)]*facto[max(leB,riA)])%MOD;
            ans = (ans*tmp)%MOD;
        }else{
            print(0);
            exit(0);
        }
    }
    print(ans%MOD);
}

int32_t main(){
    IO
    int t = 1; 
//    t = read();
    while(t--) solve();
}
