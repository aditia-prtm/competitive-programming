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
    int n, m, q; cin >> n >> m >> q; 
    int baris_tertanam = 0, kolom_tertanam = 0; 
    map<int, bool>fullbaris, fullkolom;
    while(q--){
        int x, y; cin >> x >> y;
        int ans = 0;
        if(!fullbaris[x]){
            fullbaris[x] = 1; 
            ans = (m - kolom_tertanam);
            baris_tertanam++;
        }
        if(!fullkolom[y]){
            fullkolom[y] = 1; 
            ans += (n - baris_tertanam);
            kolom_tertanam++;
        }
        cout << ans << endl;
    }
}