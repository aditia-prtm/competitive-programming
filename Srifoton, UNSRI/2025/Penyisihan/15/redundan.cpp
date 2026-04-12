#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define lb lower_bound

bool hasRedundant(string &s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == ')') {
            bool operatorFound = false;
            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/')
                    operatorFound = true;
                st.pop();
            }
            if (!st.empty()) st.pop();
            if (!operatorFound) return true; 
        } else {
            st.push(ch);
        }
    }
    return false;
}

signed main() {
    string expr;
    cin >> expr;

    cout << (hasRedundant(expr) ? "true" : "false") << endl;
}
