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

  vector<vector<int>> dp(N + 10, vector<int>(W + 10, 0));
  for (int i = 1; i < N; i++) {
    for (int w = 1; w <= W; w++) {
      if (w >= A[i]) {
        dp[i + 1][w] = max(dp[i][w - A[i]] + B[i], dp[i][w]);
      } else {
        dp[i + 1][w] = dp[i][w];
      }
    }
  }

  cout << dp[N][W] << endl;
}