#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

struct node {
    long long gain;
    int row, nextt;
    bool operator<(const node &other) const {
        return gain < other.gain; 
    }
};

int n, m, k;
vector<vector<int>> a, suffix;
vector<int> chosent;
int totalans;

int defense(int r, int t) {
    if (t > m) return 0LL;
    return (int)t * suffix[r][t];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    
    cin >> n >> m >> k;
    a.assign(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    suffix.assign(n, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            suffix[i][j] = a[i][j] + suffix[i][j + 1];
        }
    }

    priority_queue<node> pq;

    for (int i = 0; i < n; i++) {
        if (m >= 1) {
            int gain = defense(i, 1) - defense(i, 0);
            pq.push({gain, i, 1});
        }
    }

    totalans = 0;
    chosent.assign(n, 0);

    for (int used = 0; used < k && !pq.empty(); used++) {
        auto cur = pq.top(); pq.pop();
        totalans += cur.gain;
        int r = cur.row;
        chosent[r] = cur.nextt;
        if (cur.nextt + 1 <= m) {
            int gain2 = defense(r, cur.nextt + 1) - defense(r, cur.nextt);
            pq.push({gain2, r, cur.nextt + 1});
        }
    }

    cout << totalans;
}
