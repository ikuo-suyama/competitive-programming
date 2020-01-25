#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int, int> P;

int H, W;
vector<string> c;
vector<vector<bool>> reached;

/**
 * 深さ優先探索/DFS
 * Depth First Search
 */
void search(int x, int y) {
  if (x >= H || y >= W || x < 0 || y < 0) return;
  if (c[x][y] == '#' || reached[x][y]) return;
  reached[x][y] = true;

  search(x, y + 1);
  search(x + 1, y);
  search(x - 1, y);
  search(x, y - 1);
}

int main() {
  ifstream in("ac-ans-a/dfs_a.txt");
  cin.rdbuf(in.rdbuf());

  cin >> H >> W;
  vector<string> _c(H);
  rep(i, H) { cin >> _c[i]; }
  c = _c;

  P s, g;
  rep(i, H) rep(j, W) {
    if (c[i][j] == 's') s = make_pair(i, j);
    if (c[i][j] == 'g') g = make_pair(i, j);
  }
  vector<vector<bool>> _reached(H, vector<bool>(W, false));
  reached = _reached;

  search(s.first, s.second);

  cout << (reached[g.first][g.second] ? "Yes" : "No") << endl;
}