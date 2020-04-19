#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("abc163/abc163_e.txt"); \
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
const ll LINF = 1e18+100;
const int MOD = 1e9 + 7;

ll dp[2010][2010];

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  memset(dp, 0, 2010 * 2010 * sizeof(ll));

  int N;
  cin >> N;
  
  vector<int> c(N);
  rep(i, N) { cin >> c[i]; }

  rep(i, N+1) rep(j, N+1) {
    dp[i + 1][j] = max(dp[i][j],  abs(i + 1 - j) * c[j] - dp[i][j]);
  }

  ll ans = 0;
  rep(i, N+1) { ans = max(ans, dp[N+1][i]); }
  cout << ans << endl;
}