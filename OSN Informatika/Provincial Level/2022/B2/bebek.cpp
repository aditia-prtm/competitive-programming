#include<bits/stdc++.h>
using namespace std;
#define F first //Harga
#define S second //kapasitas
#define int long long

int k, n, b[100005];
pair<int, int>p[1005];
long long ans = 0;
signed main(){
    cin >> k;
    for(int i = 1; i <= k; i++) cin >> p[i].S;
    for(int i = 1; i <= k; i++) cin >> p[i].F;
    
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> b[i];
    sort(p + 1, p + 1 + k);
    sort(b + 1, b + 1 + n, greater<long long>());
  //  for(int i = 1; i <= k; i++) cout << p[i].S << ' ' << p[i].F << endl;
   // cout << endl;
    int cnt = n, idx = 1;
    for(int i = 1; i <= k; i++){
        int tmp = 0;
        if(p[i].S <= cnt){
            cnt -= p[i].S;
            for(int j = idx; j < idx + p[i].S; j++) tmp += b[j];
            ans += p[i].F * tmp;
            //cout << p[i].F << ',' << p[i].S << ' ' << idx << ' ' << tmp << ' ' << cnt << endl;
            idx += p[i].S;
        }else{
            for(int j = idx; j <= n; j++) tmp += b[j];
            ans += p[i].F * tmp;
            cnt = 0;
          //  cout << p[i].F << ',' << p[i].S << ' ' << idx << ' ' << tmp << ' ' << cnt << endl;
            break;
        }
    }
    cout << ans;
}
/*
3
3 4 1 
5 2 1
6
1 2 2 3 4 5

1 2 5 
1 4 3 

*/
