#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc148/abc148_e.txt"); \
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
const int MOD = 1e9 + 7;

// [桁数][smallフラグ][整数OK][0の個数][digit]
ll dp[30][2][2][30][9];

string N;

ll memo(int i, int smaller, int ok, int k, int x) {
  // printf("i:%d ok:%d, x:%d k:%d\n", i, ok, x, k);
  if (i >= N.size()) {
    return x == 0 ? k : 0;
  }

  if (dp[i][smaller][ok][k][x] != -1) {
    return dp[i][smaller][ok][k][x];
  }

  ll ret = 0;
  int current = N[i] - '0';
  int limit = smaller ? 9 : current;
  for (int d = 0; d <= limit; d++) {
    ret += memo(i + 1, smaller || d < current, ok || d > 0,
                k + (ok && (d == 0)), d);
  }

  return dp[i][smaller][ok][k][x] = ret;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  memset(dp, -1, 30 * 2 * 2 * 30 * 9 * sizeof(ll));
  cin >> N;

  if ((N[N.size() - 1] - '0') % 2 == 1) {
    cout << 0 << endl;
    return 0;
  }
  ll cnt = memo(0, 0, 0, 0, 0);
  cout << cnt << endl;
}