#include<bits/stdc++.h>
using namespace std;
#define int long long 

int n, m, a[111][111], pref[111][111] = {0};
signed main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    }
    pref[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] > 0){
                for(int ii = 1; ii <= n; ii++){
                    for(int jj = 1; jj <= m; jj++){
                        if((i != ii or j != jj) && i <= ii && ii <= i + a[i][j] && j <= jj && jj <= j + a[i][j]){
                           // cout << i << ',' << j << " -> " << ii << ',' << jj << endl;
                            pref[ii][jj] += pref[i][j];
                            pref[ii][jj] %= 1000000007;
                        }
                    }
                }
            }
           /* cout << i << ',' << j << endl;
            for(int ii = 1; ii <= n; ii++){
                for(int jj = 1; jj <= m; jj++) cout << pref[ii][jj] << ' ';
                cout << endl;
            }*/
        }
    }
  /*  for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cout << pref[i][j] << ' ';
        cout << endl;
    }*/
    cout << pref[n][m];
}
/*
2 3
2 0 1
1 1 3

1,1 2,1 
1 <= 2 <= 
*/