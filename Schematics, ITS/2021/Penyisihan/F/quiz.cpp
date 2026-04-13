#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define lb lower_bound
#define F first
#define S second
const int MOD = 1000000007;
vector<int>arr;
int n, s, digit[15];
map<int, int>mp;
void perm(int d){
    if(d > n){
        int sum = 0;
        for(int i=0; i<n; i++){
            cout << arr[i] << ' ';
            digit[i+1] += arr[i];
            sum += arr[i];
        }
        cout << ": " << sum << endl;
        mp[sum]++;
    }else{
        for(int i=1; i<=s; i++){
            arr.pb(i);
            perm(d+1);
            arr.pop_back();
        }
    }
}
signed main(){
    cin >> n >> s;
    // perm(1);
    // for(int i=1; i<=n; i++){
    //     cout << "digit " << i << ": " << digit[i] << endl;
    // }
    // int ans = 0;
    // for(auto i:mp){
    //     ans += i.first;
    //     cout << i.first << ' ' << i.second << endl;
    // }
    // cout << ans;

    n%=MOD; s%=MOD;
    int ns = n*s; ns %= MOD;
    int x = ns*(ns+1)/2; x %= MOD;
    int y = n*(n-1)/2; y %= MOD;
    cout << (x-y+MOD)%MOD;
}
/*
N S
S = 5   
1, 2, 3, 4, 5. 
N = 3 

*/