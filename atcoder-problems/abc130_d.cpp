#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc130_d.txt"); \
  cin.rdbuf(in.rdbuf());
#else
#define INPUT_FILE
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

  ll N, K;
  cin >> N >> K;

  vector<int> c(N);
  rep(i, N) { cin >> c[i]; }

  ll ans = 0;
  ll sum = c[0];
  int j = 0;
  rep(i, N - 1) {
    // if (i == j) sum += c[++j];
    while (sum < K && j < N) sum += c[++j];
    if (sum >= K) ans += N - j;
    sum -= c[i];
  }

  cout << ans << endl;
}