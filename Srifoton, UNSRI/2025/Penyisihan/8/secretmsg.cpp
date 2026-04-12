#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char light, shadow;
    cin >> n >> light;
    cin.ignore();          
    cin.get(shadow);     

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i + j == n - 1) cout << light;
            else cout << shadow;
        }
        cout << endl;
    }
}
