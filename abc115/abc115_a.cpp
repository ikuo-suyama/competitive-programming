#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("abc115/abc115_a.txt"); \
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

  int D;
  cin >> D;

  string ans;
  if (D == 25) {
    ans = "Christmas";
  } else if (D == 24) {
    ans = "Christmas Eve";
  } else if (D == 23) {
    ans = "Christmas Eve Eve";
  } else if (D == 22) {
    ans = "Christmas Eve Eve Eve";
  }

  cout << ans << endl;
}