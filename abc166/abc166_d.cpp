#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc166/abc166_d.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v)                        \
  rep(l, v.size()) { cout << v[l] << " "; } \
  cout << endl;
#else
#define INPUT_FILE
#define print_vec(v)
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
typedef pair<ll, ll> pl;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int X;
  cin >> X;

  // rep(i, 100) { cout << pow(i, 5) << endl; }
  ll a = 0;
  ll b = 0;
  bool ok = false;
  repi(i, -1000, 1001) {
    a = i;
    ll ai = pow(i, 5);
    repi(j, -1000, 1001) {
      b = j;
      ll bi = pow(j, 5);
      if ((ai - bi) == X) {
        ok = true;
        break;
      }
    }
    if (ok) break;
  }

  cout << a << " " << b << endl;
}