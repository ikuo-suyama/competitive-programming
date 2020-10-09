#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc162/abc162_e.txt"); \
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

ll dp[100010];

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod = MOD) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, K;
  cin >> N >> K;

  memset(dp, 0, 100010 * sizeof(ll));

  for (int i = K; i >= 1; i--) {
    dp[i] = modpow(K / i, N);
    for (int j = 2 * i; j <= K; j += i) {
      dp[i] -= dp[j];
    }
    dp[i] = (dp[i] % MOD + MOD) % MOD;
  }

  ll ans = 0;
  rep(i, K+1) {
    ans += i * dp[i] % MOD;
    ans %= MOD;
  }

  cout << ans << endl;
}