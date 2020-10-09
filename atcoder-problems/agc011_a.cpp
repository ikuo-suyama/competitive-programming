#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/agc011_a.txt"); \
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

  ll N, C, K;
  cin >> N >> C >> K;

  vector<ll> c(N);
  rep(i, N) { cin >> c[i]; }
  sort(c.begin(), c.end());

  int waiting = 0;
  ll ans = 0;
  rep(i, N) {
    if(i - waiting >= C || c[i] - c[waiting] > K) {
      ans++;
      waiting = i;
    }
  }
  ans++;
  cout << ans << endl;
}
