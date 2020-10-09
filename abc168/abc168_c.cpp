#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc168/abc168_c.txt"); \
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

using R = long double;
constexpr R EPS = 1E-3;

// r の(誤差付きの)符号に従って, -1, 0, 1 を返す.
int sgn(const R& r) { return (r > EPS) - (r < -EPS); }
// a, b の(誤差付きの)大小比較の結果に従って, -1, 0, 1 を返す.
int sgn(const R& a, const R& b) { return sgn(a - b); }

int main() {
  INPUT_FILE CIN_OPTIMIZE;
  const double PI = 3.14159265358979323846;
  const double PI_ROUGH = 3.14;

  int A, B, H, M;
  cin >> A >> B >> H >> M;

  double br = (2 * PI / (60 * 12)) * (60 * H + M);
  double ar = (2 * PI / 60) * M;
  double theta = br - ar > 0 ? br - ar : ar - br;
  // if (theta > PI) {
  //   theta -= PI;
  // }
  if (sgn(theta, PI) == 0) {
    printf("%d", A + B);
    return 0;
  } else if (sgn(theta, 0) == 0) {
    printf("%d", abs(A - B));
    return 0;
  }
  // 余弦定理
  double c = sqrt(pow(A, 2) + pow(B, 2) - 2 * A * B * cos(theta));

  printf("%0.12lf", c);
}