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
// [i日][服j]
int dp[201][201] = {-1};

ll solve(int i, int j, int c, vector<int> & T, vector<shirts>& S) {
  if (i >= N) return 0;

  if (dp[i][j] != -1) return dp[i][j];

  int t = T[i];
  shirts s = S[j];

  int ret = 0;
  if (s.min <= t && t <= s.max) {
    ret = solve(i + 1, j, T, S);
  } else {
    return -1;
  }

  return dp[i][j] = ret;
}

int main() {
  ifstream in("ac-ans-a/joi2013yo_d.txt");
  cin.rdbuf(in.rdbuf());

  cin >> D, N;
  vector<int> t(D);
  vector<shirts> s(N);

  rep(i, D) { cin >> t[i]; }
  rep(i, N) {
    int a, b, c;
    cin >> a >> b >> c;
    s[i] = {a, b, c};
  }

  ll cnt = 0;

  cout << cnt << endl;
}