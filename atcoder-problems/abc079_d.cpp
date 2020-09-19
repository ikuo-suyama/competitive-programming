#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc079_d.txt"); \
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

int N = 10;
int findMin(vector<vector<int>> &g, int i) {
  priority_queue<P, vector<P>, greater<P>> que;
  vector<int> c(N, -1);
  que.push({0, i});
  while (que.size()) {
    auto p = que.top();
    que.pop();
    int j = p.second;
    if (c[j] != -1) continue;
    int cost = p.first;
    c[j] = cost;
    rep(l, N) {
      if (l == j) continue;
      que.push({cost + g[j][l], l});
    }
  }
  return c[1];
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int H, W;
  cin >> H >> W;

  vector<vector<int>> g(N, vector<int>(N, 0));
  rep(i, N) rep(j, N) { cin >> g[i][j]; }

  vector<vector<int>> m(H, vector<int>(W, 0));
  rep(i, H) rep(j, W) { cin >> m[i][j]; }

  vector<int> c(N, 0);
  rep(i, N) { c[i] = findMin(g, i); }

  ll ans = 0;
  rep(i, H) rep(j, W) {
    if (m[i][j] != -1) {
      ans += c[m[i][j]];
    }
  }

  cout << ans << endl;
}