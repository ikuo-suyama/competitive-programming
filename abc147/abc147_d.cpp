#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("abc147/abc147_d.txt"); \
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

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  cin >> N;
  
  vector<ll> c(N);
  rep(i, N) { cin >> c[i]; }

  ll ans = 0;
  rep(i, 61) {
    ll n0 = 0;
    ll n1 = 0;
    rep(j, N) {
      if (c[j] & (1ll << i)) {
        n1++;
      } else {
        n0++;
      }
    }
    ll base = pow(2, i);
    base %= MOD;
    base = (base * n0) % MOD;
    base = (base * n1) % MOD;
    ans = (ans + base) % MOD;
  }
  cout << ans << endl;
}