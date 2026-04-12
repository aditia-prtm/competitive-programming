#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first 
#define S second 
const int MOD = 1e9+7, N = 3e5+5, MAXN = 1e6;

int n, m;
char c[1005][1005];


int check(int x, int y){
  int res = 0;
  for(int i=-1; i<=1; i++){
    if(c[x+1][y+i] == '#') res++;
    if(c[x-1][y+i] == '#') res++;
  }
  if(c[x][y-1] == '#') res++;
  if(c[x][y+1] == '#') res++;
  
  return res;
}

signed main(){
  cin >> n >> m;

  for(int i=0; i<=n+1; i++) c[i][0] = c[i][m+1] = '0';
  for(int i=0; i<=m+1; i++) c[0][i] = c[n+1][i] = '0';

  for(int i=1; i<=n; i++){
    string s; cin >> s;
    for(int j=1; j<=m; j++){
      c[i][j] = s[j-1];
    }
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(c[i][j] != '#'){
        int num = c[i][j] - '0';
        int cek = check(i, j);
        if(num != cek){
          cout << "SALAH";
          return 0;
        }
      }
    }
  }
  cout << "BENAR";
}
