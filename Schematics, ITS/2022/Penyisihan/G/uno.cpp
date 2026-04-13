#include<cstdio>

int t, n;
int lajukan(int x){
    int ans = 0;
    while(x > 0){
        ans += (x%10);
        x /= 10;
    }
    return ans;
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        while(n>=10) n = lajukan(n);
        printf("%d\n", n);
    }
}