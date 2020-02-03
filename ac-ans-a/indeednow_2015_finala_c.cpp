#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ifstream in("ac-ans-a/indeednow_2015_finala_c.txt");
  cin.rdbuf(in.rdbuf());

  int N, M;
  cin >> N >> M;

  vector<vector<vector<ll>>> dp(110,
                                vector<vector<ll>>(110, vector<ll>(110, 0)));

  rep(i, N) {
    int a, b, c;
    ll w;
    cin >> a >> b >> c >> w;

    rep2(j, a, 100 + 1) rep2(k, b, 100 + 1) rep2(l, c, 100 + 1) {
      if (dp[j][k][l] < w) dp[j][k][l] = w;
    }
  }

  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c;

    cout << dp[a][b][c] << endl;
  }
}