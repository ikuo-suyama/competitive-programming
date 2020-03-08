#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc158/abc158_e.txt"); \
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

string S;
int N;
int p;

// 開始, 終了
ll dp[200010][200010];
ll memo(int s, int e) {
  // メモしてある値ならそれを返す
  if (dp[s][e] != -1) {
    return dp[s][e];
  }

  ll ret = 0;
  repi(i, s, e) {
    ret += memo(s, i - 1) + memo(i, e);
  }
  ll org = stoll(S.substr(s, e));
  if (org % p == 0) ret++;

  return dp[s][e] = ret;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  memset(dp, -1, (ll)200010 * 200010 * sizeof(ll));
  cin >> N >> p >> S;

  cout << memo(0, N) << endl;
}