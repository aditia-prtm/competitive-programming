#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, h[1005], k[1005], d[1005];
int dp[1005][10005];
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
    	cin >> h[i] >> k[i] >> d[i];
    	for(int j = 1; j <= m; j++){
    		dp[i][j] = dp[i - 1][j];
    		
    		if(h[i] <= j){	
    	    	if(d[i] == 1) dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] + k[i]);
    	    	else dp[i][j] = max(dp[i][j], dp[i][j - h[i]] + k[i]);
        	}
		} 
    }
    cout << dp[n][m];
	
}
/*
2 10
1 2 1
2 1 0
*/