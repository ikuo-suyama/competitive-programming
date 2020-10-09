#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/agc013_a.txt"); \
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
  rep(i, N) { cin >> c[i]; }

  ll ans = 1;
  int mode = 0;
  if (c[1] > c[0]) {
    mode = 1;
  } else if (c[1] < c[0]) {
    mode = -1;
  }

  repi(i, 1, N) {
    int bef = mode;
    if (c[i] == c[i - 1]) continue;
    if (c[i] > c[i - 1]) {
      mode = 1;
    } else if (c[i] < c[i - 1]) {
      mode = -1;
    }

    if (bef != 0 && bef != mode) {
      ans++;
      mode = 0;
      if (c[i + 1] > c[i]) {
        mode = 1;
      } else if (c[i + 1] < c[i]) {
        mode = -1;
      }
    }
  }

  cout << ans << endl;
}