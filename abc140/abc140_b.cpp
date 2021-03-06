#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc140/abc140_b.txt"); \
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

  vector<int> a(N);
  vector<int> b(N);
  vector<int> c(N - 1);
  rep(i, N) {
    cin >> a[i];
    a[i]--;
  }
  rep(i, N) { cin >> b[i]; }
  rep(i, N - 1) { cin >> c[i]; }

  ll ans = 0;
  rep(i, N) {
    ans += b[a[i]];
    if (i < N && a[i + 1] - a[i] == 1) {
      ans += c[a[i]];
    }
  }

  cout << ans << endl;
}