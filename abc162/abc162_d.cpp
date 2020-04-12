#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("abc162/abc162_d.txt"); \
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
  
  vector<vector<int>> c(3, vector<int>(0));
  rep(i, N) {
    char s;
    cin >> s;
    int t;
    if (s == 'R') {
      t = 0;
    } else if (s == 'G') {
      t = 1;
    } else if (s == 'B') {
      t = 2;
    }
    c[t].push_back(i);
  }

  ll ans = 0;
  for (int i : c[0]) {
    for (int j : c[1]) {
      for (int k : c[2]) {
        vector<int> c = {i, j, k};
        sort(c.begin(), c.end(), greater<int>());
        if (c[0] - c[1] != c[1] - c[2]) ans++;
      }
    }
  }

  cout << ans << endl;
}