#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ifstream in("abc154/abc154_d.txt");
  cin.rdbuf(in.rdbuf());

  int N, K;
  cin >> N >> K;

  vector<ll> e(N);
  rep(i, N) {
    ll p;
    cin >> p;
    e[i] = (1 + p);
  }

  ll buf = 0;
  rep(i, K) { buf += e[i]; }

  ll ans = buf;
  repi(i, K, N) {
    buf -= e[i - K];
    buf += e[i];
    ans = max(ans, buf);
  }

  string f = ans % 2 == 0 ? ".0" : ".5";
  cout << (ans / 2) << f << endl;
}