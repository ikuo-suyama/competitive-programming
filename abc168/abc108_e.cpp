#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc168/abc108_e.txt"); \
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

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

long long modpow(long long a, long long n, long long mod = MOD) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

// 有理数の逆を取る
pair<ll, ll> rev_rational(pair<ll, ll> x) {
    ll a = -x.first;
    ll b = x.second;

    if (a < 0) return make_pair(-b, -a);
    return make_pair(b, a);
}
/**
 * 有理数（rational number）クラス
 * 約分された分数表現
 * A / B => {A / gcd(A, B)} / {B / gcd(A, B)}
 * B が負のときは -A, -B と両方にマイナスをかけて分子にマイナスを押し付けておく
 * 
 * A/B <=> -B/A とキャンセルし合う.
 * 数え上げの際は、 2 ^ count(A/B) + 2 ^ count(-B/A) -1 (ゼロの場合を除く)
 */
int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  cin >> N;

  vector<ll> c(N);
  int zero_zero = 0;
  int no_zero = 0;
  int zero_no = 0;
  map<pl, int> cnt;

  rep(i, N) {
    ll a, b;
    cin >> a >> b;
    if (a == 0 && b == 0) zero_zero++;
    else if (a == 0)
      zero_no++;
    else if (b == 0)
      no_zero++;
    else {
      ll gcdab = gcd(abs(a), abs(b));
      ll A = a / gcdab;
      ll B = b / gcdab;
      if (b < 0) {
        A *= -1;
        B *= -1;
      }
      cnt[make_pair(A, B)]++;
    }
  }

  ll ans = 0;
  // どちらかが１の組み合わせ
  ans = modpow(2, zero_no) + modpow(2, no_zero) - 1;
  ans %= MOD;
  set<pl> used;
  for (auto kv : cnt) {
    auto pa = kv.first;
    if (used.count(pa)) continue;
    auto rev = rev_rational(pa);
    ans *= modpow(2, cnt[pa]) + modpow(2, cnt[rev]) - 1;
    ans %= MOD;
    used.insert(rev);
  }

  ans += zero_zero;
  ans %= MOD;
  ans -= 1;
  if (ans < 0) ans += MOD;

  cout << ans << endl;
}