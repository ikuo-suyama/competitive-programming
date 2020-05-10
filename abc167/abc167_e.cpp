#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("abc167/abc167_e.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v) \
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
const ll LINF = 1e18+100;
const int MOD = 998244353;

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

  int N, M, K;
  cin >> N >> M >> K;
 
  // 階乗テーブルの初期化
  fact[0] = 1;
  invfact[0] = 1;
  repi(i, 1, N + 1) {
    fact[i] = fact[i - 1] * i % MOD;
    invfact[i] = invfact[i - 1] * powMod(i, MOD - 2) % MOD;
  }
 
  ll ans = powMod(M, N);
  repi(i, K + 1, N) {
    ll dup = combMod(N - 1, i) * combMod(M + i - 1, i) % MOD;
    ans -= dup;
    if (ans < 0) ans += MOD;
    ans %= MOD;
  }

  cout << ans << endl;
}