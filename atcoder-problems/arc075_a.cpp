#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/arc075_a.txt"); \
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

  int N;
  cin >> N;

  vector<int> c(N);
  int ans = 0;
  rep(i, N) {
    cin >> c[i];
    ans += c[i];
  }
  int max = ans;

  sort(c.begin(), c.end());

  bool dec = false;
  rep(i, N) {
    if (ans % 10 != 0) break;
    if (c[i] % 10 == 0) {
      dec = true;
      continue;
    } else {
      ans -= c[i];
    }
  }
  if (dec && ans == max) ans = 0;
  cout << ans << endl;
}