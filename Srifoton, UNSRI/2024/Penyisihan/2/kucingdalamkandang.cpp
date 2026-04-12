#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define lb lower_bound

int n, a[105], sum;
signed main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum%n > 0){
        cout << -1;
        return 0;
    }
    int left = 1, target = sum/n, step = 0;
    for(int i=1; i<=n; i++){    
        if(a[i] > target){  
            for(int j=1; j<=n; j++){
                if(i==j) continue;
                if(a[i] == target) break;
                if(a[j] < target){
                    int k = target-a[j]; // banyak yg dipindhkan
                    if(a[i]-k >= target){
                        a[i] -= k;
                        a[j] += k;
                    }else{
                        k = a[i]-target;
                        a[i] -= k;
                        a[j] += k;
                    }
                    step += k*abs(i-j);
                    // cout << i << " to " << j << ": " << k << ' ' << step << " - " << a[i] << ' '  << a[j] << endl;
                }
            }
        }
    }
    cout << step;
}