#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc129_c.txt"); \
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

int memo(vector<ll>& dp, int i, vector<ll>& c) {
  if (i == 0) return 1;
  if (i < 0) return 0;
  if (dp[i] != -1) return dp[i];

  if (!c[i]) {
    dp[i] = memo(dp, i - 1, c) + memo(dp, i - 2, c);
  } else {
    dp[i] = 0;
  }
  return dp[i] %= MOD;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, M;
  cin >> N >> M;

  vector<ll> c(N + 1, 0);
  rep(i, M) {
    ll j;
    cin >> j;
    c[j]++;
  }

  vector<ll> dp(N + 1, -1);

  ll ans = memo(dp, N, c);
  cout << ans << endl;
}