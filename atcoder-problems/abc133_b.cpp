#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/abc133_b.txt"); \
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

  int N, D;
  cin >> N >> D;
  
  vector<vector<int>> x(N, vector<int>(D, 0));
  rep(i, N) rep(j, D) { cin >> x[i][j]; }

  ll ans = 0;
  rep(i, N - 1) repi(j, i + 1, N) {
    int tmp = 0;
    rep(k, D) { tmp += pow(x[i][k] - x[j][k], 2); }
    int dis = sqrt(tmp);
    ans += pow(dis, 2) == tmp;
  }

  cout << ans << endl;
}