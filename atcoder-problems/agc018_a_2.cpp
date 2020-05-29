#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                       \
  ifstream in("atcoder-problems/agc018_a.txt"); \
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

/**
 * すべての要素の差の組み合わせ -> 最大公約数
 * #Integer
 */
int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, K;
  cin >> N >> K;

  vector<ll> c(N);
  ll m = 0;
  rep(i, N) {
    cin >> c[i];
    m = max(m, c[i]);
  }

  ll _gcd = c[0];
  rep(i, N) { _gcd = gcd(_gcd, c[i]); }

  bool ret = K <= m && K % _gcd == 0;

  cout << (ret ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}