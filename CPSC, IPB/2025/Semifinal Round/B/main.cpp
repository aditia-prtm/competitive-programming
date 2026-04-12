#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
const int N = 2e5+5;

int n, w, h[105], t[105], dp[100005];
bool used[100005][105];
signed main(){
    cin >> n >> w;
    for(int i=1; i<=n; i++) cin >> h[i] >> t[i];
    
    for(int i=1; i<=w; i++){
        dp[i] = dp[i-1];
        for(int j=1; j<=n; j++) used[i][j] = used[i-1][j];

        for(int j=1; j<=n; j++){
            if(i - h[j] >= 0 && !used[i - h[j]][j] && dp[i] < dp[i - h[j]] + t[j]){
                for(int k=1; k<=n; k++) used[i][k] = used[i - h[j]][k];
                used[i][j] = 1;
                dp[i] = dp[i - h[j]] + t[j];
            }
        }

        // cout << i << ": " << dp[i] << endl;
    }
    cout << dp[w];
}
/*
3 8
3 30
4 50
5 60


*/