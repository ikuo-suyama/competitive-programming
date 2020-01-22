#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main() {
  ifstream in("abs/abc086_c.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;

  int c[N][3];
  rep(i, N) rep(j, 3) {
    { cin >> c[i][j]; }
  }

  int T, X, Y;
  int t = 0;
  int x = 0;
  int y = 0;

  rep(i, N) {
    T = c[i][0] - t;
    X = abs(c[i][1] - x);
    Y = abs(c[i][2] - y);

    if (T < (X + Y) || (T % 2) != (X + Y) % 2) {
      cout << "No";
      return 0;
    }

    t = c[i][0];
    x = c[i][1];
    y = c[i][2];
  }
  cout << "Yes";
}