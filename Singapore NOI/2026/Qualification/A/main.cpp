#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define F first 
#define S second 

int n, a[200005];
signed main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);

    cout << a[n] * a[n-1];
}

/*

*/