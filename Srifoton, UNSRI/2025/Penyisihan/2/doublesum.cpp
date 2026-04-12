#include<bits/stdc++.h>
using namespace std;
#define int long long 

vector<int>v;
signed main(){
    int x;
    while(cin >> x) v.push_back(x);

    int k = v.back();
    v.pop_back();

    for(int i = 1; i < v.size(); i++){
        for(int j = 0; j < i; j++){
            if(v[i] + v[j] == k){
                cout << "[" << j << ", " << i << "]";
                return 0;
            }
        }
    }
}