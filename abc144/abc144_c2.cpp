#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc144/abc144_c.txt"); \
  cin.rdbuf(in.rdbuf());
#else
#define INPUT_FILE
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  ll N;
  cin >> N;
  int sqn = sqrt(N) + 1;
  bool ok = false;
  ll a = 0, b = 0;
  ll ans = LINF;
  repi(i, 2, sqn) {
    b = N / i;
    if (i * b == N) {
      a = i;
      ans = min(ans, a + b - 2);
      ok = true;
    }
  }

  if (!ok) {
    // 素数
    ans = N - 1;
  }
  cout << ans << endl;
}