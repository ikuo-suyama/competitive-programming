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

// [桁][未満フラグ][last][lunlun]
ll dp[20][2][10][2];

ll memo(string &S, int i, int smaller, int last, int l) {
  // printf("i:%d last:%d l:%d\n", i, last, l);
  if (i >= S.size()) return l;
  if (dp[i][smaller][last][l] != -1) return dp[i][smaller][last][l];

  ll ret = 0;
  int current = S[i] - '0';
  int limit = smaller ? 9 : current;
  for (int d = 0; d <= limit; d++) {
    int lun = 1;
    if (last != 0) lun = abs(d - last) <= 1;
    // printf("  d:%d lun:%d\n", d, lun);

    ret += memo(S, i + 1, smaller || d < current, d, l && lun);
  }
  return dp[i][smaller][last][l] = ret;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int K;
  cin >> K;
  memset(dp, -1, 20 * 2 * 10 * 2 * sizeof(ll));
  string s = "554543231";
  printf("%lld\n", memo(s, 0, 0, 0, 1));

  ll l = 0, r = LINF;
  while (l + 1 < r) {
    ll x = (l + r) / 2;
    string s = to_string(x);
    memset(dp, -1, 20 * 2 * 10 * 2 * sizeof(ll));
    ll cnt = memo(s, 0, 0, 0, 1);
    // 0 のぶんを引いておく
    cnt--;
    if (cnt <= K) {
      l = x;
    } else {
      r = x;
    }
  }

  cout << l << endl;
}