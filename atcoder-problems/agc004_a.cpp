#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/agc004_a.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v) \
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
const ll LINF = 1e18+100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  ll A, B, C;
  cin >> A >> B >> C;
  
  if (A % 2 == 0 || B % 2 == 0 || C % 2 == 0) {
    cout << 0 << endl;
    return 0;
  } else {
    ll a = (A / 2 + 1) * B * C - (A / 2) * B * C;
    ll b = (B / 2 + 1) * A * C - (B / 2) * A * C;
    ll c = (C / 2 + 1) * A * B - (C / 2) * A * B;
    cout << min(a, min(b, c)) << endl;
  }
}