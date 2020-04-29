#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/abc088_c.txt"); \
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

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N = 3;
  
  vector<vector<int>> c(N + 1, vector<int>(N + 1, 0));
  rep(i, N) rep(j, N) { cin >> c[i + 1][j + 1]; }

  bool ok = true;
  ok &= (c[1][1] - c[2][1] == c[1][2] - c[2][2] && c[1][2] - c[2][2] == c[1][3] - c[2][3]);
  ok &= (c[2][1] - c[3][1] == c[2][2] - c[3][2] && c[2][2] - c[3][2] == c[2][3] - c[3][3]);
  ok &= (c[1][1] - c[3][1] == c[1][2] - c[3][2] && c[1][2] - c[3][2] == c[1][3] - c[3][3]);

  ok &= (c[1][1] - c[1][2] == c[2][1] - c[2][2] && c[2][1] - c[2][2] == c[3][1] - c[3][2]);
  ok &= (c[1][2] - c[1][3] == c[2][2] - c[2][3] && c[2][2] - c[2][3] == c[3][2] - c[3][3]);
  ok &= (c[1][1] - c[1][3] == c[2][1] - c[2][3] && c[2][1] - c[2][3] == c[3][1] - c[3][3]);

  cout << (ok ? "Yes" : "No") << endl;
}