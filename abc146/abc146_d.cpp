#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc146/abc146_d.txt"); \
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
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

void dfs(int from, int color, int &maxC, vector<vector<int>> &g, map<P, int> &colors) {
  int c = 1;
  for (auto to : g[from]) {
    if (c == color) c++;
    if (colors.find(make_pair(from, to)) == colors.end()) {
      colors.emplace(make_pair(from, to), c);
      colors.emplace(make_pair(to, from), c);
      dfs(to, c, maxC, g, colors);
      c = c + 1 > maxC ? 1 : c + 1;
    }
  }
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  cin >> N;

  vector<P> c(N-1);
  vector<vector<int>> g(N, vector<int>(0));
  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    c[i] = make_pair(a, b);

    g[a].push_back(b);
    g[b].push_back(a);
  }

  int max = 0;
  int start = 0;
  rep(i, N) {
    if (g[i].size() > max) {
      max = g[i].size();
      start = i;
    }
  }

  map<P, int> colors;

  colors.emplace(make_pair(start, g[start][0]), 1);
  colors.emplace(make_pair(g[start][0], start), 1);
  dfs(start, 1, max, g, colors);
  dfs(g[start][0], 1, max, g, colors);

  cout << max << endl;
  rep(i, N-1) { cout << colors.at(c[i]) << endl; }
}