#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/agc014_a.txt"); \
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

  ll a, b, c;
  cin >> a >> b >> c;

  ll cnt = 0;
  while ((a % 2 == 0 && b % 2 == 0 && c % 2 == 0) && cnt < 100) {
    ll _a = (b + c) / 2;
    ll _b = (a + c) / 2;
    ll _c = (b + c) / 2;
    a = _a;
    b = _b;
    c = _c;
    cnt++;
  }

  cout << (a % 2 == 0 && b % 2 == 0 && c % 2 == 0 ? -1 : cnt) << endl;
}