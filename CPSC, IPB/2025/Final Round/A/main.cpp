#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first 
#define S second 
const int MOD = 1e9+7, N = 3e5+5, MAXN = 1e6;

signed main(){
  string s; cin >> s;

  char now = s[0];
  cout << now;
  for(int i=1; i < s.length(); i++){
    if(s[i] != now){
      now = s[i];
      cout << now;
    }
  }
}