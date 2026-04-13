#include<bits/stdc++.h>
using namespace std;

vector<int>dp;
int main(){
    int n;cin>>n;
 
    dp.push_back(0);
    for(int i=1;i<=n;i++){
        dp.push_back(max(i,dp[i/2]+dp[i/3]+dp[i/4]));
    }
    cout<<dp[n];
}