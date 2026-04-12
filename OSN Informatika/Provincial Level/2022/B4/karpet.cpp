#include<bits/stdc++.h>
using namespace std;

int n, m;
long long dp[100005], mod = 1000000007;
int main(){
    cin >> n >> m;
    dp[1] = 2;
    for(int i = 2; i <= m; i++){
        dp[i] = 3 * dp[i - 1]; dp[i] %= mod;
    }
    cout << dp[m];
}