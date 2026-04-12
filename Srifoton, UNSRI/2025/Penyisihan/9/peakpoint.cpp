#include<bits/stdc++.h>
using namespace std;
#define int long long 

int n, arr[100005];
signed main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> arr[i];
    
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(i == 1 && arr[i] > arr[i+1]){
            cout << i << ' ';
            cnt++;
        }
        else if(i == n && arr[i] > arr[i-1]){
            cout << i << ' ';
            cnt++;
        }
        else if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            cout << i << ' ';
            cnt++;
        }
    }
    if(cnt == 0) cout << -1;
}   