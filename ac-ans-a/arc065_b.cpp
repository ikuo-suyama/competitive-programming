#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ifstream in("ac-ans-a/arc065_b.txt");
  cin.rdbuf(in.rdbuf());

  int N, K, L;
  cin >> N >> K >> L;

  vector<vector<int>> c(N, vector<int>(N, 0));

  rep(i, K + L) {
    int a, b;
    cin >> a >> b;
    c[a][b] += 1;
    c[a][b] += 1;
  }

  int ret0 = 0;
  rep(i, N) {
    if (c[0][i] >= 2) {
      ret0 += 1;
    }
  }
  cout << ret0;
  repi(i, 1, N) {
    int ret = 0;
    rep(j, N) {
      if (c[i][j] >= 2) {
        ret += 1;
      }
    }
    cout << ' ' << ret;
  }
}