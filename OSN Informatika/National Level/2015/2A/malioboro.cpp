#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll 
#define pb push_back
#define vec vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define ipii pair<pii, int>
#define all(v) v.begin(), v.end() 
#define lb lower_bound
#define fi first 
#define se second 
#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

int n, m, k;
vector<int> tabel[1005];
signed main(){
    string s; cin >> s; 
    cin >> m >> n >> k; 
    for(int i = 1; i <= n; i++){
        int a, x; cin >> a >> x; 
        int id = a;
        if(x == 1){
            for(int j = 0; j < m; j++){
                tabel[i].pb(id);
                id++; if(id == m+1) id = 1;
            }
        }else{
            for(int j = 0; j < m; j++){
                tabel[i].pb(id);
                id--; if(id == 0) id = m;
            }
        }
    }

    while(k--){
        int t; cin >> t; t %= m; 
        vector<int>tmp;
        for(int i = 1; i <= n; i++) tmp.pb(tabel[i][t]);
        sort(all(tmp));
        int ans = 1e18;
        for(int i = 1; i < tmp.size(); i++) ans = min(ans, tmp[i]-tmp[i-1]);
        ans = min(ans, (tmp[0]+m)-tmp.back());
        cout << ans << endl;
    }
}  