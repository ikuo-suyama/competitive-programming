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

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  ll a, b, c;
  cin >> a >> b >> c;

  ll g = gcd(a, b);
  g = gcd(g, c);

  cout << (sqrt(a/g) + sqrt(b/g) < sqrt(c/g) ? "Yes" : "No") << endl;
}