#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first 
#define S second 
const int MOD = 1e9+7, N = 3e5+5, MAXN = 1e6;

string xs;
int numv, denv, p, q, llv, rr, kv;
vector<int> ans;

signed main(){
    cin >> xs >> llv >> rr;

    int d = 0;
    string t = "";
    bool dot = false;

    for (char c : xs){
        if (c == '.') { dot = true; continue; }
        t.push_back(c);
        if (dot) d++;
    }

    if (t.empty()) t = "0";
    numv = stoll(t);
    denv = 1;
    for (int i = 0; i < d; i++) denv *= 10;
    int g = __gcd(numv, denv);
    //

    p = numv / g;
    q = denv / g;
    if (p < llv * q || p > rr * q){
        cout << -1;
        return 0;
    }

    kv = q;
    ans.assign(kv, llv);
    int64_t s = p;
    int64_t cur = (int64_t)llv * kv;
    int64_t rem = s - cur;

    for (int i = 0; i < kv && rem > 0; i++){
        int64_t add = min<int64_t>(rem, rr - llv);
        ans[i] += add;
        rem -= add;
    }

    /*
    
    */
    cout << kv << endl;
    for (int i = 0; i < kv; i++){
        //
        if (i) cout << ' ';
        cout << ans[i];
    }
}
