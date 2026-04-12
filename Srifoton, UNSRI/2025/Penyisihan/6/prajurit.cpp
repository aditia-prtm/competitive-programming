#include<bits/stdc++.h>
using namespace std;
#define int long long 

int n, arr[1005];
signed main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];

    int ans = 0;
    for(int i = 1; i <= n-2; i++){
        for(int j = i+1; j <= n-1; j++){
            for(int k = j+1; k <= n; k++){
                if(arr[i] < arr[j] && arr[j] < arr[k]) ans++;
                else if(arr[i] > arr[j] && arr[j] > arr[k]) ans++;
            }
        }
    }
    cout << ans;
}