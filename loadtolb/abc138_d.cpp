#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                      \
  ifstream in("loadtolb/abc138_d.txt"); \
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

vector<ll> c;
vector<bool> seen;
vector<vector<int>> g;

void dfs(int i) {
  // すでに訪れたところ -- 逆流防止
  seen[i] = true;
  for (auto j : g[i]) {
    if (seen[j] == true) continue;
    // 自分の子供には必ず、自分に設定された点が加算される(累積)
    c[j] += c[i];
    dfs(j);
  }
}

/**
 * 一回だけ全探索する DFS
 */
int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, Q;
  cin >> N >> Q;

  c = vector<ll>(N, 0);
  seen = vector<bool>(N, false);
  g = vector<vector<int>>(N, vector<int>(0));
  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  rep(i, Q) {
    int q, x;
    cin >> q >> x;
    q--;
    c[q] += x;
  }

  // rootが1は保証されている
  dfs(0);
  rep(i, N) { cout << c[i] << " "; }
}