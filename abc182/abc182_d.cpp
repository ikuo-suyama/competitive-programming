#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc182/abc182_d.txt"); \
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

  int N;
  cin >> N;

  vector<ll> c(N);
  rep(i, N) { cin >> c[i]; }

  vector<ll> sum(N, 0);
  vector<ll> maxx(N, 0);
  maxx[0] = max(c[0], (ll)0);
  sum[0] = c[0];

  int l = -1;
  repi(i, 1, N) {
    sum[i] = sum[i - 1] + c[i];
    maxx[i] = max(maxx[i - 1], sum[i]);
  }

  ll ans = 0;
  ll cur = 0;
  rep(i, N) {
    ans = max(ans, cur + maxx[i]);
    cur += sum[i];
  }

  cout << ans << endl;

}