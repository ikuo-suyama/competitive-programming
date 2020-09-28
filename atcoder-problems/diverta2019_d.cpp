#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                   \
  ifstream in("atcoder-problems/diverta2019_d.txt"); \
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

  ll N;
  cin >> N;

  // ll tmp = 0;
  // repi(j, 1, N + 1) {
  //   if (N / j == N % j) {
  //     printf("  %d,", j);
  //     tmp+=j;
  //   }
  // }
  // cout << tmp << endl << endl;

  ll ans = 0;
  ll i = 1;
  while ((N - i) / i > i) {
    if ((N - i) % i == 0) {
      // printf("  %lld,", (N - i) / i);
      ans += (N - i) / i;
    }
    i++;
  }
  cout << ans << endl;
}