#include<cstdio>

int main(){
	long long n, m; 
	scanf("%lld %lld", &n, &m);
	if(m==1) printf("%lld", n-1);
	else printf("%lld", n*(m-1));
}