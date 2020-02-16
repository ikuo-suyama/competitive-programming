#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

struct shirts {
  int min;
  int max;
  int c;
};

int D, N;
vector<int> T;
vector<shirts> S;

// [i日][服j]
int dp[201][201];

ll solve(int i, int j) {
  if (i == 0) return 0;

  if (dp[i][j] != -1) return dp[i][j];

  int t = T[i];
  shirts s = S[j];

  vector<int> c(0);
  if (s.min <= t && t <= s.max) {
    rep(k, N) {
      shirts s_1 = S[k];
      c.push_back(solve(i - 1, k) + abs(s_1.c - s.c));
    }
    sort(c.begin(), c.end());
  } else {
    return 0;
  }

  return dp[i][j] = c[0];
}

int main() {
  ifstream in("ac-ans-a/joi2013yo_d.txt");
  cin.rdbuf(in.rdbuf());

  memset(dp, -1, 201 * 201 * sizeof(int));

  cin >> D >> N;
  T = vector<int>(D);
  S = vector<shirts>(N);

  rep(i, D) { cin >> T[i]; }
  rep(i, N) {
    int a, b, c;
    cin >> a >> b >> c;
    S[i] = {a, b, c};
  }

  ll cnt = 0;
  solve(D, 0);

  cout << cnt << endl;
}