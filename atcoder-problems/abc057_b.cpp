#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc057_b.txt"); \
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

  int N, M;
  cin >> N >> M;

  vector<int> a(N);
  vector<int> b(N);
  vector<int> c(M);
  vector<int> d(M);
  rep(i, N) {
    cin >> a[i];
    cin >> b[i];
  }
  rep(i, M) {
    cin >> c[i];
    cin >> d[i];
  }

  rep(i, N) {
    int x = a[i];
    int y = b[i];
    int dis = INF * 10;
    int ans = 0;
    rep(j, M) {
      int m = c[j];
      int n = d[j];
      int _dis = abs(x - m) + abs(y - n);
      if (dis > _dis) {
        dis = _dis;
        ans = j + 1;
      }
    }
    cout << ans << endl;
  }
}