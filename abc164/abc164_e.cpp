#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("abc164/abc164_e.txt"); \
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
const ll LINF = 1e18+100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  ll N, M, S;
  cin >> N >> M >> S;
  
  vector<vector<int>> g(N, vector<int>(0));
  // 料金
  map<P, int> A;
  // かかる時間
  map<P, int> B;

  rep(i, M) { 
    int u, v, a, b;
    cin >> u >> v >> a >> b;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);

    A.emplace(P(u, v), a);
    A.emplace(P(v, u), a);
    B.emplace(P(v, u), b);
    B.emplace(P(v, u), b);
  }

  vector<int> c(N);
  rep(i, N) { cin >> c[i]; }

  ll cnt = 0;
  cout << cnt << endl;
}