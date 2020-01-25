#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

/**
 * 幅優先探索/BFS
 * Breadth First Search
 */

int main() {
  ifstream in("ac-ans-a/abc007_3.txt");
  cin.rdbuf(in.rdbuf());

  int R, C;
  cin >> R >> C;

  int sy, sx, gy, gx;
  cin >> sy >> sx >> gy >> gx;
  sy--;
  sx--;
  gy--;
  gx--;

  vector<string> c(R);
  rep(i, R) { cin >> c[i]; }

  vector<vector<int>> r(R, vector<int>(C, -1));
  queue<tuple<int, int, int>> que;

  que.push(make_tuple(sy, sx, 0));
  do {
    tuple<int, int, int> t = que.front();
    que.pop();
    int y = get<0>(t), x = get<1>(t), cnt = get<2>(t);

    vector<P> p = {make_pair(y + 1, x), make_pair(y - 1, x),
                   make_pair(y, x + 1), make_pair(y, x - 1)};
    rep(i, 4) {
      int y = p[i].first, x = p[i].second;
      if (y < R && x < C && r[y][x] == -1 && c[y][x] != '#') {
        r[y][x] = cnt + 1;
        que.push(make_tuple(y, x, cnt + 1));
      }
    };

  } while (!que.empty());

  cout << r[gy][gx] << endl;
}