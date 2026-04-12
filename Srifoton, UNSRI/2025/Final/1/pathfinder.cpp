#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second 

int n, m, k, dp[1005][1005];
bool dilarang[1005][1005];

signed main(){
    cin >> n >> m >> k;
    while(k--){
        int x, y; cin >> x >> y;
        dilarang[x][y] = 1;
    }
    dp[0][0] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dilarang[i][j]) continue;
            dp[2*i][2*j] = (dp[2*i][2*j] + dp[i][j]) % 1000000007;
            dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % 1000000007;
            dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % 1000000007;
        }
    }
    if(dilarang[n-1][m-1]) dp[n-1][m-1] = 0;
    cout << dp[n-1][m-1];

}