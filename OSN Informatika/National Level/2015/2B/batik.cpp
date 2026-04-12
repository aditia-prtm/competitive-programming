#include<bits/stdc++.h>
using namespace std;
#define W first 
#define C second
#define ll long long
ll n, m;
pair<ll, ll>p[100010];
map<ll, vector<ll>>mp; 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s; cin >> s >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> p[i].C >> p[i].W;
    }
    sort(p + 1, p + n + 1);
    
    ll ans = 0, tmp = 0, idx = 0;
    for(int i = 1; i < n; i++){
        ans += i * (n - i) * (p[i + 1].W - p[i].W);
        mp[p[i].C].push_back(p[i].W);
    }
    mp[p[n].C].push_back(p[n].W);
    for(auto i : mp){
        ll tmp = 0;
        for(int j = 0; j < mp[i.first].size() - 1; j++){
            tmp += (j + 1) * (mp[i.first].size() - j - 1) * (mp[i.first][j + 1] - mp[i.first][j]);
        }
        ans -= tmp;
        //cout << tmp << endl;
    }
    cout << ans;
}
/*
0..3456.8
5 2

1 5
2 3
1 2
2 4
2 6
???????-> jumlahkan selisih semua jenis
          kurngkan dgn selisih setiap jenis yg sama
5 2 = 3
3 4 6 = 1+2+3=6

3+7+


*/