#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int N, M;
vector<vector<int>> g;

void searchGraph(int i, vector<bool>& fill, ll& cnt) {
  vector<int> path = g[i];
  bool all_visited = true;
  rep(i, N) { all_visited &= fill[i]; }
  if (all_visited) {
    cnt++;
    return;
  }
  rep(i, path.size()) {
    int next = path[i];
    if (!fill[next]) {
      fill[next] = true;
      searchGraph(next, fill, cnt);
      fill[next] = false;
    }
  }
}

int main() {
  ifstream in("ac-ans-a/abc054_c.txt");
  cin.rdbuf(in.rdbuf());

  cin >> N >> M;

  g = vector<vector<int>>(M, vector<int>(0));
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  ll cnt = 0;
  vector<bool> fill(N, false);
  fill[0] = true;
  searchGraph(0, fill, cnt);

  cout << cnt << endl;
}