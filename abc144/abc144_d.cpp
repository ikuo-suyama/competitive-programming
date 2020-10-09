#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc144/abc144_d.txt"); \
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

#ifndef M_PI
#define M_PI 3.14159265358979
#endif
#define deg_to_rad(deg) (((deg) / 180) * M_PI)
#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  double a, b, x;
  cin >> a >> b >> x;

  double th = 0;
  if (b * pow(a, 2) / 2 < x) {
    th = atan(2 * (b - x / pow(a, 2)) / a);
  } else {
    th = atan(pow(b, 2) * a / (2 * x));
  }

  printf("%.9lf", rad_to_deg(th));
}