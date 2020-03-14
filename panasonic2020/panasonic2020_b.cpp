#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                  \
  ifstream in("panasonic2020/panasonic2020_b.txt"); \
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

  ll h, w;
  cin >> h >> w;

  ll cnt = 0;
  if (h == 1 || w == 1) {
    cnt = 1;
  } else {
    cnt = ((w / 2 + w % 2) + (w / 2)) * (h / 2) + (w / 2 + w % 2) * (h % 2);
  }

  cout << cnt << endl;
}