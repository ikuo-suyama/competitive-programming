#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/tenka1_2015_qualB_b.txt"); \
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

  string S;
  cin >> S;

  int cnt = 0;
  string ans = "dict";
  int dictCnt = 0;
  S = S.substr(1, S.size() - 2);
  rep(i, S.size()) {
    char c = S[i];
    if (c == '{') {
      cnt++;
    } else if (c == '}') {
      cnt--;
    } else if (cnt == 0 && c == ',') {
      ans = "set";
      break;
    } else if (cnt == 0 && c == ':') {
      dictCnt++;
      break;
    }
  }

  if (S.size() != 0 && dictCnt == 0) {
    ans = "set";
  }
  cout << ans << endl;
}