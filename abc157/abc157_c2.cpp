#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc157/abc157_c.txt"); \
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

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, M;
  cin >> N >> M;

  vector<int> S(N, -1);
  rep(i, M) {
    int s, c;
    cin >> s >> c;
    s--;
    if (S[s] == -1) {
      S[s] = c;
    } else if (S[s] != c) {
      // 同じ桁で違う数字
      cout << -1 << endl;
      return 0;
    }
  }

  // 先頭が0指定
  if (N > 1 && S[0] == 0) {
    cout << -1 << endl;
    return 0;
  }
  // 2桁以上で先頭が指定されない場合、先頭は１
  if (N > 1 && S[0] == -1) {
    S[0] = 1;
  }

  string ans = "";
  rep(i, N) {
    if (S[i] == -1) {
      ans += "0";
    } else {
      ans += to_string(S[i]);
    }
  }

  cout << ans << endl;
}