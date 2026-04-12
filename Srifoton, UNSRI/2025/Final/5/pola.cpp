#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[10];
signed main() {
    for(int i=1; i<=8; i++) cin >> a[i];
    cin >> n;

    n = (n - 1) % 14 + 1; // pola berulang tiap 14 hari

    for(int i=1; i<=n; i++){
        int tmp[10];
        tmp[1] = tmp[8] = 0;
        for(int j=2; j<=7; j++){
            tmp[j] = (a[j-1] == a[j+1]);
        }
        for(int i=1; i<=8; i++) a[i] = tmp[i];
    }
    for(int i=1; i<=8; i++) cout << a[i] << ' ';
}
