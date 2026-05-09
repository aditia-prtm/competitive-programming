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

    int idxPemakan = 1;
    for(int i = 1; i < n; i++){
        if(a[i] == -1) continue;

        while(idxPemakan <= n && a[i] >= a[idxPemakan]) idxPemakan++;
        if(idxPemakan > n){
            cout << "NO";
            return 0;
        }

        a[i] = -1;
        a[idxPemakan]++;
        idxPemakan++;
    }
    
    for(int i = 1; i < n; i++){
        if(a[i] != -1){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}

/*

*/