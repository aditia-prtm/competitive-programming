#include<bits/stdc++.h>
using namespace std; 
#define pub push_back
#define int long long
#define fi first 
#define se second 

int n, k, q, a[100005], par[100005], tmp[100005];
vector<int>child[100005], csd;

pair<int, int> cek(){
    int ans = -1, tukar = -1;
    for(auto i : csd){
        int mn = 1e18, tkr = -1;
        for(auto j : child[i]){
            if(tmp[j] < mn){
                mn = tmp[j]; tkr = j;
            }
        }
        if(tmp[i] > mn){
            ans = i; tukar = tkr;
            break;
        }
        if(ans != -1) break;
    }
 //   cout << ans << "-> " << tukar << endl;
    return {ans, tukar};
}

void sub1_3(){
    for(int i = 1; i <= n; i++){
        if(!child[i].empty()) csd.pub(i);
    } reverse(csd.begin(), csd.end());
    
    do{
        for(int i = 1; i <= n; i++) tmp[i] = a[i];
        int ans = 0;
        while(true){
            pair<int, int>c = cek();
            if(c.fi != -1 && c.se != -1){
                ans++;
                swap(tmp[c.fi], tmp[c.se]);
            }else break;
        }
        if(ans == k){
            cout << "YA\n";
            if(q){
                for(int i = 1; i <= n; i++) cout << a[i] << ' ';
            }
            exit(0);
        }
    }while(next_permutation(a+1, a+n+1));
    cout << "TIDAK";
}

signed main(){
    cin >> n >> k >> q;
    bool jejer = 1;
    for(int i = 1; i <= n; i++){
        a[i] = i;
        if(i>1){
            int p; cin >> p;
            child[p].pub(i); par[i] = p;
            if(p != i-1) jejer = 0;
        }
    }
    if(jejer){
        //subtask 4  
        if(k > (n*(n-1))/2) cout << "TIDAK";
        else{
            cout << "YA\n";
            if(q){
                int sum = 0;
                for(int i = n-1; i >= 1; i--){
                    sum += i; 
                    if(sum == k){
                        for(int j = n; j > i; j--) cout << j << ' ';
                        for(int j = 1; j <= i; j++) cout << j << ' ';
                        return 0;
                    }else if(k < sum){
                        for(int j = n; j > i+1; j--) cout << j << ' ';
                        int pdh = k-(sum-i)+1, id = i+1;
                        vector<int>v;
                        for(int j = 1; j <= i+1; j++){
                            if(j == pdh) v.pub(i+1);
                            else{
                                id--; v.pub(id);
                            }
                        } 
                        for(int j = v.size()-1; j >= 0; j--) cout << v[j] << ' ';
                        return 0;
                    }
                }
            }
        }
    }else sub1_3();
}