#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[200005], sgtree[800005], lazy[800005];

void build(int node, int l, int r){
    if (l == r){
        sgtree[node] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
    sgtree[node] = sgtree[node*2] + sgtree[node*2+1];
}

void prop(int node, int l, int r){
    if (lazy[node] != 0){
        sgtree[node] += (r - l + 1) * lazy[node];
        if (l != r){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int L, int R, int v){
    prop(node, l, r);
    if (r < L || R < l) return;
    if (L <= l && r <= R){
        lazy[node] += v;
        prop(node, l, r);
        return;
    }
    int mid = (l+r)/2;
    update(node*2, l, mid, L, R, v);
    update(node*2+1, mid+1, r, L, R, v);
    sgtree[node] = sgtree[node*2] + sgtree[node*2+1];
}

int query(int node, int l, int r, int L, int R){
    if (r < L || R < l) return 0;
    prop(node, l, r);
    if (L <= l && r <= R) return sgtree[node];
    int mid = (l+r)/2;
    return query(node*2, l, mid, L, R)
         + query(node*2+1, mid+1, r, L, R);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    memset(sgtree, 0, sizeof(sgtree));
    memset(lazy, 0, sizeof(lazy));

    build(1, 1, n);

    int q; cin >> q;
    while (q--){
        string s; cin >> s;
        int l, r; cin >> l >> r;
        if (s == "SUM"){
            cout << query(1, 1, n, l, r) << "\n";
        } else {
            int v; cin >> v;
            update(1, 1, n, l, r, v);
        }
    }
}