#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int N, M;
vector<vector<int>> g;

void searchGraph(int i, set<int> fill, ll *cnt) {
  vector<int> path = g[i];
  fill.insert(i);
  if (fill.size() == N) {
    // 回りきって最後
    *cnt += 1;
    return;
  }
  rep(i, path.size()) {
    int next = path[i];
    if (fill.find(next) == fill.end()) {
      searchGraph(next, fill, cnt);
    }
  }
}

int main() {
  ifstream in("ac-ans-a/abc054_c.txt");
  cin.rdbuf(in.rdbuf());

  cin >> N >> M;

  g = vector<vector<int>>(M + 1, vector<int>(0));
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  ll cnt = 0;
  set<int> fill;
  searchGraph(1, fill, &cnt);

  cout << cnt << endl;
}