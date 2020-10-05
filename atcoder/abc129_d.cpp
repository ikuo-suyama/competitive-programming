#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                     \
  ifstream in("atcoder/abc129_d.txt"); \
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
int checki(vector<vector<char>> &c, vector<vector<int>> &m, int i, int j,
           int cnt) {
  if (m[i][j] != -1) return m[i][j];
  if (c[i][j] == '#') {
    return m[i][j] = cnt;
  }
  cnt++;
  if (i + 1 < H) {
    return m[i][j] = checki(c, m, i + 1, j, cnt);
  }
  return m[i][j] = cnt;
}

int checkj(vector<vector<char>> &c, vector<vector<int>> &m, int i, int j,
           int cnt) {
  if (m[i][j] != -1) return m[i][j];
  if (c[i][j] == '#') {
    return m[i][j] = cnt;
  }
  cnt++;
  if (j + 1 < W) {
    return m[i][j] = checkj(c, m, i, j + 1, cnt);
  }
  return m[i][j] = cnt;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  cin >> H >> W;

  vector<vector<char>> c(H, vector<char>(W, 0));
  vector<vector<int>> mi(H, vector(W, -1));
  vector<vector<int>> mj(H, vector(W, -1));
  rep(i, H) rep(j, W) { cin >> c[i][j]; }

  int ans = 0;
  rep(i, H) {
    rep(j, W) {
      int tmp = checki(c, mi, i, j, 0) + checkj(c, mj, i, j, 0);
      ans = max(ans, tmp);
      // printf("%d %d :%d\n", i, j, tmp);
    }
  }

  cout << ans - 1 << endl;
}