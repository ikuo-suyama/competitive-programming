#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/agc036_a.txt"); \
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

  ll S;
  cin >> S;

  ll x, y;
  for (ll i = sqrt(sqrt(S)); i >= 1; i--) {
    ll tmp = S - pow(i, 2);
    if (pow(sqrt(tmp), 2) == tmp) {
      x = i;
      y = sqrt(tmp);
      break;
    }
  }

  ll x2 = -y, y2 = x;
  printf("0 0 %lld %lld %lld %lld", x, y, x2, y2);
  return 0;
}