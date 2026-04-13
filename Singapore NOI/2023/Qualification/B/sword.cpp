#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n; pair<ll, ll>p[100010];
int main(){
	 ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> p[i].first >> p[i].second;
    
    sort(p + 1, p + n + 1);
    
    ll ans = n, maks = 0;
    for(ll i = n; i >= 1; i--){
        if(p[i].second <= maks) ans--;
        maks = max(maks, p[i].second);
    }
    cout << ans;
}
/*
6
5 6 
5 5 
6 9 
1 3 
10 12 
5 7 

7
1 3 
5 6 
5 5 
5 7
6 9
9 13
10 12


*/