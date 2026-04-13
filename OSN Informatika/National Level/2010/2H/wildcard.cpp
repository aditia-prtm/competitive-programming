#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int x = s.find("*"), q; cin >> q;
    
    string left, right;
    for(int i = 0; i < s.size(); i++){
        if(i < x) left += s[i];
        if(i > x) right += s[i];
    }
   
    while(q--){
        string p; cin >> p;
        bool sm = 1;
        if(s.size() - 1 > p.length()) continue;
        for(int i = 0; i < left.size(); i++){
            if(p[i] != left[i]){
                sm = 0; break;
            }
        }
        int r = p.size() - 1;
        for(int i = right.size() - 1; i >= 0; i--){
            if(p[r] != right[i]){
                sm = 0; break;
            }
            r --;
        }
       // cout << sm << ' ' << smm << endl;
        if(sm){
            cout << p << endl;
        }
    }
    
    
    
}
/*
*
5
mula
makan
minum
main
hama

*akan
jakan
0 2 


*/