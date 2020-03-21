#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc146/abc146_c.txt"); \
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

  ll A, B, X;
  cin >> A >> B >> X;

  ll l = 0, r = 1e9;
  while (l + 1 < r) {
    ll x = (l + r) / 2;
    if (A * x + B * to_string(x).size() > X) {
      r = x;
    } else {
      l = x;
    }
  }

  if (A * (l + 1) + B * to_string(l + 1).size() <= X) l++;
  cout << l << endl;
}