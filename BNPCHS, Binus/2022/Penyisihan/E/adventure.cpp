#include<bits/stdc++.h>
using namespace std;
#define F first 
#define S second 

int n, u, a[1010], b[1010], x[1010];
pair<int, int>dp [1010];

int main(){
    cin >> n >> u;
   // int p = 100000:
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i] >> x[i];
       // p = min(p, a[i]);
    }
    dp[0] = {0, 0};
    for(int i = 1; i <= u; i++){
        dp[i] = {0, i};
        for(int j = 1; j <= n; j++){
            if(i - a[j] >= 0){
                dp[i] = max(dp[i], {dp[i - a[j] + b[j]].F + x[j], dp[i - a[j] + b[j]].S});
            }
            
        }
        //cout << i << ' ' << dp[i] << endl;
    }
    cout << dp[u].F << ' ' << dp[u].S << endl;
    
}