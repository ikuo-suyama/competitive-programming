#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                     \
  ifstream in("abc145/abc145_d.txt"); \
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

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// 逆元
// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

ll factorialMod(int n) {
  ll ret = 1;
  rep(i, n) {
    ret *= i + 1;
    ret %= MOD;
  }
  return ret;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  ll x, y;
  cin >> x >> y;

  if ((2 * x - y) % 3 != 0 || (2 * y - x) % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  ll a = (2 * x - y) / 3;
  ll b = (2 * y - x) / 3;
  if (a < 0 || b < 0) {
    cout << 0 << endl;
    return 0;
  }

  ll abf = factorialMod(a + b);
  ll apb = factorialMod(a) * factorialMod(b) % MOD;
  // a / b (mod p) = a * (1 / b) (mod p)
  ll cnt = abf * modinv(apb, MOD) % MOD;

  cout << cnt << endl;
}