#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/agc017_a.txt"); \
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

ll comb(int n, int k) {
  if (k == 0) return 1;
  if (n / 2 < k) return comb(n, n - k);
  ll ans = 1;
  vector<int> p(0);
  vector<int> q(0);
  rep(i, k) { p.push_back(n - i); }
  repi(i, 1, k + 1) { q.push_back(i); }
  rep(i, k) {
    ans *= p[i];
    ans /= q[i];
  }

  return ans;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;
  int N, P;
  cin >> N >> P;

  int even = 0;
  int odd = 0;
  rep(i, N) {
    int a;
    cin >> a;
    if (a % 2 == 0) {
      even++;
    } else {
      odd++;
    }
  }

  ll ans = 0;
  ll c_even = 0, c_odd = 0;
  if (P == 0) {
    rep(i, even + 1) { c_even += comb(even, i); }
    for (int i = 0; i <= odd; i += 2) {
      c_odd += comb(odd, i);
    }
    ans = c_even * c_odd;
  } else {
    rep(i, even + 1) {
      // printf("%d, %d, comb:%lld\n", even, i, comb(even, i));
      c_even += comb(even, i);
    }
    for (int i = 1; i <= odd; i += 2) {
      c_odd += comb(odd, i);
    }
    ans = c_even * c_odd;
  }
  cout << ans << endl;
}