#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("m_solutions2020/m_solutions2020_a.txt"); \
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

  int N;
  cin >> N;

  ll ans = 0;
  if (N >= 1800) {
    ans = 1;
  } else if (N >= 1600) {
    ans = 2;
  } else if (N >= 1400) {
    ans = 3;
  } else if (N >= 1200) {
    ans = 4;
  } else if (N >= 1000) {
    ans = 5;
  } else if (N >= 800) {
    ans = 6;
  } else if (N >= 600) {
    ans = 7;
  } else if (N >= 400) {
    ans = 8;
  }

  cout << ans << endl;
}