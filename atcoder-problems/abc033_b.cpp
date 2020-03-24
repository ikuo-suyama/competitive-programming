#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc033_b.txt"); \
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

  int N;
  cin >> N;

  vector<int> c(N);
  vector<string> s(N);

  ll total = 0;
  int max = 0;
  int maxi = 0;
  rep(i, N) {
    cin >> s[i];
    cin >> c[i];
    total += c[i];
    if (c[i] > max) {
      max = c[i];
      maxi = i;
    }
  }

  string ans = "atcoder";
  if (total / 2 < max) {
    ans = s[maxi];
  }

  cout << ans << endl;
}