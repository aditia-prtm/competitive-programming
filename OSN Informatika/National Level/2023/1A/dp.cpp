#include<bits/stdc++.h>
using namespace std;

int n, zone[200005], mx[200005] = {0};
int main(){ 
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> zone[i];
    
    int dp[200005] = {0};
    for(int day = 1; day <= n; day++){
        if(day - zone[day] >= 0){
            mx[day - zone[day]] ++;
            dp[day] = max(dp[day], dp[day - zone[day]] + mx[day - zone[day]]);
        }
        dp[day] = max(dp[day], dp[day-1]);
        //cout << day << ' ' << dp[day] << endl;
    }
    cout << n - dp[n];
}
/*
5 
2 2 3 2 1 

0 0 0 0 0 
  0 0 0 0 
    0 0 0 
*/