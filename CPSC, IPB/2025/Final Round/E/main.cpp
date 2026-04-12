#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
const int N = 2e5+5;


int binpow(int x, int y){
    if(y==0) return 1;
    if(y==1) return x;

    int p = binpow(x, y/2);
    int q = p;
    if(y%2 == 1) q*=x;
    return p*q;
}
int sumRow(int left, int right){
    int prev = left * (left-1) / 2, x = right * (right+1) / 2;
    return x - prev;
}

int binser(int n, int Lleft, int Rleft, int len){
    int left = Lleft, right = Rleft, mid = 0;
    while(left <= right){
        mid = (left + right) / 2;
        int tmp = sumRow(mid, mid+len-1);
        // cout << tmp << ": " << left << ' ' << right << ' ' << mid << endl;

        if(tmp > n) right = mid-1;
        else if(tmp < n) left = mid+1;
        else return mid;
    }
    return -1;
}


signed main(){
    int t;
    cin >> t;

    while(t--){
        int n; cin >> n;
        // cek apakah n = 2 pangkat 
        int kcek = log2(n);
        if(binpow(2, kcek) == n){
            cout << "GAK BISA\n";
            continue;
        }
        cout << n << " = ";
        if(n%2 == 1) cout << n/2 << " + " << n/2+1 << endl;
        else if(n%3 == 0) cout << n/3-1 << " + ... + " << n/3+1 << endl;
        else{
            int len;
            for(int i=4; i<=10000; i++){
                // cout << "length: " << i << endl;
                int kiri = max((int)1, n/i - i);
                int hasil = binser(n, kiri, n/i + 1, i);
                if(hasil != -1){
                    cout << hasil << " + ... + " << hasil+i-1 << endl;
                    break;
                }
            }   
        }
    }
}
