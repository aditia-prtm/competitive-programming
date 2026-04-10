#include<cstdio>

long long n, k, x;
int main(){
	scanf("%lld %lld %lld", &n, &k, &x);
	if(x<0) x*=-1;
	if(n*k < x) printf("TIDAK");
	else printf("YA");
}