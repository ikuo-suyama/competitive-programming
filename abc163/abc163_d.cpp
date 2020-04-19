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

ll powMod(ll n, ll p, const int mod = MOD) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    ll t = powMod(n, p / 2);
    return t * t % mod;
  } else {
    return n * powMod(n, p - 1) % mod;
  }
}

ll fact[200010];
ll invfact[200010];

/** nCr の O(1)版.
 * N ~ 10^5 ならこちらのほうが早い
 * nCk≡n! * (k!)^M−2 * ((n−k)!)^M−2 (modM)
 */
ll combMod(int n, int p) { 
  ll ret = fact[n] * invfact[p] % MOD;
  ret = ret * invfact[n - p] % MOD;
  return ret;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, K;
  cin >> N >> K;

  // 階乗テーブルの初期化
  fact[0] = 1;
  invfact[0] = 1;
  repi(i, 1, N + 2) {
    fact[i] = fact[i - 1] * i % MOD;
    invfact[i] = invfact[i - 1] * powMod(i, MOD - 2) % MOD;
  }

  ll ans = 0;
  repi(i, K, N + 1) {
    ans += combMod(N + 1, i);
    ans %= MOD;
  }
  if (ans == 0) ans++;

  cout << ans << endl;
}