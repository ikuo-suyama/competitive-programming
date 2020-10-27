#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("abc166/abc166_c.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v) \
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
const ll LINF = 1e18+100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, M;
  cin >> N >> M;
  
  vector<int> h(N);
  rep(i, N) { cin >> h[i]; }

  vector<int> g(N, -1);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a] = max(g[a], h[b]);
    g[b] = max(g[b], h[a]);
  }

  ll ans = 0;
  rep(i, N) {
    if (g[i] == -1 || h[i] > g[i]) ans++;
  }

  cout << ans << endl;
}