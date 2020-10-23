#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("arc105/arc105_a.txt"); \
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

  int N = 4;

  vector<ll> c(N);
  rep(i, N) { cin >> c[i]; }

  bool ok = false;
  rep(i, pow(2, N)) {
    ll l = 0, r = 0;
    rep(j, N) {
      if (i & (1 << j)) {
        l += c[j];
      } else {
        r += c[j];
      }
    }
    if (l == r) {
      ok = true;
      break;
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
}