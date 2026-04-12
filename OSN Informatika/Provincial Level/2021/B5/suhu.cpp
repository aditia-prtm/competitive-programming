#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double

db m, a, b, n, q;
vector<pair<db, pair<int, int>>>v;
int main(){
    cin >> n >> m >> a >> b >> q;
    for(db i = 1; i <= n; i++){
        for(db j = 1; j <= m; j++) v.push_back({(b + j) / (a + i), {b + j, a + i}});
    }
    sort(v.begin(), v.end());
    while(q--){
        int l; cin >> l;
        int x = v[l - 1].second.first, y = v[l - 1].second.second; int fpb = __gcd(x, y);
        cout << x / fpb << '/' << y / fpb << endl;
    }
}
/*
3 4 1 5 3
1
6
12
*/