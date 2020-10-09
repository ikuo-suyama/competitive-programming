#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc143/abc143_e.txt"); \
  cin.rdbuf(in.rdbuf());
#else
#define INPUT_FILE
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

int N, M;
ll L;

void solve(int s, int t, vector<vector<int>> &g, map<P, ll> &m) {
  // printf("s:%d t:%d\n", s, t);
  vector<ll> fixed(N, -1);

  // 補給回数, vertex, 残燃料
  typedef tuple<int, int, ll> tpl;
  priority_queue<tpl, vector<tpl>, greater<tpl>> que;

  que.push(make_tuple(0, s, L));
  while (!que.empty()) {
    auto top = que.top();
    que.pop();

    int cnt = get<0>(top);
    int from = get<1>(top);
    ll rest = get<2>(top);

    if (fixed[from] != -1) continue;

    // 未確定のうち一番小さいものを確定
    fixed[from] = cnt;

    for (auto to : g[from]) {
      if (fixed[to] != -1) continue;

      int ncnt = cnt;
      ll nrest = rest;

      int fuel = m[make_pair(from, to)];
      nrest -= fuel;
      // 給油
      if (nrest < 0) {
        ncnt++;
        nrest = L - fuel;
      }
      // printf(" from:%d to:%d cnt:%d rest:%d fuel:%d\n", from, to, ncnt, nrest, fuel);
      que.push(make_tuple(ncnt, to, nrest));
    }
  }

  cout << fixed[t] << endl;
  return;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  cin >> N >> M >> L;

  vector<vector<int>> g(N, vector<int>(0));
  map<P, ll> m;
  rep(i, M) {
    int a, b;
    ll c;

    cin >> a >> b >> c;
    a--;
    b--;
    if (c > L) continue;
    g[a].push_back(b);
    g[b].push_back(a);
    m[make_pair(a, b)] = c;
    m[make_pair(b, a)] = c;
  }

  int Q;
  cin >> Q;
  rep(i, Q) {
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    solve(s, t, g, m);
  }
}