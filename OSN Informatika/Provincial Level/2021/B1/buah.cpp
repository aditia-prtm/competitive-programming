#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, a, b;

int main(){
	cin >> n >> a >> b;
	ll kpk = (a * b) / (__gcd(a, b));
	cout << kpk / a + kpk / b;
}