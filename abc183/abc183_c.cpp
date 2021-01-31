#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc183/abc183_c.txt"); \
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

int N, K;

int solve(vector<vector<int>> &g, unordered_set<int> &c, int cur, int sum) {
  if (c.size() == N - 1) {
    sum += g[cur][0];
    // printf("%d\n", sum);
    if (sum == K)
      return 1;
    else return 0;
  }

  int ans = 0;
  repi(i, 1, N) {
    if (c.count(i)) continue;
    unordered_set<int> t(c);
    t.insert(i);
    int tmp = sum;
    tmp += g[cur][i];
    ans += solve(g, t, i, tmp);
  }

  return ans;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  cin >> N >> K;

  vector<vector<int>> g(N, vector<int>(N, 0));
  rep(i, N) rep(j, N) {
    int x;
    cin >> x;
    g[i][j] = x;
    g[j][i] = x;
  }

  unordered_set<int> c;
  ll ans = solve(g, c, 0, 0);

  cout << ans << endl;
}