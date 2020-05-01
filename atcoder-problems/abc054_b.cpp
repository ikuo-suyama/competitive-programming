#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc054_b.txt"); \
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

  int N, M;
  cin >> N >> M;

  vector<string> a(N);
  vector<string> b(M);
  rep(i, N) { cin >> a[i]; }
  rep(i, M) { cin >> b[i]; }

  rep(i, N - M + 1) {
    rep(j, N - M + 1) {
      bool ok = true;
      rep(l, M) {
        string ai = a[i + l].substr(j, M);
        string bi = b[l];
        ok &= ai == bi;
        if (!ok) break;
      }
      if (ok) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}