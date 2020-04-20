#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc163/abc163_d.txt"); \
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

  int N, K;
  cin >> N >> K;

  vector<ll> com(N + 1, 0);
  repi(i, 1, N + 1) { com[i] = com[i - 1] + i; }

  ll ans = 0;
  repi(k, K, N + 2) {
    ll l = com[k - 1];
    int ri = N - k >= 0 ? N - k : 0;
    ll r = com[N] - com[ri];

    ans += (r - l + 1) % MOD;
    printf("%d %d: %lld %lld %lld\n", N, k, l, r, ans);
    ans %= MOD;
  }

  cout << ans << endl;
}