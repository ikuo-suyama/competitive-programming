#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                   \
  ifstream in("atcoder-problems/keyence2019_b.txt"); \
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

  string O = "keyence";
  bool ok = false;
  rep(i, O.size() + 1) {
    string l = O.substr(0, i);
    string r = O.substr(i, O.size() - i);

    string sl = S.substr(0, i);
    string sr = S.substr(S.size() - O.size() + i, O.size() - i);

    if ((sl == l) && (r == sr)) {
      ok = true;
      break;
    }
  }

  cout << (ok ? "YES" : "NO") << endl;
}