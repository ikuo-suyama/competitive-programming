#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc136_d.txt"); \
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

  string S;
  cin >> S;
  int N = S.size();
  vector<int> c(N, 0);

  int bnd = 0;
  int start = 0;
  int even = 0;
  int odd = 0;
  rep(i, N - 1) {
    i % 2 == 0 ? even++ : odd++;
    if (S[i] == 'R' && S[i + 1] == 'L') {
      // 境界
      bnd = i;
    } else if (S[i] == 'L' && S[i + 1] == 'R') {
      c[bnd] = bnd % 2 == 0 ? even : odd;      // Rに R..RL..L Rから偶数
      c[bnd + 1] = bnd % 2 == 0 ? odd : even;  // Lに Lから偶数
      start = i;
      even = 0;
      odd = 0;
    }
  }

  (N - 1) % 2 == 0 ? even++ : odd++;
  c[bnd] = bnd % 2 == 0 ? even : odd;
  c[bnd + 1] = bnd % 2 == 0 ? odd : even;

  rep(i, S.size()) { cout << c[i] << ' '; }
}