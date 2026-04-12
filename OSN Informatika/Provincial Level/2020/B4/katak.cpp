#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int n, y[100005];
ll dp[100005];

ll f(int a, int b){
    return (a - b) * (a - b);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> y[i];
    for(int i = 2; i <= n; i++){
        dp[i] = 1e18;
        dp[i] = min(dp[i], dp[i - 1] + f(y[i - 1], y[i]));
        if(i > 2) dp[i] = min(dp[i], dp[i - 2] + (3 * f(y[i - 2], y[i])));
        if(i > 1 && i < n) dp[i] = min(dp[i], dp[i - 1] + (3 * f(y[i - 1], y[i + 1])) + (f(y[i], y[i + 1])));
    }
    cout << dp[n];
}
/*
5
3 4 6 2 5

5 
1 2 3 4 5
1 -> 0 
2 -> (1), 31
3 -> (5), 27, 29
4 -> (13), 21, 17 
5 -> 8, 22
*/