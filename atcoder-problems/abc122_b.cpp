#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc122_b.txt"); \
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

  string S;
  cin >> S;
  int N = S.size();

  int ans = 0;
  int tmp = 0;
  rep(i, N) {
    if (S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T') {
      tmp++;
    } else {
      ans = max(ans, tmp);
      tmp = 0;
    }
  }
  if (tmp > 0) {
    ans = max(ans, tmp);
  }

  cout << ans << endl;
}