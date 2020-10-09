#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc116_c.txt"); \
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

  set<int> c;
  vector<int> h(N);
  rep(i, N) {
    int _h;
    cin >> _h;
    h[i] = _h;
    c.insert(_h);
  }

  bool ok = false;
  int min = 0;
  int _max = -1;
  ll ans = 0;
  auto jt = c.begin();
  bool fin = false;

  while (!fin) {
    fin = true;
    int tmp = *jt - min;
    min = *jt;
    jt++;

    bool del = false;
    rep(i, N) {
      if (h[i] != 0) {
        if (!del) {
          ans += tmp;
          del = true;
        }
        h[i] -= tmp;
      } else {
        del = false;
      }
      fin &= h[i] == 0;
    }
  }

  cout << ans << endl;
}