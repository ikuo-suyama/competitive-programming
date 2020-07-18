#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/agc028_a.txt"); \
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

  ll N, M;
  cin >> N >> M;

  string S, T;
  cin >> S >> T;

  ll L = lcm(N, M);
  map<ll, int> s;
  map<ll, int> t;
  rep(i, N) {
    ll j = (L / N) * i + 1;
    s[j] = i;
  }
  rep(i, M) {
    ll j = (L / M) * i + 1;
    t[j] = i;
  }

  for (auto _s : s) {
    ll p = _s.first;
    if (t.find(p) != t.end()) {
      int i = _s.second;
      int j = t[p];
      if (S[i] != T[j]) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  for (auto _t : t) {
    ll p = _t.first;
    if (s.find(p) != s.end()) {
      int i = _t.second;
      int j = s[p];
      if (T[i] != S[j]) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  cout << L << endl;
}