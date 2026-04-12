#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define lb lower_bound

int n;
signed main(){
    cin >> n;
    int x; cin >> x;
    for(int i=2; i<=n; i++){
        int y; cin >> y;
        int k = y-x;
    //    cout << i << ": " << k << endl;
        if(!(k==5 || k==10)){
            cout << "NO";
            return 0;
        }
        x = y;
    }
    cout << "YES";
}