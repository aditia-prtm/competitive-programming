#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define FOR(i,a,n) for(int i=(a); i <= (n); i++)
#define ROF(i,a,n) for(int i=(a); i >= (n); i--)
#define all(x) x.begin(),x.end()
#define lb lower_bound
#define IO ios_base::sync_with_stdio(0);
#define CIO cin.tie(0);
#define COI cout.tie(0);
#define IOS IO CIO COI

int n, dp[55], mx[55];
vector<int>p;
signed main(){
    while(cin >> n) p.pb(n);
    
    n = p.size();
    if(n==1){
        cout << p[0];
        return 0;
    }

    mx[0] = mx[1] = dp[0] = p[0];
    dp[1] = p[1];
    if(p[1]>mx[1]) mx[1] = p[1];

    for(int i=2; i<n; i++){
        dp[i] = p[i] + mx[i-2];
    //    cout << i+1 << ": " << dp[i] << endl;   
        mx[i] = max(mx[i-1], dp[i]);  
    }
    cout << mx[n-1];
}
/*
1 2 3 1 4 7 1 4 5
1 2 3 4 5 6 7 8 9
1: 1
2: 2
3: 4
4: 3
5: 8
6: 11 
7: 

*/