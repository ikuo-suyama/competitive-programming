#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/arc091_a.txt"); \
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

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, M;
  cin >> N >> M;

  vector<vector<bool>> c(N, vector<bool>(M, true));
  rep(i, N) rep(j, M) {
    int is = max(0, i - 1);
    int ie = min(N - 1, i + 1);
    int js = max(0, j - 1);
    int je = min(M - 1, j + 1);
    repi(l, is, ie + 1) repi(k, js, je + 1) { c[l][k] = !c[l][k]; }
    rep(m, N) { print_vec(c[m]); }
    printf("\n");
  }

  ll h = N == 2 ? 0 : max(1, N - 2);
  ll w = M == 2 ? 0 : max(1, M - 2);

  cout << h * w << endl;
}