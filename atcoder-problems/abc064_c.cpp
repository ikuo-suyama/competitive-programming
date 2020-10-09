#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc064_c.txt"); \
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

  int N;
  cin >> N;

  vector<int> c(N);
  rep(i, N) { cin >> c[i]; }

  vector<int> clr(10, 0);
  rep(i, N) {
    if (c[i] < 400) {
      clr[0]++;
    } else if (c[i] < 800) {
      clr[1]++;
    } else if (c[i] < 1200) {
      clr[2]++;
    } else if (c[i] < 1600) {
      clr[3]++;
    } else if (c[i] < 2000) {
      clr[4]++;
    } else if (c[i] < 2400) {
      clr[5]++;
    } else if (c[i] < 2800) {
      clr[6]++;
    } else if (c[i] < 3200) {
      clr[7]++;
    } else {
      clr[8]++;
    }
  }

  int min = 0;
  int max = 0;
  rep(i, 8) { min += clr[i] != 0; }
  max = min + clr[8];
  if (min == 0) {
    min++;
  }

  cout << min << ' ' << max << endl;
}