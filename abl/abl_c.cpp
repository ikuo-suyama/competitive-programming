#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE              \
  ifstream in("abl/abl_c.txt"); \
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

#include <atcoder/dsu>

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, M;
  cin >> N >> M;

  atcoder::dsu d(N);

  vector<int> a(M);
  vector<int> b(M);
  rep(i, M) {
    int _a, _b;
    cin >> _a >> _b;
    _a--;
    _b--;
    a[i] = _a;
    b[i] = _b;
  }
  rep(i, M) { d.merge(a[i], b[i]); }

  ll ans = 0;
  int leader = d.leader(0);
  rep(i, N) {
    if (!d.same(leader, i)) {
      d.merge(leader, i);
      leader = d.leader(i);
      ans++;
    }
  }

  cout << ans << endl;
}