#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc057_c.txt"); \
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

/**
 * ceil loga(x)
 */
int loga(ll x, ll a) {
  if (x == 0) return 0;
  int cnt = 0;
  while (x != 0) {
    x /= a;
    cnt++;
  }
  return cnt;
}

/**
 * 約数の数え上げ
 * N = A * B , B * A であるから、sqrt n まで数えれば十分。
 * ~ 10 ^ 10 程度でも間に合う
 * #integer #約数
 */
int main() {
  INPUT_FILE CIN_OPTIMIZE;

  ll N;
  cin >> N;

  ll ans = INF;
  ll tmp = 1;
  repi(i, 1, sqrt(N) + 1) {
    if (N % i != 0) continue;
    ll res = N / i;
    ll f = max(loga(tmp, 10), loga(res, 10));
    ans = min(ans, f);
  }

  cout << ans << endl;
}