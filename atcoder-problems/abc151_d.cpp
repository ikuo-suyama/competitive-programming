#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc151_d.txt"); \
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
int solve(vector<vector<char>> &c, P s) {
  priority_queue<pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>>> que;
  que.push({0, s});

  vector<vector<int>> m(H, vector<int>(W, -1));
  int _max = -1;
  while (que.size()) {
    auto val = que.top();
    que.pop();

    int cnt = val.first;

    int i = val.second.first;
    int j = val.second.second;
    if (m[i][j] != -1) continue;
    _max = max(_max, cnt);

    m[i][j] = cnt;
    if (i - 1 >= 0 && c[i - 1][j] == '.') que.push({cnt + 1, {i - 1, j}});
    if (i + 1 < H && c[i + 1][j] == '.') que.push({cnt + 1, {i + 1, j}});
    if (j - 1 >= 0 && c[i][j - 1] == '.') que.push({cnt + 1, {i, j - 1}});
    if (j + 1 < W && c[i][j + 1] == '.') que.push({cnt + 1, {i, j + 1}});
  }
  return _max;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  cin >> H >> W;

  vector<vector<char>> c(H, vector<char>(W));
  rep(i, H) rep(j, W) { cin >> c[i][j]; }

  int ans = 0;

  rep(i, H) rep(j, W) {
    if (c[i][j] == '#') continue;
    int tmp = solve(c, {i, j});
    // printf("%d %d/ cnt:%d\n", i, j, tmp);
    ans = max(ans, tmp);
  }

  cout << ans << endl;
}