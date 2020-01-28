#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

/**
 * 動的計画法/DP Dynamic Programming
 * https://qiita.com/drken/items/a5e6fe22863b7992efdb
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
      N + 1, vector<vector<int>>(W + 1, vector<int>(K + 2, 0)));
  for (int i = 1; i < N; i++) {
    for (int w = 1; w <= W; w++) {
      for (int k = 1; k <= K; k++) {
        if (w >= A[i]) {
          dp[i + 1][w][k] =
              max({dp[i][w - A[i]][k] + B[i], dp[i][w][k - 1], dp[i][w][k]});
        } else {
          dp[i + 1][w][k] = max(dp[i][w][k], dp[i][w][k - 1]);
        }
      }
    }
  }

  cout << dp[N][W][K] << endl;
}