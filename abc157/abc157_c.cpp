#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc157/abc157_c.txt"); \
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
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, M;
  cin >> N >> M;

  vector<int> s(N + 1);
  vector<int> c(N + 1);
  map<int, int> check;

  rep(i, M) {
    cin >> s[i] >> c[i];
    decltype(check)::iterator it = check.find(s[i]);
    if (it != check.end()) {
      if (it->second > c[i]) {
        check.erase(s[i]);
        check.emplace(s[i], c[i]);
      }
    } else {
      check.emplace(s[i], c[i]);
    }
  }

  if (N > 1) {
    decltype(check)::iterator it = check.find(1);
    if (it == check.end() || it->second == 0) {
      cout << -1 << endl;
      return 0;
    }
  }

  for (int i = 3; i > N; i--) {
    decltype(check)::iterator it = check.find(i);
    if (it != check.end()) {
      cout << -1 << endl;
      return 0;
    }
  }
  string ans = "";
  repi(i, 1, N + 1) {
    decltype(check)::iterator it = check.find(i);
    if (it != check.end()) {
      ans += to_string(it->second);
    } else {
      ans += "0";
    }
  }
  cout << ans << endl;
}