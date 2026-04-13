// ________________________________________________
//
// created by: A_doubleP -- SMAN 1 JEJAWI(KISMIN)
// ________________________________________________

#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>
#include<array>
#include<bitset>
#include<cassert>
#include<chrono>
#include<climits>
#include<complex>
#include<cstring>
#include<queue>
#include<numeric>
#include<map>
#include<set>
#include<random>
#include<functional>
using namespace std;

#define LL long long
#define FPB __gcd
#define DB double
#define ULL unsigned long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define str string
#define vint vector<int>
#define vll vector<long long>
#define pint pair<int,int>    
#define pll pair<long long,long long>
#define pinl pair<int,long long>
#define plin pair<long long,int>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define fi first
#define se second
#define up upper_bound
#define lb lower_bound
#define bye return 0;
#define byee exit(0);
#define loop(i,a,b) for(int i=(a);i<(b);i++)
#define loops(i,a,b) for(int i=(a);i<=(b);i++)
#define liip(i,a,b) for(int i=(a);i>b;i--)
#define liips(i,a,b) for(int i=(a);i>=b;i--)

const LL cuy = 998244353;
const LL MM = 1e6;
const LL MOD = 1e9+7;
const LL INF = 1e18;

int main(){
        fast
        vint v;
        int n,x;
        int I,J;cin>>I>>J;
        
        cin>>n;
        while(I--){
                cin>>x;
                v.pb(x);
        }
        while(J--){
                cin>>x;
                v.pb(x);
        }
        sort(v.begin(),v.end());
        cout<<v[n-1];
        exit(0);
}