#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc135_c.txt"); \
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

  vector<ll> a(N + 1);
  rep(i, N + 1) { cin >> a[i]; }
  vector<ll> b(N);
  rep(i, N) { cin >> b[i]; }

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  ll ans = 0;
  rep(i, N) {
    ll _a = a[i];
    ll _b = b[i];
    ans += min(_a, _b);
    a[i] = max(_a - _b, (ll)0);
    b[i] = max(_b - _a, (ll)0);
    if (b[i] != 0) {
      ll _a = a[i + 1];
      ll _b = b[i];
      ans += min(_a, _b);
      a[i + 1] = max(_a - _b, (ll)0);
      b[i] = max(_b - _a, (ll)0);
    }
  }

  cout << ans << endl;
}