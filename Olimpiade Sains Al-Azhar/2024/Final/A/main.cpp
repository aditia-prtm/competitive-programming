#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll 
#define pb push_back
#define pii pair<int, int>
#define all(v) v.begin(), v.end() 
#define lb lower_bound
#define F first
#define S second 

int a, x, y;
int32_t main(){
    cin >> a; x = y = 1; 
    while(y < 1000000000){
        int tmp = x+y; 
        x = y; y = tmp; 
        if(a%y == 0){
            cout << (a/y)*x; return 0;
        }
    }
    cout << -1;
}