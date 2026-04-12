#include<cstdio>
#include<vector>
#include<algorithm> 
#define ll long long 
#define pb push_back 
#define all(x) x.begin(), x.end() 
#define lb lower_bound 
using namespace std; 

ll n, b;
vector<ll>last;

void inp(ll &num){
    bool neg = 0; register ll c; num = 0; c = getchar();
    if(c=='-'){ neg = 1; c = getchar();}
    for(;(c>47 && c<58); c = getchar()) num = num*10+c-48;
    if(neg) num *= -1;
}
int main(){
	inp(n); inp(b);
	last.push_back(b);
	for(int i = 2; i <= n; i++){
	    inp(b);
	    ll id = lb(all(last), b)-last.begin();
	    if(id==last.size()) last.pb(b);
	    else last[id] = b;
	}
	printf("%ld", last.size());
}