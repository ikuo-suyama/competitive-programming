#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

int main() {
  ifstream in("ac-ans-b/arc064_a.txt");
  cin.rdbuf(in.rdbuf());

  ll N, x;
  cin >> N >> x;

  vector<ll> c(N);
  rep(i, N) { cin >> c[i]; }

  ll cnt = 0;
  if (c[0] > x) {
    cnt = c[0] - x;
    c[0] = x;
  }
  repi(i, 1, N) {
    if (c[i-1] + c[i] > x) {
      ll tmp = c[i];
      c[i] = x - c[i - 1];
      cnt += tmp - c[i];
    }
  }

  cout << cnt << endl;
}