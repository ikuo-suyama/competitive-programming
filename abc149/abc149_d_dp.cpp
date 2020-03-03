#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc149/abc149_d.txt"); \
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

// i回目のじゃんけん、r/s/p
ll dp[10010][3];
int N, K;

ll memo(int i, int k) {
  if (i > N) return 0;
  if (dp[i][k] != -1) return dp[i][k];

  ll ret = 0;
  rep(l, 3) { ret = memo(i + 1, l); }
  return dp[i][k] = ret;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int R, S, P;
  cin >> N >> K >> R >> S >> P;
  map<char, int> win;
  win.emplace('r', 0);
  win.emplace('s', 1);
  win.emplace('p', 2);

  map<char, int> points;
  // 相手の手に対して勝利したときの点
  points.emplace('s', R);
  points.emplace('p', S);
  points.emplace('r', P);

  string t;
  cin >> t;

  ll ans = 0;
  rep(i, N) {
    char x, kx = '-';
    x = t[i];
    if (i + K < N) {
      kx = t[i + K];
    }
    if (x != kx) {
      ans += points.at(x);
    }
  }

  cout << ans << endl;
}