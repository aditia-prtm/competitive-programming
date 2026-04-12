#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define FOR(i,a,n) for(int i=(a); i <= (n); i++)
#define ROF(i,a,n) for(int i=(a); i >= (n); i--)
#define all(x) x.begin(),x.end()
#define lb lower_bound
#define IO ios_base::sync_with_stdio(0);
#define CIO cin.tie(0);
#define COI cout.tie(0);
#define IOS IO CIO COI

vector<string>ans;
void g(string s, int open, int close, int n) {
    if (s.length() == 2 * n) {
        ans.pb(s);
        return;
    }

    if (open < n) g(s + "(", open + 1, close, n);
    if (close < open) g(s + ")", open, close + 1, n);
}

signed main() {
    int n;
    cin >> n;
    g("", 0, 0, n);
    cout << '[';
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i];
        if(i!=ans.size()-1) cout << ", ";
    }
    cout << ']';
}

/*
1: ()
2: (()), ()()
3: ((())), (()()), (())(), ()(()), ()()()
4: (((()))), ((()())), ((())()), 
*/