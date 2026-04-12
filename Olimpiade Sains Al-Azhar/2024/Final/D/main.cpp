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

int n, m, a[305][305], b[305][305];
char c[305][305];
int32_t main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> c[i][j];
    }
    for(int i = 2; i <= n; i++){ a[i][0] = b[i][0] = 1e9+7;}
    for(int i = 2; i <= m; i++){ a[0][i] = b[0][i] = 1e9+7;}
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(c[i][j] == '#'){ a[i][j] = b[i][j] = 1e9+7;}
            else{
                a[i][j] = min(a[i][j - 1], b[i - 1][j] + 1);
                b[i][j] = min(b[i - 1][j], a[i][j - 1] + 1);
            } 
        }
    }
    cout << min(a[n][m], b[n][m]);
}
