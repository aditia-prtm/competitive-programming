#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define lb lower_bound

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m; if(!(cin>>n>>m)) return 0;
    
    string s; cin >> s;
    int tot = (int)s.size();
    int L = n + m;
    // prefix counts
    vector<int> pref0(tot+1,0), pref1(tot+1,0);
    for(int i=0;i<tot;i++){
        pref0[i+1]=pref0[i]+(s[i]=='0');
        pref1[i+1]=pref1[i]+(s[i]=='1');
    }
    // check all windows of length L
    bool any_window = false;
    bool window_is_prefix = false, window_is_suffix=false;
    for(int i=0;i+L<=tot;i++){
        int z = pref0[i+L]-pref0[i];
        int o = pref1[i+L]-pref1[i];
        if(z==n && o==m){
            any_window = true;
            if(i==0) window_is_prefix = true;
            if(i+L==tot) window_is_suffix = true;
        }
    }
    if(window_is_prefix || window_is_suffix){
        cout << 1;
        return 0;
    }
    if(any_window){
        cout << 2;
        return 0;
    }

    unordered_map<long long, vector<int>> mp;
    mp.reserve(tot*2+10);

    auto key = [&](int z,int o)->long long{
        return ( (long long)z << 32 ) ^ (unsigned long long)o;
    };
    
    for(int j=0;j<tot;j++){
        int z = pref0[tot]-pref0[j];
        int o = pref1[tot]-pref1[j];
        mp[key(z,o)].pb(j);
    }
    for(auto &kv: mp) sort(kv.second.begin(), kv.second.end());

    for(int i=0;i<=tot;i++){
        int pz = pref0[i];
        int po = pref1[i];
        int needz = n - pz;
        int needo = m - po;
        if(needz < 0 || needo < 0) continue;
        long long k = key(needz, needo);
        if(mp.find(k)==mp.end()) continue;
        auto &vec = mp[k];
        auto it = lower_bound(vec.begin(), vec.end(), i);
        if(it != vec.end()){
            cout << 2;
            return 0;
        }
    }
    cout << 3;
}
