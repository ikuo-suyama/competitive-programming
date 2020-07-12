#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc172/abc172_c.txt"); \
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

  int N, M, K;
  cin >> N >> M >> K;

  vector<ll> a(N), b(M);
  rep(i, N) { cin >> a[i]; }
  rep(i, M) { cin >> b[i]; }

  int ai = 0, bi = 0;
  int ans = 0;
  ll res = K;
  rep(i, N) {
    if (res - a[i] < 0) {
      ai = i - 1;
      break;
    } else {
      res -= a[i];
      ans++;
    }
  }
  if (res > 0) {
    rep(i, M) {
      if (res - b[i] < 0) {
        bi = i - 1;
        break;
      } else {
        res -= b[i];
        ans++;
      }
    }
  }

  int j = bi;
  for (int i = ai; i >= 0; i--) {
    res += a[i];
    for (int l = j; l < M; l++) {
      if (res - b[l] < 0) {
        j = l - 1;
        break;
      } else {
        res -= b[l];
      }
    }
    ans = max(ans, i + j + 1);
  }
  cout << ans << endl;
}