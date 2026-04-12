#include<bits/stdc++.h>
using namespace std;
#define int long long //tol*llll sumpah bisa lupa pake ll 
//kalah lagi mampus 

int n, m, jml = 0;
vector<int>a;
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x; cin >> x; a.push_back(x); jml += x;
    }
    sort(a.begin(), a.end());
    if(jml < m){
        cout << -1; return 0;
    }
    for(int i = 1; i <= a.back() + 5; i++){
        int tmp = n - (lower_bound(a.begin(), a.end(), i) - a.begin());
        jml -= tmp;
    //    cout << i << ' ' << jml << endl;
        if(jml < m){
            cout << i - 1; return 0;
        }
    }
}
//GOOD BYE OSN:)