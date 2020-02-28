#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

string s;
// 区間[i, j) の消せる文字数の最大値
int dp[301][301];

int solve(const int& l, const int& r) {
  if (r - l < 1) return 0;
  if (dp[l][r] != -1) return dp[l][r];

  int cnt = 0;
  repi(i, l + 1, r) {
    // printf("%d %d %d: %c%c%c\n", l, i, r, s[l], s[i], s[r - 1]);
    cnt = max(cnt, solve(l, i) + solve(i, r));
    if (s[l] == 'i' && s[i] == 'w' && s[r - 1] == 'i') {
      if (solve(l + 1, i) == i - l - 1 && solve(i + 1, r - 1) == r - i - 2) {
        // もし間が全部消せるなら、この区間は全部消せる
        cnt = r - l;
        break;
      }
    }
  }

  // printf("%d %d: cnt %d\n", l, r, cnt);
  return dp[l][r] = cnt;
}

int main() {
  ifstream in("tipicalDP/tdpc_iwi.txt");
  cin.rdbuf(in.rdbuf());

  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(dp, -1, 301 * 301 * sizeof(int));

  cin >> s;

  cout << solve(0, s.size()) / 3 << endl;
}