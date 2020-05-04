#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/abc116_b.txt"); \
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

  int s;
  cin >> s;

  bool ok = false;
  vector<int> c(0);
  c.push_back(s);

  auto f = [&](int n) -> int {
    if(n % 2 == 0) {
      return n / 2;
    } else {
      return 3 * n + 1;
    }
  };

  int i = 0;
  while (!ok) {
    int next = f(c[i++]);
    for (auto a : c) {
      if (a == next) ok = true;
    }
    if (!ok) c.push_back(next);
    else
      break;
  }

  cout << c.size() + 1 << endl;
}