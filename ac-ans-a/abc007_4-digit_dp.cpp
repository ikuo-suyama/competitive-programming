#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;


ll solve(const string& N) {
  // [桁数][N未満フラグ][4 || 9フラグ]
  ll dp[32][2][2] = {};
  int L = N.size();
  dp[0][0][0] = 1;
  rep(i, L) {
    int D = N[i] - '0';
    rep(j, 2) rep(k, 2) {
      for (int l = 0; l <= (j ? 9 : D); l++) {
        // printf("%d, %d: %d %d %d\n", i, D, j, k, l);
        dp[i + 1][j || l < D][k || l == 4 || l == 9] += dp[i][j][k];
      }
    }
  }
  return dp[L][0][1] + dp[L][1][1];
}
/**
 * 桁DP / Disit DP
 * https://torus711.hatenablog.com/entry/20150423/1429794075
 * https://qiita.com/nomikura/items/bfed11ad771db76f43ab
 */
int main() {
  ifstream in("ac-ans-a/abc007_4-digit_dp.txt");
  cin.rdbuf(in.rdbuf());

  ll A, B;
  cin >> A >> B;

  ll cnt = solve(to_string(B)) - solve(to_string(A - 1));
  cout << cnt << endl;
}