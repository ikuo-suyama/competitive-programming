#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/abc142_d2.txt"); \
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
const int MOD = 1e9 + 7;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

// 素因数分解
vector<pl> prime_factorize(ll N) {
  vector<pl> res;
  for (ll a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    ll ex = 0;  // 指数

    while (N % a == 0) {
      ++ex;
      N /= a;
    }

    res.push_back({a, ex});
  }

  // 最後に残った数について
  if (N != 1) res.push_back({N, 1});
  return res;
}

/** 約数に含まれる素数を列挙する。
 * gcdまでの素数の数え上げでは間に合わない。
 * 素因数分解が高速
 * #prime_factorize #integer
 */
int main() {
  INPUT_FILE CIN_OPTIMIZE;

  ll a, b;
  cin >> a >> b;

  ll ans = 1;
  ll g = gcd(a, b);
  // 最大公約数の素因数はすべて公約数
  vector<pl> p = prime_factorize(g);
  ans += p.size();

  cout << ans << endl;
}