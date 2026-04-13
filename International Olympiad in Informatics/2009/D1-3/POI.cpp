#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define F first 
#define S second 
#define endl '\n' 

int a[2005][2005], poin[2005] = {0}, solved[2005] = {0};
vector<pair<int, pair<int, int>>> v;
int32_t main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    int n, t, p; cin >> n >> t >> p;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= t; j++){
            cin >> a[i][j];
            if(a[i][j]){
                poin[j]++; solved[i]++;
            }
            if(i == n) poin[j] = n - poin[j];
        }
    }
    for(int i = 1; i <= n; i++){
        int pts = 0;
        for(int j = 1; j <= t; j++){
            if(a[i][j]) pts += poin[j];
        }
        v.push_back({pts, {solved[i], n - i + 1}});
    }
    sort(v.begin(), v.end()); reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        if(n - v[i].S.S + 1 == p){
            cout << v[i].F << ' ' << i + 1 << endl;
            return 0;
        }
    }
}