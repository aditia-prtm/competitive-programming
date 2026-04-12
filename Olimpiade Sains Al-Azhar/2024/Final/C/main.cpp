#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll 
#define pb push_back
#define pii pair<int, int>
#define all(v) v.begin(), v.end() 
#define lb lower_bound
#define F first
#define S second 

int n, k, d, t[100010];
int32_t main(){
    cin >> n >> k >> d; 
    for(int i = 1; i <= n; i++) cin >> t[i]; 
    sort(t+1, t+n+1); 
    for(int i = 1; i <= k; i++) t[i] += d; 
    for(int i = k+1; i <= n; i++){
        if(t[i-k] < t[i]) t[i] += d; 
        else t[i] = t[i-k] + d;
    }
    cout << t[n];
}