#include<bits/stdc++.h>
using namespace std;
#define F first 
#define S second 
#define ll long long

int main(){
    pair<ll, pair<ll, ll>>p [200010];
    ll n, x; cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> p[i].S.F;
    for(int i = 1; i <= n; i++){
        cin >> p[i].S.S; p[i].F = p[i].S.F - p[i].S.S;
    }
    sort(p + 1, p + n + 1);
    ll minim = 0, idx = n, maks = 0;
    for(int i = 1; i <= n; i++){
        if(i <= x){
            minim += p[i].S.F;
            maks += p[idx].S.F;
        }else{
            minim += (min(p[i].S.F, p[i].S.S));
            maks += (max(p[idx].S.F, p[idx].S.S));
        }
        idx--;
   //     cout << maks << ' ' << minim << endl;
    }
  //  cout << maks << ' ' << minim << endl;
    cout << maks - minim << endl;

}