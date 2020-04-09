#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                  \
  ifstream in("atcoder-problems/sumitb2019_c.txt"); \
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

  int X;
  cin >> X;

  int l = X % 100;
  int g = X / 100;
  int cnt = 0;
  while (l > 0) {
    for (int i = 5; i > 0; i--) {
      if (l >= i) {
        l -= i;
        cnt++;
        break;
      }
    }
  }
  cout << (cnt <= g ? 1 : 0) << endl;
}