#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc158/abc158_c.txt"); \
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

  int a, b;
  cin >> a >> b;

  int ax = a * 12.5;
  int bx = b * 10;
  bool ok = true;
  int ans = ax;
  if (ax != bx) {
    ok = false;
    if (ax < bx) {
      while (int(++ax * 0.08) == a) {
        if (ax * 0.1 == b) {
          ans = ax;
          ok = true;
          break;
        }
      }
    } else {
      while (int(++bx * 0.1) == b) {
        if (bx * 0.08 == a) {
          ans = bx;
          ok = true;
          break;
        }
      }
    }
  }
  cout << (ok ? ans : -1) << endl;
}