#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/arc080_b.txt"); \
  cin.rdbuf(in.rdbuf());
#else
#define INPUT_FILE
#endif
#define print_vec(v)                        \
  rep(l, v.size()) { cout << v[l] << " "; } \
  cout << endl;
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
typedef pair<ll, ll> pl;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

int W, H;
void dfs(int w, int h, int i, vector<vector<int>> &ans, vector<int> &col) {
  // printf("%d %d %d\n", w, h, i);
  if (w < 0 || w >= W || h < 0 || h >= H || ans[h][w] != 0) return;
  ans[h][w] = col[i];
  dfs(w + 1, h, i + 1, ans, col);
  dfs(w, h + 1, i + 1, ans, col);
  dfs(w - 1, h, i + 1, ans, col);
  dfs(w, h - 1, i + 1, ans, col);
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  cin >> H >> W;
  int N;
  cin >> N;

  vector<int> c(N);
  rep(i, N) { cin >> c[i]; }

  vector<int> col(H * W, 0);
  int j = 0, cur = 0;
  rep(i, H * W) {
    cur++;
    col[i] = j + 1;
    if (cur == c[j]) {
      cur = 0;
      j++;
    }
  }

  vector<vector<int>> ans(H, vector<int>(W, 0));
  dfs(0, 0, 0, ans, col);
  rep(i, H) { print_vec(ans[i]); }
}