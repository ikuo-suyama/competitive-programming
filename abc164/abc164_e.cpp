#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc164/abc164_e.txt"); \
  cin.rdbuf(in.rdbuf());
#else
#define INPUT_FILE
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> pl;
typedef tuple<ll, ll, ll> tl;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

ll N, M, S;
vector<ll> C;
vector<ll> D;

void search_dijkstra(vector<ll>& fixed, vector<vector<int>>& g, map<P, ll>& a,
                     map<P, ll>& b) {
  // 島iに到達時の銀貨
  vector<ll> sv(N, 0);
  sv[0] = S;
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
      // TODO: 次の島へのコスト
      P key = make_pair(from, to);
      ll time = b.at(key);
      ll cost = a.at(key);

      if (sv[from] < cost) {
        ll out = cost - sv[from];
        ll n = ceil((float)out / C[from]);
        sv[to] = C[from] * n - out;
        time += n * D[from];
      } else {
        sv[to] = sv[from] - cost;
      }

      que.push(make_pair(time, to));
    }
  }

  return;
}

/**
 * 拡張ダイクストラ
 * 辺の重みが変わる/補充 DPしながら最短経路
 * 各頂点で所持金がX円である状態を拡充する
 * https://drken1215.hatenablog.com/entry/2020/04/27/190000
 * #graph #dijkstra
 */
int main() {
  INPUT_FILE CIN_OPTIMIZE;

  cin >> N >> M >> S;

  vector<vector<tl>> g(N, vector<tl>(0));
  rep(i, M) {
    int u, v, a, b;
    cin >> u >> v >> a >> b;
    u--;
    v--;
    // v, time, cost
    g[u].push_back(make_tuple(v, a, b));
    g[v].push_back(make_tuple(v, a, b));
 }

  C = vector<ll>(N, 0);
  D = vector<ll>(N, 0);
  rep(i, N) { cin >> C[i] >> D[i]; }

  vector<ll> t(N, -1);
  search_dijkstra(t, g);

  for(auto i : t) {
    cout << i << endl;
  }
}