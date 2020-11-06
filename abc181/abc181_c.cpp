#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc181/abc181_c.txt"); \
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

  vector<P> xy(N);
  rep(i, N) {
    int _x, _y;
    cin >> _x >> _y;
    xy[i] = make_pair(_x, _y);
  }

  sort(xy.begin(), xy.end());

  bool ok = false;
  rep(i, N - 2) {
    repi(j, i + 1, N - 1) {
      repi(k, j + 1, N) {
        int x1 = xy[j].first - xy[i].first;
        int x2 = xy[k].first - xy[j].first;

        int y1 = xy[j].second - xy[i].second;
        int y2 = xy[k].second - xy[j].second;

        if ((x1 == 0 && x2 == 0) || (y1 == 0 && y2 == 0)) {
          ok = true;
          break;
        } else if (x1 == 0 || x2 == 0 || y1 == 0 || y2 == 0) {
          continue;
        } else if (x2 * y1 == x1 * y2) {
          ok = true;
          break;
        }
      }
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
}