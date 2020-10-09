#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/agc035_a.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v)                        \
  rep(l, v.size()) { cout << v[l] << " "; } \
  cout << endl;
#else
#define INPUT_FILE
#define print_vec(v)
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
typedef pair<ll, ll> pl;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  cin >> N;

  map<ll, int> m;
  rep(i, N) {
    ll x;
    cin >> x;
    m[x]++;
  }

  bool ok = false;
  if (m.size() == 1 && m.begin()->first == 0) {
    ok = true;
  } else if (m.size() == 2) {
    int zn, xn;
    for (auto kv : m) {
      if (kv.first == 0) {
        zn = kv.second;
      } else {
        xn = kv.second;
      }
    }
    if (xn / 2 == zn && xn + zn == N) {
      ok = true;
    }
  } else if (m.size() == 3) {
    int n = 0;
    set<int> s;
    int xr = 0;
    for (auto kv : m) {
      s.insert(kv.second);
      xr = xr ^ kv.first;
    }
    if (s.size() == 1 && xr == 0) {
      ok = true;
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
}