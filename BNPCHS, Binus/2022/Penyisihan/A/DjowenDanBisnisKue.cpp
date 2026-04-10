#include<bits/stdc++.h>
using namespace std;
#define F first 
#define S second 
#define ll long long

int meja[1010] = {0};
int main(){
   int n, m, ans = 0; cin >> n >> m;
   
   for(int i = 1; i <= m; i++){
       int x; cin >> x; meja[x] ++;
   }
   for(int i = 1; i <= n; i++){
       if(meja[i] % 4 == 2 || meja[i] % 4 == 3){
           ans++;
       }
   }
   cout << ans;
}
