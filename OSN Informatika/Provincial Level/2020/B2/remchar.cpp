#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, ans; string s;
vector<int>v;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	sort(s.begin(), s.end());
	int tmp = 1;
	for(int i = 1; i < s.length(); i++){
		if(s[i] != s[i - 1]){
			v.push_back(tmp);
			tmp = 1;
		}else tmp++;
	} v.push_back(tmp);
	sort(v.begin(), v.end()); int sz = v.size();
	if(v.size() < 3){
		cout << -1; return 0;
	}else{
		int a = v[sz - 1], b = v[sz - 2], c = v[sz - 3];
		a -= c; b -= c; ans += c * 3;
		if(a > 0)ans++;
		if(b > 0)ans++;
	}
	cout << ans << endl;
	/*for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}*/
}
/*
9
KLSSPLNLS
*/
