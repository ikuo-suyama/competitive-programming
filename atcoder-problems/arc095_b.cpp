#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/arc095_b.txt"); \
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

  int N;
  cin >> N;

  vector<ll> c(N);
  rep(i, N) { cin >> c[i]; }
  sort(c.begin(), c.end(), greater<int>());

  ll n = c[0];
  ll r = n / 2;
  auto comp = [&](ll x) -> bool { return x > r; };
  auto it = partition_point(c.begin(), c.end(), comp);
  // printf("%lld\n", *it);
  if (r != *it) {
    ll tmp = *it;
    ll tmp2 = *it;
    int j = it - c.begin() - 1;
    if (j > 0) {
      tmp2 = c[j];
    }
    r = abs(r - tmp) < abs(r - (n - tmp2)) ? tmp : tmp2;
  }
  printf("%lld %lld", n, r);
}