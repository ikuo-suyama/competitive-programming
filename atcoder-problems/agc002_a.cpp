#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/agc002_a.txt"); \
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

  int a, b;
  cin >> a >> b;

  string ans;
  if (a > 0 && b > 0) {
    ans = "Positive";
  } else if (a <= 0 && b >= 0) {
    ans = "Zero";
  } else {
    if ((a - b) % 2 == 0) {
      ans = "Negative";
    } else {
      ans = "Positive";
    }
  }

  cout << ans << endl;
}