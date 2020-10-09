#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc168/abc168_d.txt"); \
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

void search_dijkstra(vector<int>& fixed, vector<vector<int>>& g,
                     map<P, int>& m) {
  // cost, to, from
  typedef tuple<int, int, ll> tpl;
  priority_queue<tpl, vector<tpl>, greater<tpl>> que;

  que.push(make_tuple(0, 0, 0));
  while (!que.empty()) {
    auto top = que.top();
    que.pop();
    int from = get<1>(top);
    if (fixed[from] != -1) continue;

    // 未確定のうち一番小さいものを確定
    ll now =  get<0>(top);
    ll _bef = get<2>(top);

    // fixed[from] = m.at(make_pair(_bef, from));
    fixed[from] = _bef;

    for (auto to : g[from]) {
      if (fixed[to] != -1) continue;
      que.push(make_tuple(now + 1, to, from));
    }
  }

  return;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, M;
  cin >> N >> M;

  vector<vector<int>> g(N);
  map<P, int> m;
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
    m.emplace(make_pair(a, b), i + 1);
    m.emplace(make_pair(b, a), i + 1);
  }

  vector<int> fixed(N, -1);
  search_dijkstra(fixed, g, m);
  rep(i, N) {
    if (fixed[i] == -1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  repi(i, 1, N) { cout << fixed[i] + 1 << endl; }
}