#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first 
#define S second 
const int MOD = 1e9+7, N = 3e5+5, MAXN = 1e6;

string s;
int cnt[26];

signed main() {
    cin >> s;
    for (auto c : s) cnt[c - 'a']++;
    vector<char> odd;
    for (int i = 0; i < 26; i++)
        if (cnt[i] % 2) odd.push_back('a' + i);
    if (odd.empty()) {
        string half = "";
        for (int i = 0; i < 26; i++) half += string(cnt[i] / 2, 'a' + i);
        string rev = half;
        reverse(rev.begin(), rev.end());
        cout << 1 << endl << half + rev << endl;
        return 0;
    }
    int k = odd.size();
    vector<int> freq(26);
    for (int i = 0; i < 26; i++) freq[i] = cnt[i];
    for (auto c : odd) freq[c - 'a']--;
    string pool = "";
    for (int i = 0; i < 26; i++) pool += string(freq[i] / 2, 'a' + i);
    vector<string> lefts(k, "");
    int idx = 0;
    for (auto c : pool) {
        lefts[idx].push_back(c);
        idx = (idx + 1) % k;
    }
    vector<string> ans;
    for (int i = 0; i < k; i++) {
        string rev = lefts[i];
        reverse(rev.begin(), rev.end());
        ans.push_back(lefts[i] + string(1, odd[i]) + rev);
    }
    cout << ans.size() << endl;
    for (auto &x : ans) cout << x << endl;
}
