#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("hitachi2020/hitachi2020_a.txt"); \
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

  string h;
  cin >> h;

  if (h.size() % 2 != 0) {
    cout << "No" << endl;
    return 0;
  }

  for (int i = 0; i < h.size() - 1; i += 2) {
    if (h[i] != 'h' || h[i + 1] != 'i') {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}