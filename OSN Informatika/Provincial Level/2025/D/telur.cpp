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

int n, k;
string s;
void solve(){
    cin >> n >> k >> s;
    int l = s.length()+1, r = 0;
    for(int i=1; i<=s.length(); i++){
        if(s[i-1]=='A'){
            l = min(i, l);
            r = max(i, r);
        }
    }
    int b = l-1+s.length()-r;
    int segment = 0;
    vector<int>bb;
    bool v=0;
    for(int i=l; i<=r; i++){
        if(s[i-1]=='B'){
            if(!v) v=1;
            segment++;
        }else{
            if(v){
                v=0;
                bb.pb(segment);
                segment=0;
            }
        }
    }
    if(segment>0) bb.pb(segment);
    sort(all(bb));
//    for(auto i:bb) cout << i << ' ';
//    cout << endl;
//    cout << b << endl;
    if(l==s.length()+1 && r==0){
        cout << s.length();
        return;
    }
    int aa = bb.size()+1;
    int sisa = max((int)0,aa-k);
    for(int i=sisa; i<bb.size(); i++){
        b+=bb[i];
    }
    cout << b;
}

signed main(){
    IOS
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
/*
A 5 A 1 A 2 A

BABBBBBAABAABBABBB
a = 4 
k = 3

2 4
1 2 5 6

*/