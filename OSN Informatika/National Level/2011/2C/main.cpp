#include<bits/stdc++.h>
using namespace std; 
#define int long long 
#define pb push_back
#define all(x) x.begin(), x.end()
#define lb lower_bound

int n, m, pre[1000005];
vector<int>k;
bool b[1000005];
int32_t main(){
    cin >> n >> m; 
    for(int i = 1; i <= n; i++){
        int x; cin >> x; k.pb(x);
        b[x] = 1;
    }
    sort(all(k));
    for(int i = 0; i < n; i++){
        pre[i] = k[i];
        if(i>0) pre[i]+=pre[i-1];
    //    cout << pre[i] << ' ';
    }
//    cout << endl;
    int ans = -1, anss = -1;
    for(int i = 1; i <= m; i++){
        if(b[i])continue;
    //    cout << i << "-> ";
        int tmp = 0;
        // <= i
        int l = (lb(all(k), i+1)-k.begin()), L;
        if(l!=0){
            L = l-1;
            tmp = i*l - pre[L];
        //    cout << l << ',' <<  i*l - pre[L];
        }
    //    cout << " - ";
        // > i
        int r = n-l, R;
        if(r!=n+1){
            R = l;
            tmp += ((pre[n-1]-pre[R-1])-i*r);
        //    cout << r << ',' << (pre[n-1]-pre[R-1])-i*r;
        }
    //    cout << endl;
        if(tmp>ans){
            ans = tmp; 
            anss = i;
        }
    }
    cout << anss;
}
/*
4 7
4 1 4 7

1 4 4 7 

2-> = 1+9 = 10
3-> 
6

1 15 
2*1 - 1 
15 - 2*3 
*/