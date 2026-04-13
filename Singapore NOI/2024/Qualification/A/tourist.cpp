#include<bits/stdc++.h>
using namespace std;

int n,x,y,ans;
int main(){
	cin >> n >> x >> y;
	while(n--){
		int a; cin >> a;
		ans += min(a*x, y);
	}
	cout << ans;
}

