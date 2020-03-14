#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                         \
  ifstream in("loadtolb/joi2008yo_f.txt"); \
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

typedef pair<ll, int> pl;
int N;

vector<int> search_min(int s, vector<vector<int>> &g, map<P, ll> &cost) {
  vector<int> c(N, -1);
  // cost, to の配列
  priority_queue<pl, vector<pl>, greater<pl>> que;

  // ダイクストラ法で最も安い航路を検索
  que.push(make_pair(0, s));
  while (!que.empty()) {
    pl top = que.top();
    que.pop();
    int from = top.second;

    if (c[from] != -1) continue;
    // 未確定のうち最小
    c[from] = top.first;

    for (auto to : g[from]) {
      if (c[to] != -1) continue;
      ll cost_to = cost.at(make_pair(from, to));
      que.push(make_pair(c[from] + cost_to, to));
    }
  }
  return c;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int K;
  cin >> N >> K;

  vector<vector<int>> g(N, vector<int>(0));
  map<P, ll> cost;
  rep(i, K) {
    int z;
    cin >> z;
    if (z == 0) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      auto min_costs = search_min(a, g, cost);
      cout << min_costs[b] << endl;
    } else {
      int c, d;
      ll e;
      cin >> c >> d >> e;
      c--;
      d--;
      g[c].push_back(d);
      g[d].push_back(c);
      ll new_cost = e;
      if (cost[make_pair(c, d)] != 0) {
        new_cost = min(cost[make_pair(c, d)], e);
      }
      cost[make_pair(c, d)] = new_cost;
      cost[make_pair(d, c)] = new_cost;
    }
  }
}