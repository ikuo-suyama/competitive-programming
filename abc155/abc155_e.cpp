#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int dp[1000005][2];

int main() {
  ifstream in("abc155/abc155_e.txt");
  cin.rdbuf(in.rdbuf());

  rep(i, 1000005) rep(j, 2) { dp[i][j] = 100100100; }

  string S;
  cin >> S;
  reverse(S.begin(), S.end());
  // 最大桁を一つ追加
  S += '0';

  int N = S.size();
  dp[0][0] = 0;
  rep(i, N) rep(j, 2) {
    rep(a, 10) {
      int x = S[i] - '0';
      x += j;
      int b = a - x;
      int ni = i + 1;
      int nj = 0;
      if (b < 0) {
        b += 10;
        nj = 1;
      }
      dp[ni][nj] = min(dp[ni][nj], dp[i][j] + a + b);
    }
  }

  cout << dp[N][0] << endl;
}