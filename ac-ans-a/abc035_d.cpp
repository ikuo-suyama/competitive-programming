#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

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

  // M本の有向グラフ
  vector<vector<int>> g(M);
  map<P, int> cm;
  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    g[a].push_back(b);
    cm.emplace(make_pair(a, b), c);
  }

  // ダイクストラ法：各辺への最短経路を求める
  vector<ll> fixed(N, -1);
  
  // auto cmp = [](pair<int, ll> a, pair<int, ll> b) { return a.second < b.second; };
  // 未確定なもののQueue; (かかる時間, 島i)
  priority_queue<pair<ll, int>> que;

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
      que.push(make_pair(now + cm.at(make_pair(from, to)), to));
    }
  }

  ll cnt = 0;
  cout << cnt << endl;
}