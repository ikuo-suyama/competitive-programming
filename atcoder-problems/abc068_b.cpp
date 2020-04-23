#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc068_b.txt"); \
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

  int ans = 0;
  int cnt = 0;
  rep(i, N + 1) {
    int t = i;
    int c = 0;
    while (t > 0) {
      if (t % 2 == 0) {
        t /= 2;
        c++;
      } else {
        break;
      }
    }
    if (c > cnt) {
      ans = i;
      cnt = c;
    }
  }
  if (ans == 0) ans++;
  cout << ans << endl;
}