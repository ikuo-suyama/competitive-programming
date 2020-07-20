#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/arc098_a.txt"); \
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

  int N;
  cin >> N;
  string S;
  cin >> S;

  int E = 0, W = 0;
  vector<int> e(N, 0);
  vector<int> w(N, 0);
  E = e[0] = S[0] == 'E';
  W = w[0] = S[0] == 'W';
  repi(i, 1, N) {
    if (S[i] == 'E') {
      E++;
      e[i] = e[i - 1] + 1;
      w[i] = w[i - 1];
    } else {
      W++;
      e[i] = e[i - 1];
      w[i] = w[i - 1] + 1;
    }
  }

  ll ans = LINF;
  rep(i, N) {
    ll re = E - e[i];
    ll lw = w[i];
    if (S[i] == 'W') lw--;
    ans = min(ans, lw + re);
  }

  cout << ans << endl;
}