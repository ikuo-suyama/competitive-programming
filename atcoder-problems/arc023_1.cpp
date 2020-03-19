#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/arc023_1.txt"); \
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

int days(int y, int m, int d) {
  return 365 * y + (y / 4) - (y / 100) + (y / 400) + ((306 * (m + 1)) / 10) +
         d - 429;
}
int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int y, m, d;
  cin >> y >> m >> d;

  if (m <= 2) {
    y--;
    m += 12;
  }

  int input = days(y, m, d);
  int now = days(2014, 5, 17);

  cout << now - input << endl;
}