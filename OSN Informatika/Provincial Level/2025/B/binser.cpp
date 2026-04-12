#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

bool bisa(ll S, ll N, ll P, ll L){
    return (S/P) * (S/L) >= N;
}

signed main() {
    ll N, P, L;
    cin >> N >> P >> L;

    ll low = 1, high = 2000000000, ans = -1;
    while(low <= high){
    //    cout << low << ' ' << high << ' ';
        ll mid = (low + high) / 2;
    //    cout << mid << endl;
        ll a = mid / P;
        ll b = mid / L;
        if(a == 0 || b == 0) { low = mid + 1; continue; }
        if(a * b >= N){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
}
