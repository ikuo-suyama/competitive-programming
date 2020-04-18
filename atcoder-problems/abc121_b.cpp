#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/abc121_b.txt"); \
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
const ll LINF = 1e18+100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, M, C;
  cin >> N >> M >> C;

  vector<int> b(M);
  rep(i, M) { cin >> b[i]; }
  
  vector<vector<int>> c(N, vector<int>(M, 0));
  rep(i, N) {
    rep(j, M) { cin >> c[i][j]; }
  }

  ll cnt = 0;
  rep(i, N) {
    int tmp = C;
    rep(j, M) {
      tmp += b[j] * c[i][j];
    }
    if (tmp > 0) cnt++;
  }

  cout << cnt << endl;
}