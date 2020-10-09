#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc121_c.txt"); \
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

  ll N, M;
  cin >> N >> M;

  vector<pl> c(N);
  rep(i, N) {
    ll a, b;
    cin >> a >> b;
    c[i] = make_pair(a, b);
  }
  sort(c.begin(), c.end());

  ll cnt = 0;
  ll ans = 0;
  rep(i, N) {
    ll a = c[i].first;
    ll b = c[i].second;
    if (cnt + b < M) {
      ans += a * b;
      cnt += b;
    } else {
      ans += (M - cnt) * a;
      break;
    }
  }

  cout << ans << endl;
}