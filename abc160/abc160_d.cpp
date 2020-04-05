#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc160/abc160_d.txt"); \
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

int N;
void dijkstra(int i, vector<vector<int>> &g, vector<vector<int>> &f,
              vector<int> &cnt) {
  priority_queue<P, vector<P>, greater<P>> que;
  vector<int> fixed(N, -1);
  for (int j : g[i]) {
    que.push(make_pair(1, j));
  }
  while (!que.empty()) {
    P top = que.top();
    que.pop();

    int nexti = top.second;
    int currentCost = top.first;

    if (fixed[nexti] != -1) continue;
    fixed[nexti] = 1;

    if (f[i][nexti] == 0) {
      // 距離の組み合わせ個数をカウント
      f[i][nexti] = 1;
      f[nexti][i] = 1;
      cnt[currentCost - 1] += 1;
    }

    // printf("i:%d next: %d cst:%d cnt:%d\n", i, nexti, currentCost,
    //        cnt[currentCost - 1]);
    for (int to : g[nexti]) {
      if (i == to) continue;
      que.push(make_pair(currentCost + 1, to));
    }
  }
  return;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int X, Y;
  cin >> N >> X >> Y;

  vector<vector<int>> g(N, vector<int>(0));
  rep(i, N - 1) {
    g[i].push_back(i + 1);
    g[i + 1].push_back(i);
  }
  g[X - 1].push_back(Y - 1);
  g[Y - 1].push_back(X - 1);

  vector<vector<int>> fixed(N, vector<int>(N, 0));
  vector<int> cnt(N, 0);
  rep(i, N - 1) { dijkstra(i, g, fixed, cnt); }

  rep(i, N - 1) { cout << cnt[i] << endl; }
}