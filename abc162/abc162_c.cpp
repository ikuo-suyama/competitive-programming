#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc162/abc162_c.txt"); \
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

ll _gcd(ll a, ll b) {
  if (b == 0) return a;
  return _gcd(b, a % b);
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  cin >> N;

  ll ans = 0;
  rep(i, N) rep(j, N) rep(k, N) { ans += _gcd(_gcd(i+1, j+1), k+1); }

  cout << ans << endl;
}