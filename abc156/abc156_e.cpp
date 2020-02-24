#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
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

/**
 * 組み合わせ
 */
int main() {
  ifstream in("abc156/abc156_e.txt");
  cin.rdbuf(in.rdbuf());

  ll N, K;
  cin >> N >> K;
  K = min(N, K);

  // 階乗テーブルの初期化
  fact[0] = 1;
  invfact[0] = 1;
  repi(i, 1, N + 1) {
    fact[i] = fact[i - 1] * i % MOD;
    invfact[i] = invfact[i - 1] * powMod(i, MOD - 2) % MOD;
  }

  ll ans = 0;
  // ゼロが入る位置の組み合わせを数え上げる
  // nCm * (n-m)Hm = nCm * (n - m + m - 1)Cm = nCm * (n-1)Cm
  // via xHy = (x + y - 1)Cy
  rep(i, K + 1) {
    ll tmp = combMod(N, i) * combMod(N - 1, i) % MOD;
    ans = (ans + tmp) % MOD;
  }

  cout << ans << endl;
}