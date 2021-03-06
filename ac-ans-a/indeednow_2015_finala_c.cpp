#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ifstream in("ac-ans-a/indeednow_2015_finala_c.txt");
  cin.rdbuf(in.rdbuf());

  int N, M;
  cin >> N >> M;

  vector<vector<vector<ll>>> dp(110,
                                vector<vector<ll>>(110, vector<ll>(110, 0)));

  rep(i, N) {
    int a, b, c;
    ll w;
    cin >> a >> b >> c >> w;
    dp[a][b][c] = max(dp[a][b][c], w);
  }

  rep(i, 101) rep(j, 101) rep(k, 101) {
    if (i) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
    if (j) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
    if (k) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
  }
  // rep2(j, 1, 100 + 1) rep2(k, 1, 100 + 1) rep2(l, 1, 100 + 1) {
  //   dp[j][k][l] =
  //       max({dp[j][k][l], dp[j - 1][k][l], dp[j][k - 1][l], dp[j][k][l -
  //       1]});
  // }

  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c;

    cout << dp[a][b][c] << endl;
  }
}