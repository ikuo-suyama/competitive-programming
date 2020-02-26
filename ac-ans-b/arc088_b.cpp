#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

int main() {
  ifstream in("ac-ans-b/arc088_b.txt");
  cin.rdbuf(in.rdbuf());

  string s;
  cin >> s;
  int N = s.size();

  char c = s[0];
  int ans = INF;
  repi(i, 1, N) {
    if (s[i] != c) {
      ans = min(ans, max(i, N - i));
      c = s[i];
    }
  }
  if (ans == INF) {
    ans = N;
  }

  cout << ans << endl;
}