#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc062_b.txt"); \
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

  int H, W;
  cin >> H >> W;

  vector<string> s(H);
  rep(i, H) { cin >> s[i]; }

  rep(i, H) { s[i] = '#' + s[i] + '#'; }

  string h;
  rep(i, W + 2) { h += '#'; }

  printf("%s\n", h.c_str());
  rep(i, H) { printf("%s\n", s[i].c_str()); }
  printf("%s\n", h.c_str());
}