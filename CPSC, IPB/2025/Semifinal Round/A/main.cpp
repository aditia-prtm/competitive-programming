#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
const int N = 2e5+5;

int n, k, arr[5000005];
signed main(){
    cin >> n >> k;
    n *= 2; k %= n;

    for(int i=1; i<=n; i++){
        if(i%2 == 1) arr[i] = i;
        else arr[i] = n - i + 2;

        arr[n+i] = arr[i];
    }

    for(int i = n-k+1; i <= n-k+n; i++) cout << arr[i] << ' ';
}