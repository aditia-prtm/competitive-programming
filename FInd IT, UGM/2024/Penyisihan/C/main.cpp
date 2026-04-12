#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#define int long long
#define ll long long
#define fpb __gcd
#define db double
#define ull unsigned long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define str string
#define vint vector<int>
#define vll vector<long long>
#define pii pair<int,int>    
#define pll pair<long long,long long>
#define mkp make_pair
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define F first
#define S second
#define ub upper_bound
#define lb lower_bound
#define debug cerr<<"-> ";
#define all(x) (x).begin(),(x).end()
#define endl '\n'
#define rep(i ,a ,b) for(int i = (a); i < (b);i++)
#define repz(i, a ,b) for(int i = (a); i <= (b);i++)
#define repd(i, a, b) for(int i = (a); i > (b); i--)
#define repdz(i, a, b) for(int i = (a); i >= b; i--)
const ll MOD = 998244353;
const ll MAX = 1e9+7;
const ll INF = 1e18;
const ld PI = acos(-1.0);

// ---------------------------------------------------------------------------
	
ll n, r, k, b[200005], ans = 0;
void solve(){
    cin >> n >> r >> k;
    repz(i, 1, n) cin >> b[i];
    repz(i, 1, n){
        int x; cin >> x; ans += (b[i] * x / 100);
    }
    if(ans >= r) cout << "PASS";
    else cout << "NOT PASS";
}

int32_t main(){
	fastio
    int t = 1; 
//    cin >> t;
    while(t--) solve();
    return 0;
}

/*
4 200 1000
100 200 300 400
40 30 20 10
*/
	
// ---------------------------------------------------------------------------

/* Kesalahan - kesalahan fatal pas osp 2024 kemarin :
* terlalu lama blank di soal A 
* gabisa manage waktu
* terlalu fokus mencari solusi full, ga nguli subtask 1 dulu
* ga teliti karna di problem C lupa pake long long
* pokonya knp aku kemarin tolol bgt
* alhasil cuma dapet kulian subtask 1 dari soal A dan B
* dan yang C gatau dapet apa (mungkin subtask 1 karna masih muat di int)
* waktu hampir habis baru mau brute force soal E buat dapetin subtask 1
* dan akhirnya ga sempet haha 
* compilernya juga tolol itu masa gabisa pake vector + array
* pokonya lebih goblok ini daripada tahun lalu 
* intinya kecerobohanku membuat aku jatuh 2 kali di lobang yang sama (gagal osp 2 kali)
* gagal karna kesalahan kaya gini lebih sakit daripada gagal karna emang gatau apa-apa
* penyesalan memang selalu datang di akhir 

Kalo aku ga lolos ke osn, harus tetap nge cp
karna ini awal mula aku masuk ke dunia informatika
dan masih banyak jalan lain selain dari osn walau osn lah yang paling ku impikan
gaboleh down terlalu lama, harus segera cari resolusi positif
bismillah, rencana allah mungkin lebih dari ini
fokus perbaiki diri, belajar dari kesalahan, supaya diri ini jadi lebih baik
mulailah untuk mempelajari hal - hal baru 
karna tidak ada kata terlambat untuk belajar
*/
