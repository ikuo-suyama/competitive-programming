#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("hitachi2020/hitachi2020_b.txt"); \
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

  int A, B, M;
  cin >> A >> B >> M;

  vector<ll> a(A);
  vector<ll> b(B);

  rep(i, A) { cin >> a[i]; }
  rep(i, B) { cin >> b[i]; }

  ll ans = LINF;
  rep(i, M) {
    ll x, y, c;
    cin >> x >> y >> c;
    x--;
    y--;
    ans = min(ans, a[x] + b[y] - c);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ans = min(ans, a[0] + b[0]);

  cout << ans << endl;
}