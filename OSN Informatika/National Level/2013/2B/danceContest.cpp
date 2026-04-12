#include<bits/stdc++.h>
using namespace std;
#define F first 
#define S second
int n, r, y, j;
pair<int, char>t[15], a[15];
bool s[15] = {0};
vector<int>k;

void f(int d){
    if(d == r + 1){
        int ans = 0; bool yakin = 0;
        for(int i = 1; i <= r; i++){
           // cout << a[i].F << ' ' << a[i].S << endl;
            if(i > 1){
                if(a[i - 1].S == 'P'){
                    ans += a[i].F * 2;
                }else if(a[i - 1].S == 'L'){
                    ans += a[i].F / 2;
                }else{
                    ans += a[i].F;
                }
                if(yakin) ans += y;
            }else{
                ans += a[i].F;
            }
            if(a[i].S == 'Y') yakin = 1;
        }
    //    cout << ans << endl;
        k.push_back(ans);
    }else{
        for(int i = 1; i <= n; i++){
            if(!s[i]){
                s[i] = 1;
                a[d].F = t[i].F; a[d].S = t[i].S;
                f(d + 1);
                s[i] = 0;
            }
        }
    }
}

int main(){
    string sub; int zz; 
    cin >> sub >> zz;
    cin >> n >> r >> y >> j;
    for(int i = 1; i <= n; i++){
        cin >> t[i].F >> t[i].S;
    }
    
    f(1);
    sort(k.begin(), k.end());
    while(j--){
        int h; cin >> h;
        cout << k.size() - (upper_bound(k.begin(), k.end(), h) - k.begin()) << endl;
    }
    
}
/*
5 3 1 2 
40 P 
12 B 
9 L 
12 Y 
22 L

5 3 5 3
10 B
15 B
5 P
300 L
7 B
1
1000
600
*/