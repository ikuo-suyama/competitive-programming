#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc137_c.txt"); \
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

  vector<string> s(N);
  rep(i, N) {
    string _s;
    cin >> _s;
    sort(_s.begin(), _s.end());
    s[i] = _s;
  }
  sort(s.begin(), s.end());

  ll tmp = 0;
  ll ans = 0;
  repi(i, 1, N) {
    if (s[i - 1] == s[i])
      tmp++;
    else {
      if (tmp != 0) {
        tmp++;
        ans += tmp * (tmp - 1) / 2;
        tmp = 0;
      }
    }
  }
  if (tmp != 0) {
    tmp++;
    ans += tmp * (tmp - 1) / 2;
  }

  cout << ans << endl;
}