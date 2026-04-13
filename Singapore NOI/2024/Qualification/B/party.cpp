#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int>a;
signed main(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	
	int ans = 0;
	for(int i = 1; i <= (n+1)/2; i++){
		if(a[i-1] > 0) ans += a[i-1];
	}
	cout << ans;
}