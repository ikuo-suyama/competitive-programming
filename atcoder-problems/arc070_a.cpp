#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/arc070_a.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v) \
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
const ll LINF = 1e18+100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  ll X;
  cin >> X;
  ll l = 0;
  ll r = INF;
  ll ans = 0;

  while (l + 1 < r) {
    ll n = (l + r) / 2;
    ll sum = (1 + n) * n / 2;
    if (sum < X) {
      l = n;
    } else {
      r = n;
    }
    // printf("%d %d %d\n", l, r, sum);
    ans = X == (1 + l) * l / 2 ? l : l + 1;
  }

  cout << ans << endl;
}