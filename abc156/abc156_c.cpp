#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

int main() {
  ifstream in("abc156/abc156_c.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;

  vector<int> x(N);
  rep(i, N) { cin >> x[i]; }

  ll ans = INF;
  rep(i, 100) {
    ll buf = 0;
    rep(j, N) {
      buf += pow(x[j] - (i + 1), 2);
      // printf("x[j]:%d i:%d ret:%f buf:%lld\n", x[j], i, pow(x[j] - (i + 1), 2), buf);
    }
    ans = min(ans, buf);
  }

  cout << ans << endl;
}