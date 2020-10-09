#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc161/abc161_d.txt"); \
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

// [桁][未満フラグ][nonzeroフラグ][last][lunlun]
ll dp[20][2][2][10][2];

ll memo(string &S, int i, int smaller, int nonzero, int last, int l) {
  if (i >= S.size()) return l;
  if (dp[i][smaller][nonzero][last][l] != -1)
    return dp[i][smaller][nonzero][last][l];

  ll ret = 0;
  int current = S[i] - '0';
  int limit = smaller ? 9 : current;
  for (int d = 0; d <= limit; d++) {
    int lun = 1;
    if (nonzero) lun = abs(d - last) <= 1;

    ret +=
        memo(S, i + 1, smaller || d < current, nonzero || d > 0, d, l && lun);
  }
  return dp[i][smaller][nonzero][last][l] = ret;
}

/**
 * 桁DP
 * #dp #digitdp
 */
int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int K;
  cin >> K;

  ll l = 0, r = LINF;
  while (l + 1 < r) {
    ll x = (l + r) / 2;
    string s = to_string(x);
    memset(dp, -1, 20 * 2 * 10 * 2 * 2 * sizeof(ll));
    ll cnt = memo(s, 0, 0, 0, 0, 1);

    if (cnt <= K) {
      l = x;
    } else {
      r = x;
    }
  }

  cout << r << endl;
}