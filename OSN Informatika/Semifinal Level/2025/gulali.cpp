#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define lb lower_bound

int n,k, a[100005];
vector<int>v;
map<int, int>cnt;
signed main(){  
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    
    for(int i=1; i<=n; i++){
        // cout << a[i] << " -> ";
        int p = 1;
        while(a[i] % 2 == 0){
            p *= 2;
            a[i] /= 2;
        }
        if(cnt[a[i]]==0) v.pb(a[i]);
        cnt[a[i]] += p;
        // cout << a[i] << ' ' << p << endl;
    }
    //  cout << endl;
    sort(all(v), greater<int>());
    //  for(auto i:v) cout << i << ": " << cnt[i] << endl;
    //  cout << endl;

    int eat = 0, ans = 0;
    // cout << v.size() << endl;
    for(auto i:v){
        if(eat+cnt[i] > k){
            ans += i * (k-eat);    
            eat = k;
        }else{
            ans += cnt[i] * i;
            eat += cnt[i];
        }
        // cout << eat << ' ' << ans << endl;
        if(eat == k) break;
    }
    cout << ans;
}