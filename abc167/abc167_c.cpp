#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc167/abc167_c.txt"); \
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

  int N, M, X;
  cin >> N >> M >> X;

  vector<int> c(N);
  vector<vector<int>> a(N, vector<int>(M, 0));
  rep(i, N) {
    cin >> c[i];
    rep(j, M) { cin >> a[i][j]; }
  }

  ll ans = LINF;
  rep(i, pow(2, N)) {
    ll tmpans = 0;
    vector<ll> buf(M, 0);
    rep(j, N) {
      if (i & (1 << j)) {
        tmpans += c[j];
        rep(l, M) { buf[l] += a[j][l]; }
      }
    }
    bool ok = true;
    rep(k, M) { ok &= X <= buf[k]; }
    if (ok) ans = min(tmpans, ans);
  }

  cout << (ans != LINF ? ans : -1) << endl;
}