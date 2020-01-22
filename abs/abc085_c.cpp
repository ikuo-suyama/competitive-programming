#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main() {
  ifstream in("abs/abc085_c.txt");
  cin.rdbuf(in.rdbuf());

  int N, Y;
  cin >> N >> Y;

  rep(i, max(Y / 10000 + 1, 1)) {
    int yi = Y - (10000 * i);
    rep(j, max(yi / 5000 + 1, 1)) {
      int yj = yi - (5000 * j);
      int k = yj / 1000;
      if (i + j + k == N) {
        cout << i << " " << j << " " << k << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
}