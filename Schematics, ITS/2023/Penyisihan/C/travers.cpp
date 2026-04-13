#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ambatukaam ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// buta dikit ga ngaruh
char g[1005][1005];
ll n, m, y, step[1005][1005];
bool vis[1005][1005];

void f(ll x, ll y){
    if(g[x][y] == 'U' && x != 1){
        if(vis[x - 1][y]){
            cout << 1 << ' ' << step[x - 1][y] - 1 << ' ' << 0 << ' ' << step[x][y] - step[x - 1][y] + 1 << endl;
            //exit(1);
        }else{
            vis[x - 1][y] = 1;
            step[x - 1][y] = step[x][y] + 1;
            f(x - 1, y);
        }
    }else if(g[x][y] == 'S' && x != n){
        if(vis[x + 1][y]){
            cout << 1 << ' ' << step[x + 1][y] - 1 << ' ' << 0 << ' ' << step[x][y] - step[x + 1][y] + 1 << endl;
         //   exit(1);
        }else{
            vis[x + 1][y] = 1; 
            step[x + 1][y] = step[x][y] + 1;
            f(x + 1, y);
        }
    }else if(g[x][y] == 'T' && y != m){
        if(vis[x][y + 1]){
            cout << 1 << ' ' << step[x][y + 1] - 1 << ' ' << 0 << ' ' << step[x][y] - step[x][y + 1] + 1 << endl;
          //  exit(1);
        }else{
            vis[x][y + 1] = 1;
            step[x][y + 1] = step[x][y] + 1;
            f(x, y + 1);
        }
    }else if(g[x][y] == 'B' && y != 1){
        if(vis[x][y - 1]){
            cout << 1 << ' ' << step[x][y - 1] - 1 << ' ' << 0 << ' ' << step[x][y] - step[x][y - 1] + 1 << endl;
          //  exit(1);
        }else{
            vis[x][y - 1] = 1;
            step[x][y - 1] = step[x][y] + 1;
            f(x, y - 1);
        }
    }else{
        cout << 1 << ' ' << step[x][y] << endl;
       // exit(1);
    }
}

int main(){
    ambatukaam
    while(cin >> n >> m >> y){
        if(n + m + y == 0) return 0;
        memset(step, 0, sizeof(step));
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++) cin >> g[i][j];
        }
        step[1][y] = vis[1][y] = 1;
        f(1, y);
    }
}

/*
4 5 1
STSBT
TTSUB
UBTTU
TBSTU

S SB
TTSUB
  TTU

3 6 5
UTTSBT
BBBTSS
SUBBBB
4 5 1
STSBT
TTSUB
UBTTU
TBSTU
0 0 0
*/