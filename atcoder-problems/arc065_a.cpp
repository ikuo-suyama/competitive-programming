#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/arc065_a.txt"); \
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

  string S;
  cin >> S;
  reverse(S.begin(), S.end());
  vector<string> ss = {"dream", "dreamer", "erase", "eraser"};
  rep(i, ss.size()) { reverse(ss[i].begin(), ss[i].end()); }

  int i = 0;
  while (i < S.size()) {
    bool ok = false;
    for (auto s : ss) {
      if (i + s.size() > S.size()) continue;
      string test = S.substr(i, s.size());
      if (s == test) {
        i += s.size();
        ok = true;
        break;
      }
    }
    if (!ok) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
}