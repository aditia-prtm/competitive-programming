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

int32_t main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); cout.tie(0);
    int t = 1; 
    cin >> t; 
    while(t--){ 
        int n, sum = 0; cin >> n; 
        for(int i = 1; i < n; i++){
            int a; cin >> a; sum += a;
        }
        cout << -sum << endl;
    }
}
