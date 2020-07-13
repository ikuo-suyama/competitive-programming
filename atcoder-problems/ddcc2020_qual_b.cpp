#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                     \
  ifstream in("atcoder-problems/ddcc2020_qual_b.txt"); \
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
  ll total = 0;
  rep(i, N) {
    cin >> c[i];
    total += c[i];
  }
  sort(c.rbegin(), c.rend());

  ll ans = 0;
  if (total % 2 == 1) {
    ans++;
    c[0]--;
  }

  ll half = 0;
  rep(i, N) {
    if (half + c[i] <= total / 2) {
      half += c[i];
    }
  }
  if (half != total / 2) {
    ans += abs(half - total / 2);
  }

  cout << ans << endl;
}