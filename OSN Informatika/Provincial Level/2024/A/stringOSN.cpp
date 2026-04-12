#include<bits/stdc++.h>
using namespace std;

string s, c[6] = {"OSN", "ONS", "SON", "SNO", "NOS", "NSO"};
//O(6*s.length()) 
int ans = 0;
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    for(int i = 0; i < 6; i++){
        int idx = 0, tmp = 0;
        for(int j = 0; j < s.length(); j++){
            if(s[j] == c[i][idx]){
                tmp++; idx++; idx %=3;
            }
        }
    //    cout << c[i] << " >> " << tmp << endl;
        ans = max(ans, tmp);
    }
    if(ans < 3) cout << -1;
    else cout << ans;
}
/*
BLUNDER :
* Panik duluan liat soal A dan B
* gabisa manage waktu 
* lupa def int ll 
* lupa doa sebelum lomba
* banyak lah
*/