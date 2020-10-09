#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/agc003_a.txt"); \
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

  int s = 0, e = 0, w = 0, n = 0;
  rep(i, S.size()) {
    if (S[i] == 'S') s++;
    if (S[i] == 'E') e++;
    if (S[i] == 'W') w++;
    if (S[i] == 'N') n++;
  }

  if ((s == 0 && n != 0) || (s != 0 && n == 0) || (w == 0 && e != 0) ||
      (w != 0 && e == 0)) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}