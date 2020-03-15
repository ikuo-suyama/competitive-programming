#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("panasonic2020/panasonic2020_c.txt"); \
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
const ll LINF = 1e18+100;
const int MOD = 1e9 + 7;
using R = long double;

constexpr R EPS = 1E-14;

// r の(誤差付きの)符号に従って, -1, 0, 1 を返す.
int sgn(const R& r){ return (r > EPS) - (r < -EPS); }
// a, b の(誤差付きの)大小比較の結果に従って, -1, 0, 1 を返す.
int sgn(const R& a, const R &b){ return sgn(a - b); }

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  ll a, b, c;
  cin >> a >> b >> c;
  ll d = c - (a + b);
  string ans;
  if (d > 0 && d * d > 4 * a * b) {
    ans = "Yes";
  } else {
    ans = "No";
  }
  cout << ans << endl;
}