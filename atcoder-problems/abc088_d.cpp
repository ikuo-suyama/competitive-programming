#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc088_d.txt"); \
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

int H, W;

void dfs(vector<vector<char>> &c, vector<vector<int>> &memo, int i, int j,
         int cnt) {
  if (memo[i][j] != -1 && memo[i][j] <= cnt) return;

  memo[i][j] = cnt;
  if (i + 1 < H && c[i + 1][j] == '.') dfs(c, memo, i + 1, j, cnt + 1);
  if (i - 1 >= 0 && c[i - 1][j] == '.') dfs(c, memo, i - 1, j, cnt + 1);
  if (j + 1 < W && c[i][j + 1] == '.') dfs(c, memo, i, j + 1, cnt + 1);
  if (j - 1 >= 0 && c[i][j - 1] == '.') dfs(c, memo, i, j - 1, cnt + 1);
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  cin >> H >> W;

  vector<vector<char>> c(H, vector<char>(W, 0));
  vector<vector<int>> memo(H, vector<int>(W, -1));
  int black = 0;
  rep(i, H) rep(j, W) {
    cin >> c[i][j];
    black += (c[i][j] == '#');
  }

  dfs(c, memo, 0, 0, 0);

  if (memo[H - 1][W - 1] == -1) {
    cout << -1 << endl;
  } else {
    cout << max(0, (H * W - black) - memo[H - 1][W - 1] - 1) << endl;
  }
}