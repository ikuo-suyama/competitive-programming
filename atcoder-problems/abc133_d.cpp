#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc133_d.txt"); \
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

  vector<ll> c(N);
  ll tot = 0;
  rep(i, N) {
    cin >> c[i];
    tot += c[i];
  }

  vector<ll> x(N);
  ll tmp = 0;
  for (int i = 1; i < N; i+= 2) {
    tmp += c[i];
  }
  x[0] = tot - 2 * tmp;

  rep(i, N - 1) { x[i + 1] = (c[i] - x[i] / 2) * 2; }
  rep(i, N) { cout << x[i] << ' '; }
}