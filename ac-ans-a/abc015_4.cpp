#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

/**
 * 動的計画法/DP Dynamic Programming
 * https://qiita.com/drken/items/a5e6fe22863b7992efdb
 */
/* dp[i+1][j+1][k]= i番目以下のスクショからj個以下選び、幅kがWを超えない
   スクショを選んだ時の重要度のmax
   i番目を取らないとき
   dp[i+1][j+1][k] = max(dp[i][j+1][k],dp[i][j][k])
   i番目を取る時
   dp[i+1][j+1][k] = max(dp[i][j+1][k],dp[i][j][k],dp[i][j][k-A[i]] + B[i])
*/
int main() {
  ifstream in("ac-ans-a/abc015_4.txt");
  cin.rdbuf(in.rdbuf());

  int W, N, K;
  cin >> W >> N >> K;

  vector<int> A(N);
  vector<int> B(N);
  rep(i, N) { cin >> A[i] >> B[i]; }

  vector<vector<vector<int>>> dp(
      N + 10, vector<vector<int>>(K + 10, vector<int>(W + 10, 0)));
  for (int i = 0; i < N; i++) {
    for (int k = 0; k < K; k++) {
      for (int w = 0; w <= W; w++) {
        // printf(
        //     "i: %d, k:%d, w:%d | dp[i][k][w - A[i]] + B[i]: %d, dp[i][k + "
        //     "1][w]: %d, dp[i][k][w]d: %d\n",
        //     i, k, w, dp[i][k][w - A[i]] + B[i], dp[i][k + 1][w],
        //     dp[i][k][w]);

        if (w >= A[i]) {
          dp[i + 1][k + 1][w] =
              max({dp[i][k][w - A[i]] + B[i], dp[i][k + 1][w], dp[i][k][w]});
        } else {
          dp[i + 1][k + 1][w] = max(dp[i][k + 1][w], dp[i][k][w]);
        }
      }
    }
  }

  cout << dp[N][K][W] << endl;
}