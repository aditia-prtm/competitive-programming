#include<bits/stdc++.h>
using namespace std; 
#define int long long 
#define pb push_back
#define all(x) x.begin(), x.end()
#define lb lower_bound

int n, dp[1005];
int32_t main(){
    cin >> n; 
    dp[0] = dp[1] = dp[2] = dp[3] = 1; dp[3]++;
    for(int i = 4; i <= n; i++) dp[i] = (dp[i-1]+dp[i-3])%1000000;
    cout << dp[n];
}