#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                     \
  ifstream in("atcoder-problems/ddcc2020_qual_c.txt"); \
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

int H, W, K;
void w_dfs(vector<vector<int>> &ans, int i, int j) {
  if (ans[i][j] == 0) return;
  if (j - 1 >= 0 && ans[i][j - 1] == 0) {
    ans[i][j - 1] = ans[i][j];
    w_dfs(ans, i, j - 1);
  }
  if (j + 1 < W && ans[i][j + 1] == 0) {
    ans[i][j + 1] = ans[i][j];
    w_dfs(ans, i, j + 1);
  }
}

void h_dfs(vector<vector<int>> &ans, int i, int j) {
  if (ans[i][j] == 0) return;
  if (i - 1 >= 0 && ans[i - 1][j] == 0) {
    ans[i - 1][j] = ans[i][j];
    h_dfs(ans, i - 1, j);
  }
  if (i + 1 < H && ans[i + 1][j] == 0) {
    ans[i + 1][j] = ans[i][j];
    h_dfs(ans, i + 1, j);
  }
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  cin >> H >> W >> K;

  vector<vector<char>> c(H, vector<char>(W, ' '));
  vector<vector<int>> ans(H, vector<int>(W, 0));
  int cnt = 0;
  rep(i, H) rep(j, W) {
    cin >> c[i][j];
    if (c[i][j] == '#') ans[i][j] = ++cnt;
  }

  rep(i, H) rep(j, W) { w_dfs(ans, i, j); }
  rep(i, H) rep(j, W) { h_dfs(ans, i, j); }

  rep(i, H) {
    rep(j, W) { cout << ans[i][j] << ' '; }
    cout << endl;
  }

  return 0;
}