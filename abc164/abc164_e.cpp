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

// [辺i][所持金S] のときの最短時間
ll dp[50][2500 + 1];

void solve(vector<vector<tl>>& g) {
  ll MAX = 2500;
  S = min(S, MAX);

  rep(i, 50) rep(j, 2501) dp[i][j] = LINF;
  dp[0][S] = 0;

  // 未確定なもののQueue; time, vertex, money
  priority_queue<tl, vector<tl>, greater<tl>> que;
  que.push(make_tuple(0, 0, S));

  while (!que.empty()) {
    // 構造化束縛 C++17
    auto [time, from, money] = que.top();
    // printf("time:%lld from:%lld s:%lld\n", time, from, money);
    que.pop();
    if (dp[from][money] < time) continue;

    // 換金（補充）
    if (money + C[from] <= MAX) {
      ll ntime = time + D[from];
      ll nmoney = money + C[from];
      if (dp[from][nmoney] > ntime) {
        // printf(" >> GET! time:%lld from:%lld s:%lld\n", ntime, from, nmoney);
        dp[from][nmoney] = ntime;
        que.push(make_tuple(ntime, from, nmoney));
      }
    }

    // 移動
    for (auto to_edge : g[from]) {
      auto [to, to_time, to_cost] = to_edge;

      // お金が足りないので通れない
      if (money < to_cost) continue;

      ll ntime = time + to_time;
      ll nmoney = money - to_cost;

      // printf("    to:%lld dp:%lld ntime:%lld\n", to, dp[to][nmoney], ntime);
      if (dp[to][nmoney] > ntime) {
        // printf(" >> GO! time:%lld to:%lld s:%lld\n", ntime, to, nmoney);
        dp[to][nmoney] = ntime;
        que.push(make_tuple(ntime, to, nmoney));
      }
    }
  }

  repi(i, 1, N) {
    ll ans = LINF;
    rep(j, MAX + 1) { ans = min(ans, dp[i][j]); }
    cout << ans << endl;
  }
}

/**
 * 拡張ダイクストラ
 * 辺の重みが変わる/補充 DPしながら最短経路
 * 各頂点で所持金がX円である状態を拡充する
 * https://drken1215.hatenablog.com/entry/2020/04/27/190000
 *
 * #graph #dijkstra #dp
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
    g[u].push_back(make_tuple(v, b, a));
    g[v].push_back(make_tuple(u, b, a));
  }

  C = vector<ll>(N, 0);
  D = vector<ll>(N, 0);
  rep(i, N) { cin >> C[i] >> D[i]; }

  solve(g);
}