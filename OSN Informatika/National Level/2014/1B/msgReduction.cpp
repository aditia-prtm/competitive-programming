#include<bits/stdc++.h>
using namespace std;

int n, q, cnt[100005] = {0};
string s;
char c[100005];
int main(){
    string subsoal; cin >> subsoal;
    cin >> n >> q >> s;
    
    char prev = s[0];
    int tmp = 1;
    c[1] = prev;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != prev){
            tmp ++;
            c[tmp] = s[i];
        }
        cnt[i + 1] = tmp;
        prev = s[i];
        //cout << i + 1 << ' ' << s[i] << ' ' << tmp << endl;
    }
    
    while(q--){
        int a, b; cin >> a >> b;
        cout << cnt[b] - cnt[a] + 1;
        if(cnt[b] - cnt[a] + 1 < 10){ 
            cout << ' ';
            for(int i = cnt[a]; i <= cnt[b]; i++){
                cout << c[i];
            }
        }
        cout << endl;
    }
}
/*
ambatukam
20 5
AAABBCCCCCQWERTYUIOP
111223333345678910111213

1 1
1 3
2 9 -> 1 3
1 20
18 20


*/