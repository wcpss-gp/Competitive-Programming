// <judge> Problem Link:

#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <complex>
#include <cstdint>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

// #define atcoder 1
// #define codeforces 1

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")

#define spc " "
#define nl "\n"
#define eb emplace_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define F_OR(i, j, k, l) for (int i=(j); (l) > 0 ? i < (k) : i > (k); i += (l))
#define F_OR1(j) F_OR(i, 0, j, 1)
#define F_OR2(i, j) F_OR(i, 0, j, 1)
#define F_OR3(i, j, k) F_OR(i, j, k, 1)
#define F_OR4(i, j, k, l) F_OR(i, j, k, l)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(i, j) for (auto &i: j)

using ll = long long;
using ld = long double;
using int32 = long int;
using uint32 = unsigned long int;
using int64 = long long int;
using uint64 = unsigned long long int;

const int32 BIG = 1e9, SMALL = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

#ifdef atcoder
    const ll MOD = 998244353;
    const string yes = "Yes\n", no = "No\n";
#endif

#ifdef codeforces
    const ll MOD = 1e9 + 7;
    const string yes = "YES\n", no = "NO\n";
#endif

template <class T> int sz(const T &container) { return (int)container.size(); }

template <typename T> int index(const vector<T> &v, const T &n) {
    FOR(i, sz(v)) if (v[i] == n) return i;
    return -1;
}

string to_string(char c) { return string(1, c); }

string to_string(bool b) { return b ? "true" : "false"; }

string to_string(const char* c) { return string(c); }

string to_string(vector<bool> v) {
    string res;
    for (int i = 0; i < sz(v); ++i) res += char('0' + v[i]);
    return res;
}

int choi(char c) { return ((int) (c - '0')); }

char iohc(int i) { return ((char) (i + '0')); }

template<size_t S> string to_string(bitset<S> b) {
    string res;
    FOR(S) res += char('0' + b[i]);
    return res;
}

template<class T> string to_string(T v) {
    bool f = 1;
    string res;
    EACH(x, v) {
        if(!f) res += spc;
        f = 0;
        res += to_string(x);
    }
    return res;
}

void setIO(string filename = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (sz(filename)) {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

ll mod_inv(ll num, ll mod) { return num <= 1 ? num : mod - ( mod / num) * mod_inv(mod % num, mod) % mod; }

bool is_prime(int num) {
    for (int i = 2; i * i <= num; ++i) if (num % i == 0) return false;
    return num >= 2;
}

ll binpow(ll base, ll exp) {
    ll ret = 1;
    while (exp > 0) {
        if (exp & 1) ret *= base;
        base *= base;
        exp >>= 1;
    }
    return ret;
}

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n); EACH(i, a) cin >> i;
    vector<array<ll, 2>> query(q);
    for (int i = 0; i < q; i++) { query[i][1] = i; cin >> query[i][0]; }
    sort(all(a)); sort(rall(query));
    ll ans = 0;
    vector<ll> res(q);
    for (ll i = 0; i < n - 2; i++) {
        ans += (n - (i + 1)) * (n - (i + 2)) / 2;
        while (!query.empty() && query[size(query) - 1][0] <= ans) { res[query[size(query) - 1][1]] = a[i]; query.pop_back(); }
    }
    EACH(i, res) cout << i << "\n";
}

int main() {
    setIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
