#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

int main() {
  ifstream in("ac-ans-b/arc022_2.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;

  vector<int> c(N);
  rep(i, N) { cin >> c[i]; }

  int l = 0, r = 0;
  int ans = 1;
  vector<bool> use(1e5 + 9, false);

  rep(l, N) {
    while (r < N && !use[c[r]]) {
      use[c[r]] = true;
      r++;
    }
    ans = max(ans, r - l);
    use[c[l]] = false;
  }

  cout << ans << endl;
}