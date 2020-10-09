#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc109_b.txt"); \
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
  set<string> ss;
  rep(i, N) {
    cin >> s[i];
    ss.insert(s[i]);
  }
  if (s.size() != ss.size()) {
    cout << "No" << endl;
    return 0;
  }

  bool ok = true;
  rep(i, N - 1) {
    if (s[i][s[i].size() - 1] != s[i + 1][0]) {
      ok = false;
      break;
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
}