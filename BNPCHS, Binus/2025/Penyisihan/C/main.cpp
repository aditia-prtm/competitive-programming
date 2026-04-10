#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;

int n, l[N], r[N], green;
map<int, int>le, ri, all, ans;
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> l[i] >> r[i];
        le[l[i]]++; ri[r[i]+1]++;
    }
    for(auto i:le) all[i.first]++;
    for(auto i:ri) all[i.first]++;
    for(auto i:all){
        green += le[i.first] - ri[i.first];
        if(ans[green] == 0) ans[green] = i.first; 
    }
    for(int i=1; i<=n; i++) cout << (ans[i]==0 ? -1 : ans[i]) << ' ';
}