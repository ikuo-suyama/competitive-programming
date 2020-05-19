#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/yahoo_procon2019_qual_c.txt"); \
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

  ll K, A, B;
  cin >> K >> A >> B;

  if (K < A || B <= A + 2) {
    cout << K + 1 << endl;
    return 0;
  }

  // ll k = K;
  // ll y = 0;
  // ll c = 1;
  // while (k > 0) {
  //   if (c >= A && k >= 2) {
  //     c -= A;
  //     y++;
  //   } else if (y > 0) {
  //     y--;
  //     c += B;
  //   } else {
  //     c++;
  //   }
  //   k--;
  //   printf("k:%d y:%d c:%d\n", k, y, c);
  // }
  ll k = K - (A - 1);
  k--;
  ll cookie = B;
  k--;

  ll res = k / (A + 2);
  cookie += res * B;
  cookie += k % (A + 2);

  cout << cookie << endl;
}