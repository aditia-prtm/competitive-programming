#include<cstdio>
#include<cmath>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long

ll n, a[100005], MAX = 1000000007;
void solve(){
    scanf("%lld", &n);
    map<ll, vector<ll>>cnt; 
    for(ll i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        cnt[a[i]].push_back(i);
    }
    ll ans = 0, sum;
    for(auto i : cnt){
        sum = 0;
        for(ll j = 0; j < cnt[i.first].size(); j++){
            ans = (ans + cnt[i.first][j]*j - sum - j)%MAX;
            sum += cnt[i.first][j]; 
        }
    }
    printf("%lld \n", ans);
}

int main(){
    int t = 1; 
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        printf("Case #"); printf("%d", i);
        printf(": ");
        solve();
    }
}