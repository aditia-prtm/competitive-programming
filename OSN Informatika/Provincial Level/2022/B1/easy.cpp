#include<bits/stdc++.h>
using namespace std;

long long p, q, r;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> p >> q >> r;
    int n; cin >> n;
    while(n--){
        long long l; cin >> l;
        if((l % p)+ (l % q )+ (l % r) == 0) cout << "YA\n";
        else cout << "TIDAK\n";
    }
}