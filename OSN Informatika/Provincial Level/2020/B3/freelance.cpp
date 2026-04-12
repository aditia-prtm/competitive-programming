#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int m, s[10005], e[10005], p[10005], mx;
ll dp[15005];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> s[i] >> e[i] >> p[i];
        mx = max(mx, e[i]);
    }
    for(int i = 1; i <= mx; i++){
        for(int j = 1; j <= m; j++){
            if(e[j] <= i) dp[i] = max(dp[i], p[j] + dp[s[j] - 1]);
        }
      //  cout << i << ' ' << dp[i] << endl;
    }
    cout << dp[mx];
}
/*
6
1 5 1000
1 3 500
4 5 700
6 8 800
6 10 2000
9 10 1500

dp[i] -> berapa max selama i hari

6
1 5 2000
1 3 500
4 5 700
6 8 800
6 10 3000
9 10 1500

1,2 -> 0 
3 -> 500 
4 -> 500 
5 -> 


dp[i] = duit[j] + duit[mulai[j]]


*/