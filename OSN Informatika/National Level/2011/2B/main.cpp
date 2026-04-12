#include<bits/stdc++.h>
using namespace std; 
#define int long long 

int n, f[20];
int32_t main(){
    cin >> n;
    if(n<=2){ cout << 0; return 0;}
    f[0] = 1;
    for(int i = 1; i <= 16; i++) f[i] = i*f[i-1];
    cout << f[n]/(f[n-3]*f[3]);
}