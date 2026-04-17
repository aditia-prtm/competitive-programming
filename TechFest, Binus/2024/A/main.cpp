#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, a[100005];
int32_t main(){
    cin >> n >> a[1];
    int stin = 1, ans = 0;
    for(int i = 2; i <= n; i++){
        cin >> a[i];
        if(a[i-1] < a[i]) stin++;
        else{
            ans += stin*(stin+1)/2;
            stin = 1;
        }
    }
    ans += stin*(stin+1)/2;
    cout << ans;
}