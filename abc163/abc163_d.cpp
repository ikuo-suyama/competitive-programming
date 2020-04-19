#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc163/abc163_d.txt"); \
  cin.rdbuf(in.rdbuf());
#else
#define INPUT_FILE
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

/**
 * 繰り返し自乗法
 * http://satanic0258.hatenablog.com/entry/2016/04/29/004730
 */
ll powMod(ll n, ll p, const int mod = MOD) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    ll t = powMod(n, p / 2);
    return t * t % MOD;
  } else {
    return n * powMod(n, p - 1) % MOD;
  }
}

/**
 * 余剰Combination
 * nCk≡n! * (k!)^M−2 * ((n−k)!)^M−2 (modM)
 */
ll combMod(ll n, ll k, const int mod = MOD) {
  ll nCk = 1;
  k = min(k, n - k);

  repi(i, 1, k + 1) {
    nCk = nCk * (n - i + 1) % MOD;
    nCk = nCk * powMod(i, mod - 2) % MOD;
  }
  return nCk;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, K;
  cin >> N >> K;

  ll ans = 0;
  repi(i, K, N + 1) {
    ans += combMod(N + 1, i);
    ans %= MOD;
  }
  if (ans == 0) ans++;

  cout << ans << endl;
}