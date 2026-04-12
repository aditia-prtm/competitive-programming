#include<bits/stdc++.h>
using namespace std;
#define int long long 

map<char, int>mp;
signed main(){
    string s; 
    getline(cin, s);

    if(s.length() < 1 || s.length() > 8){
        cout << "Panjang string harus antara 1 hingga 8.";
        return 0;
    }

    for(auto i : s){
        if(i < 'a' || i > 'z'){
            cout << "String hanya boleh berisi huruf kecil a-z tanpa spasi.";
            return 0;
        }
        mp[i]++;
    }
    
    for(auto i : mp){
        if(i.second > 1){
            cout << "Semua karakter harus unik (tidak boleh ada huruf yang sama).";
            return 0;
        }
    }

    sort(s.begin(), s.end());

    do{
        cout << s << endl;
    }while(next_permutation(s.begin(),s.end()));
}