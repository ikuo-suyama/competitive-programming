#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/abc109_c.txt"); \
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

// 最大公約数を求める関数。ユークリッドの除去法
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, X;
  cin >> N >> X;
  
  vector<int> c(N + 1);
  rep(i, N) { cin >> c[i]; }
  c[N] = X;
  sort(c.begin(), c.end());

  ll ans = c[1] - c[0];
  rep(i, N) { ans = gcd(ans, c[i + 1] - c[i]); }

  cout << ans << endl;
}