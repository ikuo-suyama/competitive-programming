#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc184/abc184_c.txt"); \
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

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N = 4;
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a == c && b == d) {
    cout << 0 << endl;
    return 0;
  }
  if (a + b == c + d || a - b == c - d || abs(a - c) + abs(b - d) <= 3) {
    cout << 1 << endl;
    return 0;
  }

  if ((a + b + c + d) % 2 == 0 || abs(a - c) + abs(b - d) <= 6 ||
      abs(a + b - (c + d)) <= 3 || abs(a - b - (c - d)) <= 3) {
    cout << 2 << endl;
    return 0;
  }
  cout << 3 << endl;
}