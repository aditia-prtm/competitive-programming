#include<bits/stdc++.h>
using namespace std;
#define int long long

int b, c, d;
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >>  b >> c >> d;
    int tmp = c - d, ans = 0;// cout << "-> " << tmp << endl;
    if(c == d && b >= c){
        cout << b - c; return 0;
    }
    for(int i = 1; i <= sqrt(tmp); i++){
        if(tmp % i == 0){
            int j = tmp / i;
            if(c % i == d && i <= b){
                ans++; //cout << i << endl;
            }
            if(c % j == d && j != i && j <= b){
                ans++; //cout << j << endl;
            }
        }
    }
    cout << ans;
    // :")
}