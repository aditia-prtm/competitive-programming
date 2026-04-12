#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
char g[205][205];
int n, m;
string s, tt, t;
map<char, vector<pair<int, int>>>mp;
vector<pair<int, int>>cnt1, cnt2;

void f(int x, int y, int digit){
   // cout << digit << ' ' << x << ' ' << y << endl;
    if(digit == s.length() - 1){
        cnt1.push_back({x, y});
    }else{
        for(int i = 0; i < mp[s[digit + 1]].size(); i++){
            int a = mp[s[digit + 1]][i].F, b = mp[s[digit + 1]][i].S;
            if((x == a and abs(y - b) == 1) or (y == b and abs(a - x) == 1)){
                f(a, b, digit + 1);
            }
        }
    }
}

void ff(int p, int q, int x, int y, int digit){
   // cout << digit << ' '  << p << ' ' << q << ' ' << x << ' ' << y << endl;
    if(digit == t.length() - 1){
        cnt2.push_back({p, q});
    }else{
        for(int i = 0; i < mp[t[digit + 1]].size(); i++){
            int a = mp[t[digit + 1]][i].F, b = mp[t[digit + 1]][i].S;
            if((x == a and abs (y - b) == 1) or (y == b and abs(a - x) == 1)){
                ff(p, q, a, b, digit + 1);
            }
        }
    }
}

int main(){
    string gaguna; cin >> gaguna;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> g[i][j];
            mp[g[i][j]].push_back({i, j});
        }
    }
    cin >> s >> tt;
    int buang = 0;
    for(int i = 0; i < min(s.length(), tt.length()); i++){
        int idx = 0;
        for(int j = i; j < min(s.length(), tt.length()); j++){
            if(s[j] != tt[idx]) break;
            idx++;
        }
        buang = max(buang, idx);
    }
    string v;
    for(int i = buang; i < tt.length(); i++){
        v += tt[i];
    }
    
    int vx = 0;
    while(s[s.length() - 1] == v[vx] and vx != v.length()){
        vx++;
    }
    for(int i = vx; i < v.length(); i++){
        t += v[i];
    }
    for(int i = 0; i < vx; i++){
        s += v[i];
    }
  //  cout << s << ' ' << t << endl;
    for(int i = 0; i < mp[s[0]].size(); i++){
        f(mp[s[0]][i].F, mp[s[0]][i].S, 0);
    }
    
    for(int i = 0; i < mp[t[0]].size(); i++){
        ff(mp[t[0]][i].F, mp[t[0]][i].S, mp[t[0]][i].F, mp[t[0]][i].S, 0);
    }
    if(t.length() == 0){
        if(cnt1.size() == 0){
            cout << -1;
        }else{
            cout << s.size();
        } return 0;
    }
    if(cnt1.size() == 0 or cnt2.size() == 0){
        cout << -1; return 0;
    }
    int ans = 1e9+7;
    for(auto i : cnt1){
        for(auto j : cnt2){
            ans = min(ans, abs(i.F - j.F) + abs(i.S - j.S));
        }
    }
    cout << ans - 1 + s.length() + t.length();
}

/*
0.......89
5 5
ampeo
kosms
acnka
caboc
cadyx
osn nso

1 5 
2 2 
4 4 

2 3 
2 5

3 3 

2 1 
3 4 

1 5 
2 2 
4 4 

0..3....89
3 3
aba
aab
bab
ab
bb
*/
