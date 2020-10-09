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

  ll A = 0;
  ll ai = -1;
  rep(i, N) {
    if (A + a[i] <= K) {
      A += a[i];
    } else {
      break;
    }
    ai = i;
  }

  int bj = -1;
  ll B = 0;
  ll k = K - A;
  rep(j, M) {
    if (B + b[j] <= k) {
      B += b[j];
    } else {
      break;
    }
    bj = j;
  }
  int ans = ai + bj + 2;

  for (int i = ai; i >= 0; i--) {
    A -= a[i];
    ll k = K - A;
    repi(j, bj + 1, M) {
      if (B + b[j] <= k) {
        B += b[j];
      } else {
        break;
      }
      bj = j;
    }
    ans = max(i + bj + 1, ans);
  }

  cout << ans << endl;
}