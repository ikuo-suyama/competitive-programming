#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc130_c.txt"); \
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

using ld = long double;
constexpr ld EPS = 1E-9;
// r の(誤差付きの)符号に従って, -1, 0, 1 を返す.
int sgn(const ld& r) { return (r > EPS) - (r < -EPS); }
// a, b の(誤差付きの)大小比較の結果に従って, -1, 0, 1 を返す.
int sgn(const ld& a, const ld& b) { return sgn(a - b); }

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  ll W, H;
  cin >> W >> H;

  long double x, y;
  cin >> x >> y;

  // x
  long double minx = sgn(x * H, (W - x) * H) < 0 ? x * H : (W - x) * H;
  // y
  long double miny = sgn(y * W, (H - y) * W) < 0 ? y * W : (H - y) * W;

  long double ans = sgn(minx, miny) > 0 ? minx : miny;
  int check = sgn(minx, miny) == 0 ? 1 : 0;
  printf("%Lf %d", ans, check);
}