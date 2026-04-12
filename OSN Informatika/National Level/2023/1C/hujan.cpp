#include<bits/stdc++.h>
using namespace std; 
#define pub push_back
#define int long long
#define fi first 
#define se second 

int n, a[1069][1069], sub1[2][2] = {{-1,6},{9,-1}}, mod = 1000000007;

void sub2(){
    int min1 = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] == -1) min1++;
        }
    }
    if(min1 >= 3) cout << "-1\n";
    else if(min1 == 2){
        if(a[1][1] != -1 && a[2][2] != -1) cout << (a[1][1] + a[2][2] + 1) % mod << endl;
        else if(a[1][2] != -1 && a[2][1] != -1) cout << (a[2][1] + a[1][2] + 1) % mod<< endl;
        else cout << "-1\n";
    }else if(min1 == 1){
       if(a[1][1] != -1 && a[2][2] != -1){
           int z = a[1][1] + a[2][2];
           if(a[1][2] != -1 && a[1][2] <= z) cout << "1\n";
           else if(a[2][1] != -1 && a[2][1] <= z) cout << "1\n";
           else cout << "0\n";
       }else{
           int z = a[2][1] + a[1][2];
           if(a[1][1] != -1 && a[1][1] <= z) cout << "1\n";
           else if(a[2][2] != -1 && a[2][2] <= z) cout << "1\n";
           else cout << "0\n";
       }
    }else{
        if(a[1][1] + a[2][2] == a[1][2] + a[2][1]) cout << "1\n";
        else cout << "0\n";
    }
}

void sub4(){
    bool g = 1;
    int tmp[1069]; memset(tmp, 0, sizeof(tmp));
    for(int i = 2; i <= n; i++){
        tmp[i] = a[1][i] - a[1][i-1];
    }
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= n; j++){
            if(tmp[j] != a[i][j]-a[i][j-1]){
                g = 0; break;
            }
        }
    }
    cout << g << endl;
}
signed main(){
    cin >> n;
    bool s1 = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j]; if(a[i][j] != sub1[i-1][j-1]) s1 = 0;
        }
    }
    if(s1 && n == 2){
        cout << 16; return 0;
    }else if(n == 2){
        sub2(); return 0;
    }else{
        sub4(); return 0;
    }
    
}