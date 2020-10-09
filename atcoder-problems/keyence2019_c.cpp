#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                   \
  ifstream in("atcoder-problems/keyence2019_c.txt"); \
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

  vector<ll> a(N);
  vector<ll> b(N);
  vector<ll> c(N);
  ll totalA = 0, totalB = 0;
  rep(i, N) {
    cin >> a[i];
    totalA += a[i];
  }
  rep(i, N) {
    cin >> b[i];
    totalB += b[i];
  }
  if (totalA < totalB) {
    cout << -1 << endl;
    return 0;
  }

  ll ans = 0;
  ll minus = 0;
  rep(i, N) {
    c[i] = a[i] - b[i];
    if (c[i] < 0) {
      ans++;
      minus += c[i];
    }
  }
  sort(c.rbegin(), c.rend());

  for (auto plus : c) {
    if (minus >= 0) break;
    minus += plus;
    ans++;
  }

  cout << ans << endl;
}