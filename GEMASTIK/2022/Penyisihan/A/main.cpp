#include<bits/stdc++.h>
using namespace std; 
#define int long long 
#define pb push_back 

signed main(){
    int a, b, c, d; cin >> a >> b >> c >> d;

    if(a*d > b*c) cout << "lebih besar";
    else if(a*d < b*c) cout << "lebih kecil";
    else cout << "sama";
}