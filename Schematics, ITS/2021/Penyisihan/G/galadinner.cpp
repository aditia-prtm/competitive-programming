#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first 
#define S second
map<ll, bool>mp;
ll n, m;
pair<ll, ll>p[1005];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x, y; cin >> x >> y;
        p[i].F = y; p[i].S = x;
    }
    sort(p + 1, p + n + 1);
    ll sum = 0;
    vector<ll>cnt;
    for(int i = 1; i <= n; i++){
        if(!mp[p[i].S]){
            mp[p[i].S] = true;
            cnt.push_back(p[i].F);
        }else{
            sum += p[i].F;
        }
    }
    ll ans = 0;
    for(int i = 0; i < cnt.size(); i++){
        ans += ((i + 1) * cnt[i]);
    }
    if(ans + (sum * cnt.size()) >= m) cout << "YA";
    else cout << "TIDAK";
}