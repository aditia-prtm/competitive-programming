#include "wall.h"
#include<bits/stdc++.h>
using namespace std; 
const int maxn = 2e6+10; 
const int MAX = 1e9+7; 

int mn[4*maxn], mx[4*maxn], final[maxn];
void build(int v, int l, int r){
    mx[v] = MAX; mn[v] = 0;
    if(l == r) return;
    int m = (l+r)>>1;
    build(2*v, l, m); build(2*v+1, m+1, r);
}

void upd(int v, int l, int r, int L, int R, int h, int t){
    if(l > r || l > R || r < L) return;
    if(l >= L && r <= R){
        if(t == 1){
            mn[v] = max(h, min(mn[v], mx[v]));
            mx[v] = min(MAX, max(mn[v], mx[v]));
        }else{
            mn[v] = max(0, min(mn[v], mx[v]));
            mx[v] = min(h, max(mn[v], mx[v]));
        }
        return;
    }

    mn[2*v] = max(mn[v], min(mn[2*v], mx[2*v]));
    mx[2*v] = min(mx[v], max(mn[2*v], mx[2*v]));
    
    mn[2*v+1] = max(mn[v], min(mn[2*v+1], mx[2*v+1]));
    mx[2*v+1] = min(mx[v], max(mn[2*v+1], mx[2*v+1]));
    
    mx[v] = MAX; mn[v] = 0;
    
    int m = (l+r)>>1;
    upd(2*v, l, m, L, R, h, t); upd(2*v+1, m+1, r, L, R, h, t);
}

void que(int v, int l, int r, int L, int R){
    if(l > r || l > R || r < L) return;
    if(l == r) final[l] = min(mx[v], mn[v]);
    else{
        mn[2*v] = max(mn[v], min(mn[2*v], mx[2*v]));
        mx[2*v] = min(mx[v], max(mn[2*v], mx[2*v]));
    
        mn[2*v+1] = max(mn[v], min(mn[2*v+1], mx[2*v+1]));
        mx[2*v+1] = min(mx[v], max(mn[2*v+1], mx[2*v+1]));
    
        mx[v] = MAX; mn[v] = 0;
        
        int m = (l+r)>>1;
        que(2*v, l, m, L, R); que(2*v+1, m+1, r, L, R);
    }
}


void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
    build(1, 1, n);
    for(int i = 0; i < k; i++){
        left[i]++; right[i]++;
        upd(1, 1, n, left[i], right[i], height[i], op[i]);
    }
    que(1, 1, n, 1, n);
    for(int i = 1; i <= n; i++) finalHeight[i-1] = final[i];
    return;
}
