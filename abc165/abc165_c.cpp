#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc165/abc165_c.txt"); \
  cin.rdbuf(in.rdbuf());
#else
#define INPUT_FILE
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

  int N, M, Q;
  cin >> N >> M >> Q;

  vector<int> a(Q);
  vector<int> b(Q);
  vector<int> c(Q);
  vector<int> d(Q);
  rep(i, Q) {
    int _a, _b;
    cin >> _a >> _b >> c[i] >> d[i];
    _a--;
    _b--;
    a[i] = _a;
    b[i] = _b;
  }

  ll ans = 0;
  rep(i, pow(M, N) + 1) {
    vector<int> x(N, 1);
    int tmp = i;
    bool ok = true;
    for (int j = N - 1; j >= 0; j--) {
      int p = tmp / pow(M, j);
      x[j] = p+1;
      tmp -= p * pow(M, j);
      if (j < N - 1 && x[j] < x[j + 1]) {
        ok = false;
        break;
      }
    }
    // if (!ok) continue;
    // reverse(x.begin(), x.end());

    printf("i:%d ", i);
    rep(l, N) { cout << x[l] << " "; }
    cout << endl;

    // 判定
    ll tmpans = 0;
    rep(i, Q) {
      if (x[b[i]] - x[a[i]] == c[i]) tmpans += d[i];
    }
    ans = max(tmpans, ans);
  }

  cout << ans << endl;
}