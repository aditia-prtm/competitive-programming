#include<cstdio>
#include<algorithm>
using namespace std;

int n;
long long d, a[100005];
int main(){
	scanf("%d %lld", &n, &d);
	for(int i = 1; i <= n; i++){
	    scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1); reverse(a+1, a+n+1);
	long long r = n+1;
	for(int i = 1; i <= n; i++){
	    long long tmp = d/a[i];
	    if(r-tmp <= i){
	        printf("%d", i-1); 
	        return 0;
	    }
	    r-=tmp;
	}
	printf("%d", n);
}