#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ifstream in("ac-ans-a/tdpc_dice.txt");
  cin.rdbuf(in.rdbuf());

  ll N, D;
  cin >> N >> D;

  ll max = pow(6, N);
  vector<vector<ll>> d(N + 10);
  d[0] = vector<ll>(1, 1);

  rep(i, N) {
    d[i + 1] = vector<ll>(pow(6, i + 1));
    for (int j = 0; j < d[i].size(); j++) {
      for (int l = 0; l < 6; l++) {
        ll a = d[i][j] * (l + 1);
        // printf("i: %d, j: %d, l: %d, lla: %d\n", i, j, l, a);

        d[i + 1][6 * j + l] = a;
      }
    }
  }

  ll cnt = 0;
  for (auto a : d[N]) {
    if (a != 0 && a % D == 0) cnt++;
  }
  cout << cnt / (double)max << endl;
}