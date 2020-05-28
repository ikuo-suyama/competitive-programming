#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/arc101_a.txt"); \
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

int N, K;
ll solve(vector<ll> &c) {
  vector<int> d(N - 1, 0);
  rep(i, N - 1) {
    if (c[i] < 0 && c[i + 1] < 0) {
      d[i] = (abs(c[i]) - abs(c[i + 1])) * 2;
    } else if (c[i] < 0) {
      d[i] = abs(c[i]) * 2 + c[i + 1];
    } else {
      d[i] = c[i + 1] - c[i];
    }
  }

  ll ans = LINF;
  ll sum = 0;

  rep(i, N - 1) {
    if (i < K) {
      sum += d[i];
      ans = sum;
    } else {
      sum -= d[i - K];
      sum += d[i];
      ans = min(ans, sum);
    }
  }
  return ans;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  cin >> N >> K;

  vector<ll> c(N, 0);
  bool zero = false;
  rep(i, N) {
    cin >> c[i];
    if (c[i] == 0) zero = true;
  }
  if (N == 1) {
    cout << abs(c[0]) << endl;
    return 0;
  }

  if (!zero) {
    c.push_back(0);
    N++;
  }
  sort(c.begin(), c.end());
  ll ans = solve(c);

  rep(i, N) { c[i] *= -1; }
  sort(c.begin(), c.end());
  ans = min(ans, solve(c));

  cout << ans << endl;
}