#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc047_b.txt"); \
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

  int W, H, N;
  cin >> W >> H >> N;

  vector<int> x(N);
  vector<int> y(N);
  vector<int> a(N);
  rep(i, N) {
    cin >> x[i];
    cin >> y[i];
    cin >> a[i];
  }

  ll ans = 0;
  int minX = 0, maxX = W, minY = 0, maxY = H;
  rep(i, N) {
    switch (a[i]) {
      case 1:
        minX = max(minX, x[i]);
        break;
      case 2:
        maxX = min(maxX, x[i]);
        break;
      case 3:
        minY = max(minY, y[i]);
        break;
      case 4:
        maxY = min(maxY, y[i]);
        break;

      default:
        break;
    }
  }

  if ((maxX - minX) < 0 || (maxY - minY) < 0) {
    cout << 0 << endl;
  } else {
    ans = (maxX - minX) * (maxY - minY);
    cout << (ans > 0 ? ans : 0) << endl;
  }
}