#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
const int N = 2e5+5, INF = 1e18;

int n, a, b, h[100005];
signed main(){
    cin >> n >> a >> b;

    int sum = 0;
    for(int i=1; i<=n; i++){
        cin >> h[i];
        sum += h[i];
    }
    
    sort(h+1, h+n+1, greater<int>());

    int kelompok = n / (a+b);
    for(int i=1; i<=kelompok; i++){
        for(int j = (i-1)*(a+b) + (a+1); j <= (i-1)*(a+b) + (a+b); j++){
            // cout << j << ' ';
            sum -= h[j];
        }
        // cout << endl;
    }
    cout << sum;
}