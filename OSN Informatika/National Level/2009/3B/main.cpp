#include<bits/stdc++.h>
using namespace std;

int cnt[3], sz[3], tmp[25], n, m, b[100010], h[3] = {0};

void gnr(int x){
    if(x == m + 1){
        bool check = 1; int idx = 0;
        for(int i = 1; i < m; i++){
            idx += tmp[i];
            if(b[idx] >= b[idx + 1]){
                check = 0; break;
            }
        }
        if(check){
            idx = 0;
            for(int i = 1; i < m; i++){
                idx += tmp[i];
                cout << b[idx] + 1 << ' ';
            }
            exit(0);
        }
    }else{
        for(int i = 1; i <= 2; i++){
            if(h[i] < sz[i]){
                h[i]++;
                tmp[x] = cnt[i];
                gnr(x + 1);
                h[i]--;
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> b[i];
    cin >> m;
    sort(b + 1, b + n + 1);
   /* if(n % m == 0){
        int idx = 0;
        for(int i = 1; i <= n; i++){
            idx += (m / n);
            cout << b[idx] << ' ';
        }
        return 0;
    }*/
    cnt[1] = n / m; cnt[2] = (n / m) + 1;
    sz[1] = m - (n % m); sz[2] = n % m;
    
    gnr(1);
}