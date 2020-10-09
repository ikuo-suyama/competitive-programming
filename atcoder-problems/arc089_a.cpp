#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/arc089_a.txt"); \
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

  int N;
  cin >> N;
  
  vector<int> t(N);
  vector<int> x(N);
  vector<int> y(N);
  rep(i, N) { cin >> t[i] >> x[i] >> y[i]; }

  bool ok = true;
  int bx = 0, by = 0, bt = 0;
  rep(i, N) {
    int diff = abs(x[i] - bx) + abs(y[i] - by);
    int diffT = t[i] - bt;
    if (diffT % 2 != diff % 2 || diff > diffT) {
      ok = false;
      break;
    }
    bx = x[i];
    by = y[i];
    bt = t[i];
  }

  cout << (ok ? "Yes" : "No") << endl;
}