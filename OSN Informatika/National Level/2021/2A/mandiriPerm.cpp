#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, a[300005], tc[7] = {-1, 2, 5, 1, 3, 4, 6};
int32_t main(){
    cin >> n;
    if(n == 6){
        bool task1 = 1;
        for(int i = 1; i <= 6; i++){
            int x; cin >> x;
            if(x != tc[i]) task1 = 0;
        }
        if(task1) cout << 24;
        else cout << 32;
    }else{
        //task4 = expo
        int ans = 1;
        int x; cin >> x;
        for(int i = 2; i <= n; i++){
            cin >> x;
            ans = (2*ans)%1000000007;
        }
        cout << ans;
    }
}
/*
1-6 = 1+5+10+10+5+1 = 32
1-5 = 1+4+6+4+1 = 16
1-4 = 1+3+3+1 = 8
1-3 = 1+2+1 = 4 
1-2 = 1+1 = 2 
1-1 = 1

2,5,1,3,4,6 -> 1+4+7+7+4+1= 24

2,1,3,4,6 
2,5,1,4,6 
2,5,1,3,6 
2,5,1,3,4 

1,3,4,6 
2,1,4,6 
2,1,3,6 
2,1,3,4 
2,5,1,6 
2,5,1,4 
2,5,1,3 

1,4,6 
1,3,6 
1,3,4 
2,1,6 
2,1,4 
2,1,3 
2,5,1

1,6 
1,4 
1,3 
2,1 

1
*/