#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc164/abc164_d.txt"); \
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

/**
 * Sの部分文字列に2019が何個含まれるか？
 *
 * 部分文字列に含まれる約数を数える。
 * n が p の約数 であるとき、p が2,5の倍数でなければ 10n は p の約数である。
 * 部分文字列(i, j)が条件を満たすのは (10 ^ n - j)(Tn-1 - Tn) が p
 * の倍数のとき。 つまり Tn - 1 mod p == Tn mod p
 *
 * modPの数を数えたら、その組み合わせ nC2 の数え上げが答え。
 */
int main() {
  INPUT_FILE CIN_OPTIMIZE;

  string S;
  cin >> S;

  int N = S.size();
  int p = 2019;
  vector<int> a(N);
  rep(i, N) { a[i] = S[i] - '0'; }
  reverse(a.begin(), a.end());

  map<int, int> m;
  int t = 0;
  rep(i, N) {
    t += a[i] * modpow(10, i, p) % p;
    t %= p;
    m[t]++;
  }

  ll ans = m[0];
  for(auto kv : m) {
    ans += kv.second * (kv.second - 1) / 2;
  }
  cout << ans << endl;
}