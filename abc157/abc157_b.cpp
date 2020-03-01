#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc157/abc157_b.txt"); \
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
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  vector<vector<int>> c(3, vector<int>(3, 0));
  rep(i, 3) rep(j, 3) { cin >> c[i][j]; }

  int N;
  cin >> N;

  vector<int> b(N);
  vector<vector<int>> bingo(3, vector<int>(3, 0));
  rep(i, N) {
    cin >> b[i];
    rep(j, 3) rep(k, 3) {
      if (bingo[j][k] == 0) {
        bingo[j][k] = (c[j][k] == b[i]);
        // printf("%d %d %d: %d %d %d\n", j, k, c[j][k], b[i], c[j][k] == b[i],
        //        bingo[j][k]);
      }
    }
  }

  bool ans = false;
  ans = ans | (bingo[0][0] && bingo[0][1] && bingo[0][2]);
  ans = ans | (bingo[1][0] && bingo[1][1] && bingo[1][2]);
  ans = ans | (bingo[2][0] && bingo[2][1] && bingo[2][2]);

  ans = ans | (bingo[0][0] && bingo[1][0] && bingo[2][0]);
  ans = ans | (bingo[0][1] && bingo[1][1] && bingo[2][1]);
  ans = ans | (bingo[0][2] && bingo[1][2] && bingo[2][2]);

  ans = ans | (bingo[0][0] && bingo[1][1] && bingo[2][2]);
  ans = ans | (bingo[0][2] && bingo[1][1] && bingo[2][0]);

  cout << (ans ? "Yes" : "No") << endl;
}