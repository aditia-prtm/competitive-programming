#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second 

signed main(){
    int n; cin >> n;
    int sum = 0;
    while(n--){
        int x; cin >> x;
        sum += x;
        sum %= 1000000007;
    }
    sum = (2*sum) % 1000000007;
    cout << sum;
}