// CodeForces Problem Link: https://codeforces.com/problemset/problem/791/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int ans = 0;
    while (a <= b) {
        a *= 3;
        b *= 2;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}
