#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/abc051_c.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v) \
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
const ll LINF = 1e18+100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  rep(i, tx - sx) printf("R");
  rep(i, ty - sy) printf("U");
  rep(i, tx - sx) printf("L");
  rep(i, ty - sy) printf("D");
  printf("D");
  rep(i, tx - sx + 1) printf("R");
  rep(i, ty - sy + 1) printf("U");
  printf("L");
  printf("U");
  rep(i, tx - sx + 1) printf("L");
  rep(i, ty - sy + 1) printf("D");
  printf("R");
}