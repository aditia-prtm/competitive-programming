#include <bits/stdc++.h> 
using namespace std;
#define int long long
#define pb push_back 
#define all(x) x.begin(), x.end() 
#define F first
#define S second 
const int MOD = 1e9+7, N = 3e5+5, MAXN = 1e6;

int cellin(int a, int b){
    int x = a / b;
    if(x*b != a) x++; 
    return x;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d; cin >> a >> b >> c >> d;
    int ans = 0;
    if(a > 0){
        if(b > 0){
            ans = cellin(a,3);
            if(c > 0){
                ans = ans + cellin(b+c,3) + cellin(d,3);
            }else{
                ans = ans + cellin(b+d,3);
            }
        }else if(c > 0){
            ans = cellin(a+c,3) + cellin(d,3);
        }else{
            ans = cellin(a+d,3);
        }
    }else if(b > 0){
        if(c > 0){
            ans = ans + cellin(b+c,3) + cellin(d,3);
        }else{
            ans = ans + cellin(b+d,3);
        }
    }else ans = cellin(c,3) + cellin(d,3);

    cout << ans;
    
}
/*
a -> c d 
b-> c d 
c-> a b 
d-> a b 

0 0 

*/