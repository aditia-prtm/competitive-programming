#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxn = 1e5+5;

int n, p, q;
pair<int, int> ego[maxn];
int ans[maxn];
int main(){
	cin >> n >> p >> q;
	for(int i = 1; i <= n; i++){
		cin >> ego[i].fi;
		ego[i].se = i;
	}
	sort(ego+1, ego+1+n); 
	priority_queue<pair<int, int>> pq; 
	int rbound = 1;
	for(int i = 1; i <= n; i++){
		while(rbound+1 <= n && ego[rbound+1].fi - ego[i].fi <= p){
			rbound++; 
		}
		pq.push(make_pair(rbound - i + 1, rbound)); 
		while(pq.top().se < i){
			pq.pop(); 
		}
		ans[ego[i].se] = pq.top().fi;
	}
	for(int i = 1; i <= q; i++){
		int x; cin >> x; 
		cout << ans[x] << endl;
	}
}