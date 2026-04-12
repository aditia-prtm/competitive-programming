#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second

int n, m, a[100005], b[100005], cnt[100005];
ll suma, sumb, ans;
vector<pair<int, int> >bb;

double avg(double sum, double y){
	return sum / y;
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i]; suma += a[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> b[i]; cnt[b[i]]++; sumb += b[i];
		if(cnt[b[i]] == 1){
		   bb.push_back({b[i], 0});
     	}
	}
	sort(bb.begin(), bb.end());
	if(avg(suma, n) > avg(sumb, m)){
		cout << 0; return 0;
	}
	for(int i = bb.size() - 1; i >= 1; i--){
		bb[i].S = cnt[bb[i].F];
	//	cout << bb[i].F << ' ' << bb[i].S << endl;
		ans += bb[i].F * bb[i].S;
		suma += bb[i].F * bb[i].S; n += bb[i].S;
		sumb -= bb[i].F * bb[i].S; m -= bb[i].S;
	//	cout << suma << ' ' << n << ' ' << sumb << ' ' << m << endl;
	//	cout << avg(suma, n) << ' ' << avg(sumb, m) << endl;
		if(avg(suma, n) > avg(sumb, m)){
			cout << ans; return 0;
		}
	}
	cout << "-1";
}
/*
1 4
2
1 5 5 5
*/
