#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, k, patok[100005];
int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> patok[i];
		patok[i] += patok[i - 1];
	}
	while(k--){
		int b; cin >> b;
		cout << lower_bound(patok, patok + n, b + 1) - patok << endl;
	}
}
/*
5 5
1 2 1 2 1
2 3 5 6 5
*/
