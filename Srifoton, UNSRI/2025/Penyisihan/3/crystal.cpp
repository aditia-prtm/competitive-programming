#include <bits/stdc++.h>
using namespace std;

int minimal_days(string x, string y) {
    int c0 = 0, c1 = 0;
    int n = x.size();
    for (int i = 0; i < n; ++i) {
        if (x[i] == '0' && y[i] == '1') c0++;
        else if (x[i] == '1' && y[i] == '0') c1++;
    }
    return max(c0, c1);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string x, y;
        cin >> x >> y;
        cout << minimal_days(x, y) << endl;
    }
    return 0;
}
