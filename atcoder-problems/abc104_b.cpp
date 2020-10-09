#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc104_b.txt"); \
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

  int aidx = 0;
  int acnt = 0;
  int cidx = 0;
  int ccnt = 0;
  rep(i, S.size()) {
    if (S[i] == 'A') {
      aidx = i;
      acnt++;
    } else if (S[i] == 'C') {
      cidx = i;
      ccnt++;
    } else if (S[i] <= 'Z') {
      cout << "WA" << endl;
      return 0;
    }
  }

  bool ok = (aidx == 0) && (acnt == 1) && (cidx >= 2 && cidx <= S.size() - 2) &&
            (ccnt == 1);

  cout << (ok ? "AC" : "WA") << endl;
}