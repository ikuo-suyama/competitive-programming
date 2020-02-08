#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

typedef pair<ll, int> pl;

void search_dijkstra(vector<ll>& fixed, vector<vector<int>>& g,
                     map<P, int>& m) {
  // 未確定なもののQueue; (かかる時間, 島i)
  priority_queue<pl, vector<pl>, greater<pl>> que;

  que.push(make_pair(0, 0));
  while (!que.empty()) {
    auto top = que.top();
    que.pop();
    int from = top.second;
    if (fixed[from] != -1) continue;

    // 未確定のうち一番小さいものを確定
    ll now = top.first;
    fixed[from] = now;

    for (auto to : g[from]) {
      if (fixed[to] != -1) continue;
      que.push(make_pair(now + m.at(make_pair(from, to)), to));
    }
  }

  return;
}

/**
 * Dijkstra / ダイクストラ法
 */
int main() {
  ifstream in("ac-ans-a/abc035_d.txt");
  cin.rdbuf(in.rdbuf());

  int N, M;
  ll T;
  cin >> N >> M >> T;

  // 街iの価値/min
  vector<int> v(N);
  rep(i, N) { cin >> v[i]; }

  vector<vector<int>> g(N);
  vector<vector<int>> rev_g(N);
  map<P, int> cm, rev_cm;
  // M本の有向グラフ
  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    g[a].push_back(b);
    rev_g[b].push_back(a);

    cm.emplace(make_pair(a, b), c);
    rev_cm.emplace(make_pair(b, a), c);
  }

  // ダイクストラ法：各辺への最短経路を求める
  vector<ll> fixed(N, -1);
  search_dijkstra(fixed, g, cm);

  vector<ll> rev_fixed(N, -1);
  search_dijkstra(rev_fixed, rev_g, rev_cm);

  ll cnt = 0;
  cout << cnt << endl;
}