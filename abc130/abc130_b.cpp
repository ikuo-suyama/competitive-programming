#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                     \
  ifstream in("abc130/abc130_b.txt"); \
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

  int N, X;
  cin >> N >> X;

  vector<int> c(N);
  rep(i, N) { cin >> c[i]; }

  ll ans = 0;
  vector<int> sum(N + 1, -1);
  sum[0] = 0;
  repi(i, 1, N + 1) {
    ans++;
    sum[i] = sum[i - 1] + c[i - 1];
    if (sum[i] > X) {
      break;
    }
  }
   if (sum[N] != -1 && sum[N] <= X) ans++;

   cout << ans << endl;
}