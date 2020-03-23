#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc159/abc159_d.txt"); \
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

  int N;
  cin >> N;

  vector<int> c(N);
  vector<int> counts(N + 1, 0);
  ll max_ans = 0;
  rep(i, N) {
    int _c;
    cin >> _c;
    c[i] = _c;
    counts[_c]++;
  }

  rep(i, N + 1) {
    int cnt = counts[i];
    if (cnt) {
      max_ans += (ll)cnt * (cnt - 1) / 2;
    }
  }

  rep(i, N) {
    int _c = c[i];
    int cnt = counts[_c];
    if (cnt >= 2) {
      ll b = (ll)cnt * (cnt - 1) / 2;
      ll d = (ll)(cnt - 1) * (cnt - 2) / 2;
      cout << max_ans - (b - d) << endl;
    } else {
      cout << max_ans << endl;
    }
  }
}